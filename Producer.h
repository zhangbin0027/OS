#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "Thread.h"

namespace wd
{

class Buffer;

class Producer : public Thread
{
public:
	Producer(Buffer &);
	virtual void run();

private:
	Buffer & _buf;
};

}//end of namespace wd


#endif
