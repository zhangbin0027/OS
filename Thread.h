#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__
#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class Thread
: private Noncopyable// 实现继承
//: public Noncopyable//接口继承
{
public:
	Thread();
	virtual ~Thread();

	virtual void run()=0;

	void start();
	void join();

	static void * threadFunc(void * arg);

private:
	pthread_t _pthId;
	bool _isRunning;
};

}//end of namespace wd
#endif
