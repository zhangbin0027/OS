#include "Buffer.h"
#include <iostream>
using std::cout;
using std::endl;


namespace wd
{

Buffer::Buffer(size_t size)
: _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _size(size)
{
	
}


bool Buffer::empty()
{
	return _que.size() == 0;
}

bool Buffer::full()
{
	return _que.size() == _size;
}

//push方法运行在生产者线程
void Buffer::push(int number)
{
	_mutex.lock();	
	while(full())
		_notFull.wait();//等待条件变量; 使用while可以避免条件变量被异常唤醒

	_que.push(number);
	_notEmpty.notify();
	
	_mutex.unlock();
}

//pop方法运行在消费者线程
int Buffer::pop()
{
	_mutex.lock();
	while(empty())
		_notEmpty.wait();

	int ret = _que.front();
	_que.pop();
	
	_notFull.notify();
	_mutex.unlock();
	return ret;
}


}//end of namespace wd
