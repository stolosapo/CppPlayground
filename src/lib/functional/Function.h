#ifndef Function_h__
#define Function_h__


template<typename T, typename R>
class Function
{
public:
	Function() {};
	virtual ~Function() {};

	typedef R (*func)(T);
	typedef R (*func_param_pointer)(T*);
	typedef R* (*func_return_pointers)(T);
	typedef R* (*func_all_pointers)(T*);

};

#endif // Function_h__