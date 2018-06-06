#ifndef Strategy_h__
#define Strategy_h__

#include <map>

using namespace std;

template<typename K, typename V>
class Strategy
{
private:
        map<K, V*> strategies;

public:
        Strategy();
        virtual ~Strategy();

        bool keyExists(K key);
	virtual void registerStrategy(K key, V* value);
        virtual V* get(K key);

};













template<typename K, typename V>
Strategy<K, V>::Strategy()
{

}

template<typename K, typename V>
Strategy<K, V>::~Strategy()
{
        /* Clear strategies */
        for (typename map<K, V*>::iterator it = strategies.begin();
                it != strategies.end();
                ++it)
        {
                delete it->second;
        }

        strategies.clear();
}

template<typename K, typename V>
bool Strategy<K, V>::keyExists(K key)
{
	typename map<K, V*>::iterator it;
	it = strategies.find(key);

	return it != strategies.end();
}

template<typename K, typename V>
void Strategy<K, V>::registerStrategy(K key, V* value)
{
        strategies[key] = value;
}

template<typename K, typename V>
V* Strategy<K, V>::get(K key)
{
	if (!keyExists(key))
	{
		return NULL;
	}

	return strategies.find(key)->second;
}

#endif // Strategy_h__
