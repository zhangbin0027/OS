#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock
: Noncopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexLockPtr();

private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

}// end of namespace wd


#endif
