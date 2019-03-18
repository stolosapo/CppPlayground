#ifndef MapHelper_h__
#define MapHelper_h__

#include <iostream>
#include <map>

using namespace std;

template<class K, class V>
class MapHelper
{
public:
	MapHelper();
	virtual ~MapHelper();

	static bool containsKey(map<K, V> currentMap, K key);
	static bool containsValue(map<K, V> currentMap, V value);

};

#endif // MapHelper_h__