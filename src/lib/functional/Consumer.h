#ifndef Consumer_h__
#define Consumer_h__


template<typename T>
class Consumer
{
public:
	Consumer() {};
	virtual ~Consumer() {};

	typedef void (*func)(T);
	typedef void (*func_pointer)(T*);

};

#endif // Consumer_h__