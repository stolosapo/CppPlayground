#ifndef PropertyCollectionPointerValue_h__
#define PropertyCollectionPointerValue_h__

#include <vector>

using namespace std;

template <typename T>
class PropertyCollectionPointerValue
{
private:
    vector<T*> value;

public:
    PropertyCollectionPointerValue();
    virtual ~PropertyCollectionPointerValue();

    virtual vector<T*> getValue();
    virtual void setValue(vector<T*> value);

};



template <typename T>
PropertyCollectionPointerValue<T>::PropertyCollectionPointerValue()
{

}

template <typename T>
PropertyCollectionPointerValue<T>::~PropertyCollectionPointerValue()
{
    for (vector<T*>::iterator it = value.begin(); it != value.end(); ++it)
    {
        T* v = *it;

        if (v != NULL)
        {
            delete v;
        }
    }

    value.clear();
}

template <typename T>
vector<T*> PropertyCollectionPointerValue<T>::getValue()
{
    return value;
}

template <typename T>
void PropertyCollectionPointerValue<T>::setValue(vector<T*> value)
{
    this->value = value;
}

#endif // PropertyCollectionPointerValue_h__
