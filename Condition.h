#ifndef __WD_CONDTION_H__
#define __WD_CONDTION_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock;//前向声明

class Condition
: Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}//end of namespace wd


#endif
