#include "Statistics.h"

#include "../../converter/Convert.h"

Statistics::Statistics()
{

}

Statistics::~Statistics()
{
	clear();
}

bool Statistics::exists(string data)
{
	map<string, int>::iterator it;
	it = stats.find(data);

	return it != stats.end();
}

void Statistics::clear()
{
	stats.clear();
}

void Statistics::add(string data)
{
	int counter = 0;

	if (exists(data))
	{
		counter = stats[data];
	}

	counter++;

	stats[data] = counter;
}

string Statistics::getPercentagesAsString(int totalCount)
{
	string res = "";

	for (map<string, int>::iterator it = stats.begin();
		it != stats.end();
		++it)
	{
		res += it->first;
		res += ": ";

		int cnt = it->second;
		double perc = (100 * cnt) / ((double) totalCount);

		res += Convert<double>::NumberToString(perc);
		res += "% (";
		res += Convert<int>::NumberToString(cnt);
		res += ")\n";
	}

	return res;
}
