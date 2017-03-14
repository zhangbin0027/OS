#include "Consumer.h"
#include "Buffer.h"

#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;


namespace wd
{

Consumer::Consumer(Buffer & buf)
: _buf(buf)
{}

void Consumer::run()
{
	while(1)
	{
		int number = _buf.pop();
		cout << "----consume a number: " << number << endl;
		sleep(1);
	}
}

}//end of namespace wd
