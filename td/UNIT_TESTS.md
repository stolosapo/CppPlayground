#  Unit Tests

## kernel

#### `arguments`
- ~~`ArgParser.cpp`~~
- `ArgumentAdapter.cpp`
- `ArgumentList.cpp`
- `ArgumentService.cpp`
- `ArgumentServiceFactory.cpp`

#### `audio`
- `playlist/SimplePlaylistStrategy.cpp`
- `playlist/RandomOncePlaylistStrategy.cpp`
- `playlist/PlaylistItem.cpp`
- `playlist/PlaylistAsyncMessage.cpp`
- `playlist/PlaylistHistory.cpp`
- `playlist/RandomPlaylistStrategy.cpp`
- `playlist/PlaylistHandlerFactory.cpp`
- `playlist/PlaylistItemModel.cpp`
- `playlist/PlaylistMetadata.cpp`
- `playlist/PlaylistStatistics.cpp`
- `playlist/Playlist.cpp`
- `playlist/Statistics.cpp`
- `playlist/PlaylistHandler.cpp`
- `playlist/PlaylistStrategy.cpp`
- `SimpleAudioTag/SimpleAudioTagService.cpp`
- `Alsa/AlsaCapture.cpp`
- `Alsa/exception/AlsaDomainErrorCode.cpp`
- `AudioTagModel.cpp`
- `TagLib/TagLibAudioTagService.cpp`
- `AudioTag.cpp`
- `AudioTagServiceFactory.cpp`
- `AudioBitrateConverter.cpp`
- `encoding/lame/LameAudioEncodingService.cpp`
- `encoding/liblame/LibLame.cpp`
- `encoding/exception/EncodingDomainErrorCode.cpp`
- `encoding/simple/SimpleAudioEncodingService.cpp`
- `encoding/AudioEncodingServiceFactory.cpp`

#### `circuit_breaker`
- `CircuitBreaker.cpp`
- `CircuitBreakerClosedState.cpp`
- `CircuitBreakerOpenState.cpp`
- `CircuitBreakerHealthPolicy.cpp`
- `CircuitBreakerHalfOpenState.cpp`

#### `data_model`
- `Property.cpp`
- `DoubleProperty.cpp`
- `CollectionIntProperty.cpp`
- `PropertyFactory.cpp`
- `ObjectProperty.cpp`
- `IntProperty.cpp`
- `BoolProperty.cpp`
- `StringProperty.cpp`
- `LongProperty.cpp`

#### `data_structure`
- `SynchronizedPQueue.h`
- `Queue.h`
- `SynchronizedQueue.h`

#### `di`
- `GlobalAppContext.cpp`
- `GlobalAppContextRegistration.cpp`
- `AppContext.cpp`

#### `encrypt`
- `Base64.cpp`

#### `exception`
- `runtime/RuntimeException.cpp`
- `domain/DomainException.cpp`
- `ExceptionMapper.cpp`

#### `functional`
- ~~`Supplier.h`~~
- ~~`Predicate.h`~~
- ~~`Consumer.h`~~
- ~~`Function.h`~~

#### `interruption`
- `SignalServiceFactory.cpp`
- `SignalHandler.cpp`
- `Interruptable.cpp`
- `signals/Signal_SIGINT.cpp`
- `signals/Signal.cpp`
- `SignalService.cpp`

#### `log`
- `LogServiceFactory.cpp`
- `LogAppender.cpp`
- `LogConsoleService.cpp`

#### `math`
- ~~`PrimeFactor.cpp`~~

#### `menu`
- `MenuItem.cpp`
- `MenuContainer.cpp`

#### `observer`
- ~~`Event.cpp`~~

#### `serialization`
- `json/JzonService.cpp`
- `json/serializer/LongJzonSerializer.cpp`
- `json/serializer/CollectionIntJzonSerializer.cpp`
- `json/serializer/DoubleJzonSerializer.cpp`
- `json/serializer/JzonSerializer.cpp`
- `json/serializer/BoolJzonSerializer.cpp`
- `json/serializer/StringJzonSerializer.cpp`
- `json/serializer/IntJzonSerializer.cpp`
- `json/serializer/ObjectJzonSerializer.cpp`
- `SerializationServiceFactory.cpp`

#### `task`
- `AsyncTask.cpp`
- `TaskRunner.cpp`
- `TaskContext.cpp`
- `ThreadPool.cpp`
- `Thread.cpp`

#### `tcp`
- `protocol/ITcpProtocol.cpp`
- `ClientInfo.cpp`
- `client/TcpClientFactory.cpp`
- `client/TcpClient.cpp`
- `config/TcpServerConfig.cpp`
- `config/TcpClientConfig.cpp`
- `server/TestStatefullTcpServer.cpp`
- `server/TcpServerFactory.cpp`
- `server/TcpServer.cpp`
- `server/TestState.cpp`
- `exception/TcpProtocolErrorCode.cpp`
- `exception/TcpServerErrorCode.cpp`
- `exception/TcpClientErrorCode.cpp`
- `lib/TcpAcceptor.cpp`
- `lib/TcpStream.cpp`
- `lib/TcpProtocol.cpp`
- `lib/TcpConnector.cpp`

#### `time`
- `TimeServiceFactory.cpp`
- `TimeService.cpp`

#### `utils`
- `StringHelper.cpp`
- `FigletHeader.cpp`
- ~~`FileHelper.cpp`~~

#### `version`
- `Version.cpp`
