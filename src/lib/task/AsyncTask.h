#ifndef AsyncTask_h__
#define AsyncTask_h__

#include <pthread.h>

class AsyncTask
{
private:
        pthread_t _thread;

        static void* internalThreadFunc(void* self);

protected:
        virtual void task() = 0;

public:
        AsyncTask();
        virtual ~AsyncTask();

        bool startAsync();
        void waitToExit();

};

#endif // AsyncTask_h__
