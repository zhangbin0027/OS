#include<iostream>
using std::cout;
using std::endl;

class Base
{
public:
#if 1
	Base()
	{
		cout<<"Base()"<<endl;
	}
#endif

	//当基类提供有参构造函数时，系统就不会再提供默认构造函数
	Base(int i)
	{
		cout<<"Base(int)"<<endl;
	}
};

class Derived
: public Base
{
public:
	//当基类有显示定义构造函数时，派生类没有显示定义，则创建派生类对象时，一定会调用基类的默认构造函数所以必须给基类显示提供一个默认构造函数
};

int main(void)
{
	Derived d1;

	return 0;
}
