#ifndef PropertyCollectionValue_h__
#define PropertyCollectionValue_h__

#include <vector>

using namespace std;

template <typename T>
class PropertyCollectionValue
{
private:
    vector<T> value;

public:
    PropertyCollectionValue();
    virtual ~PropertyCollectionValue();

    virtual vector<T> getValue();
    virtual void setValue(vector<T> value);

};



template <typename T>
PropertyCollectionValue<T>::PropertyCollectionValue()
{

}

template <typename T>
PropertyCollectionValue<T>::~PropertyCollectionValue()
{
    value.clear();
}

template <typename T>
vector<T> PropertyCollectionValue<T>::getValue()
{
    return value;
}

template <typename T>
void PropertyCollectionValue<T>::setValue(vector<T> value)
{
    this->value = value;
}

#endif // PropertyCollectionValue_h__
