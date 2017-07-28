#ifndef Interruptable_h__
#define Interruptable_h__


class Interruptable
{
private:
        bool ctrl_c_pressed;

        void handler(int sig);
        
protected:
        bool ctrlC_Interruption();

        void setup();
        void reset();

public:
	Interruptable();
	virtual ~Interruptable();

};

#endif // Interruptable_h__
