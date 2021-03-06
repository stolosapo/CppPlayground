#include "PlaylistHandler.h"

#include "../../exception/domain/DomainException.h"
#include "../../exception/ExceptionMapper.h"
#include "../../task/Barrier.h"
#include "../../task/Thread.h"
#include "../../converter/Convert.h"
#include "exception/PlaylistErrorCode.h"
#include "SimplePlaylistStrategy.h"
#include "RandomPlaylistStrategy.h"
#include "RandomOncePlaylistStrategy.h"
#include "PlaylistItemModel.h"
#include "PlaylistAsyncMessage.h"

PlaylistHandler::PlaylistHandler(
	ILogService* logSrv,
	ISerializationService* serializationSrv,
	Playlist* playlist,
	PlaylistHistory* history,
	PlaylistMetadata* metadata,
	PlaylistStatistics* stats,
	PlaylistStrategyType strategyType,
	bool repeat)
	: logSrv(logSrv),
	serializationSrv(serializationSrv),
	playlist(playlist),
	history(history),
	metadata(metadata),
	stats(stats),
	strategyType(strategyType),
	repeat(repeat)
{
	pattern = new Strategy<PlaylistStrategyType, PlaylistStrategy>;

	registerStrategies();

	strategy = pattern->get(strategyType);
}

PlaylistHandler::~PlaylistHandler()
{
	if (pattern != NULL)
	{
		delete pattern;
	}
}

PlaylistStrategy* PlaylistHandler::getStrategy()
{
	return strategy;
}

ILogService* PlaylistHandler::getLogService()
{
	return logSrv;
}

PlaylistItem PlaylistHandler::getCurrentTrack()
{
	return currentTrack;
}

PlaylistItem PlaylistHandler::getTrack(int trackIndex)
{
    if (strategy == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0006);
	}

	currentTrack = strategy->getTrack(trackIndex);

	return currentTrack;
}

int PlaylistHandler::getTrackIndex(string track)
{
    if (strategy == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0006);
	}

    return strategy->getTrackIndex(track);
}

string PlaylistHandler::getHistoryTrack(int historyIndex)
{
    return history->read(historyIndex);
}

ISerializationService* PlaylistHandler::getSerializationService()
{
	return serializationSrv;
}

void PlaylistHandler::registerStrategies()
{
	pattern->registerStrategy(SIMPLE, new SimplePlaylistStrategy(logSrv, playlist, history, metadata, repeat));
	pattern->registerStrategy(RANDOM, new RandomPlaylistStrategy(logSrv, playlist, history, metadata, repeat));
	pattern->registerStrategy(RANDOM_ONCE, new RandomOncePlaylistStrategy(logSrv, playlist, history, metadata, repeat));
}

void PlaylistHandler::load()
{
	if (playlist != NULL)
	{
		playlist->load();
	}

	if (history != NULL && playlist != NULL)
	{
		// history->loadAll();
		history->loadRestOfPlaylistCount(playlist->size());
	}

	if (strategy != NULL)
	{
		strategy->load();
	}
}

int PlaylistHandler::playlistSize()
{
	if (playlist == NULL)
	{
		return -1;
	}

	return playlist->size();
}

int PlaylistHandler::historySize()
{
    if (history == NULL)
	{
		return -1;
	}

	return history->size();
}

bool PlaylistHandler::hasNext()
{
	if (strategy == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0006);
	}

	return strategy->hasNext(currentTrack);
}

PlaylistItem PlaylistHandler::nextTrack()
{
	if (strategy == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0006);
	}

	currentTrack = strategy->nextTrack(currentTrack);

	return currentTrack;
}

void PlaylistHandler::archiveTrack(PlaylistItem track)
{
    history->add(track.getTrack());

	stats->add(track.getMetadata());
}

vector<string> PlaylistHandler::searchTracks(string query, int limit, int offset)
{
    return playlist->search(query, limit, offset);
}

string PlaylistHandler::getGenrePercentages()
{
	return stats->getGenrePercentages();
}

string PlaylistHandler::getArtistPercentages()
{
	return stats->getArtistPercentages();
}

void PlaylistHandler::exportPlaylistMetadata(const char* filename, int parralelismNumber)
{
	int size = playlistSize();

	int THREAD_CNT = parralelismNumber;

	if (parralelismNumber > size)
	{
		THREAD_CNT = size;
	}

	// Barrier _barrier(THREAD_CNT);

	// _barrier.init();

	Thread *threads[THREAD_CNT];
	PlaylistAsyncMessage *messages[THREAD_CNT];

	int prevTo = -1;

	for (int i = 0; i < THREAD_CNT; ++i)
	{
		int batchSize = size / THREAD_CNT;
		int rest = size % THREAD_CNT;
		int addition = rest == 0 ? 0 : i % rest;
		batchSize += addition;

		int from = prevTo + 1;
		int to = from + (batchSize - 1);
		prevTo = to;

		PlaylistAsyncMessage* message = new PlaylistAsyncMessage;
		message->setIndex(i);
		message->setFromPlaylistIndex(from);
		message->setToPlaylistIndex(to);
		message->setFilename(filename);
		message->setHandler(this);

		messages[i] = message;

		Thread *th = new Thread;
		threads[i] = th;
		th->attachDelegate(exportPlaylistMetadataAsync);
		th->start(message);
	}


	// for (int i = 0; i < THREAD_CNT; ++i)
	// {
	// 	cout << i << endl;
	// 	threads[i]->wait();
	// }


	// _barrier.wait();
	// _barrier.destroy();


	// for (int i = 0; i < THREAD_CNT; ++i)
	// {
	// 	delete threads[i];
	// 	delete messages[i];
	// }
}

void* exportPlaylistMetadataAsync(void* context)
{
	PlaylistAsyncMessage* message = (PlaylistAsyncMessage*) context;

	int index = message->getIndex();
	int from = message->getFromPlaylistIndex();
	int to = message->getToPlaylistIndex();
	const char* filename = message->getFilename();
	PlaylistHandler* handler = message->getHandler();
	PlaylistStrategy* strategy = handler->getStrategy();
	ILogService* logSrv = handler->getLogService();
	ISerializationService* serializationSrv = handler->getSerializationService();

	try
	{
		string curFilename = Convert<int>::NumberToString(index) + "_" + string(filename);

		int size = (to - from) + 1;


		Model *items[size];

		for (int i = 0; i < size; ++i)
		{
			int actualIndex = from + i;

			PlaylistItem item = strategy->getTrack(actualIndex);

			PlaylistItemModel *model = new PlaylistItemModel(item);

			items[i] = (Model*) model;
		}

		serializationSrv->saveModelsToFile(items, size, curFilename);

		for (int i = 0; i < size; ++i)
		{
			delete items[i];
		}
	}
	catch (DomainException& e)
	{
		logSrv->error(handle(e));
	}
	catch (RuntimeException& e)
	{
		logSrv->error(handle(e));
	}
	catch (exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}
