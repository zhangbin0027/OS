#include<iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix=0,int iy=0)
	: _ix(ix)
	, _iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}
	~Point()
	{
		cout<<"~Pojnt()"<<endl;
	}
	void print()
	{
		cout<<"("<< _ix
			<<","<< _iy
			<<")"<<endl;
	}
	int getX() const
	{
		return _ix;
	}
	protected:
		int getY() const
		{
			return _iy;
		}
	private:
		int _ix;
		int _iy;
};

class Point3D
: private Point //private继承
{
public:
	Point3D(int ix,int iy,int iz)
	: Point(ix,iy)
	, _iz(iz)
	{
		cout<<"Point3D(int,int,int)"<<endl;
	}
	~Point3D()
	{
		cout<<"~Point3D()"<<endl;
	}
	void display()
	{
		cout<<"("<<getX() //基类的public/protect成员能在派生类中直接访问，表现为private
			<<","<<getY()
			<<","<<_iz
			<<")"<<endl;
	}
	
private:
	int _iz;
};

int main(void)
{
	Point3D p3D(1,2,3);
	Point pt(1,2);
	return 0; 
}
