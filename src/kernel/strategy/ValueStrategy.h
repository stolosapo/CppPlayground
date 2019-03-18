#ifndef ValueStrategy_h__
#define ValueStrategy_h__

#include <map>

using namespace std;

template<typename K, typename V>
class ValueStrategy
{
private:
        map<K, V> strategies;

public:
        ValueStrategy();
        virtual ~ValueStrategy();

        bool keyExists(K key);
	virtual void registerStrategy(K key, V value);
        virtual V get(K key);

};













template<typename K, typename V>
ValueStrategy<K, V>::ValueStrategy()
{

}

template<typename K, typename V>
ValueStrategy<K, V>::~ValueStrategy()
{
        strategies.clear();
}

template<typename K, typename V>
bool ValueStrategy<K, V>::keyExists(K key)
{
	typename map<K, V>::iterator it;
	it = strategies.find(key);

	return it != strategies.end();
}

template<typename K, typename V>
void ValueStrategy<K, V>::registerStrategy(K key, V value)
{
        strategies[key] = value;
}

template<typename K, typename V>
V ValueStrategy<K, V>::get(K key)
{
	if (!keyExists(key))
	{
		return NULL;
	}

	return strategies.find(key)->second;
}

#endif // ValueStrategy_h__
