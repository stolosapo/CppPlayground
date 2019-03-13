#ifndef Supplier_h__
#define Supplier_h__


template<typename T>
class Supplier
{
public:
	Supplier() {};
	virtual ~Supplier() {};

	typedef T (*func)();
	typedef T* (*func_pointer)();

};

#endif // Supplier_h__