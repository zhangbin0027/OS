#include "Thread.h"

#include <iostream>
using std::cout;
using std::endl;


namespace wd
{

Thread::Thread()
: _pthId(0)
, _isRunning(false)
{}


void Thread::start()
{
	pthread_create(&_pthId, NULL, threadFunc, this);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning)
	{
		pthread_join(_pthId, NULL);
		_isRunning = false;
	}
}

void * Thread::threadFunc(void * arg)
{
	Thread * p = static_cast<Thread*>(arg);
	if(p)
		p->run();	
	return NULL;
}

Thread::~Thread()
{
	if(_isRunning)
	{
		pthread_detach(_pthId);
	}
}

}//end of namespace wd

