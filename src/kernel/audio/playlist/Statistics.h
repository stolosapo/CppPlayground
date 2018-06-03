#ifndef Statistics_h__
#define Statistics_h__

#include <string>
#include <map>

using namespace std;

class Statistics
{
private:
	map<string, int> stats;

	bool exists(string data);

public:
	Statistics();
	virtual ~Statistics();

	void clear();

	void add(string data);

	string getPercentagesAsString(int totalCount);

};

#endif // Statistics_h__
