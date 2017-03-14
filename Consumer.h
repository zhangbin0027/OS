#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "Thread.h"

namespace wd
{
class Buffer;
class Consumer : public Thread
{
public:
	Consumer(Buffer & buf);

	virtual void run();

private:
	Buffer & _buf;
};

}//end of namespace wd

#endif
