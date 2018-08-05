#ifndef PropertyPointerValue_h__
#define PropertyPointerValue_h__


template <typename T>
class PropertyPointerValue
{
private:
    T* value;

public:
    PropertyPointerValue();
    virtual ~PropertyPointerValue();

    virtual T* getValue();
    virtual void setValue(T* value);

};



template <typename T>
PropertyPointerValue<T>::PropertyPointerValue()
{

}

template <typename T>
PropertyPointerValue<T>::~PropertyPointerValue()
{
    if (value != NULL)
    {
        delete value;
    }
}

template <typename T>
T* PropertyPointerValue<T>::getValue()
{
    return value;
}

template <typename T>
void PropertyPointerValue<T>::setValue(T* value)
{
    this->value = value;
}

#endif // PropertyPointerValue_h__
