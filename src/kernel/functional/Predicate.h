#ifndef Predicate_h__
#define Predicate_h__


template<typename T>
class Predicate
{
public:
	Predicate() {};
	virtual ~Predicate() {};

	typedef bool (*func)(T);
	typedef bool (*func_pointer)(T*);

};

#endif // Predicate_h__