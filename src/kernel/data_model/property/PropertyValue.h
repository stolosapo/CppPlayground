#ifndef PropertyValue_h__
#define PropertyValue_h__


template <typename T>
class PropertyValue
{
private:
    T value;

public:
    PropertyValue();
    virtual ~PropertyValue();

    virtual T getValue();
    virtual void setValue(T value);

};



template <typename T>
PropertyValue<T>::PropertyValue()
{

}

template <typename T>
PropertyValue<T>::~PropertyValue()
{

}

template <typename T>
T PropertyValue<T>::getValue()
{
    return value;
}

template <typename T>
void PropertyValue<T>::setValue(T value)
{
    this->value = value;
}

#endif // PropertyValue_h__
