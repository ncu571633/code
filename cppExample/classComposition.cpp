#include <iostream.h>
#include <math.h>
class Point	//Point类定义
{
public:
	Point(int xx=0, int yy=0) {X=xx;Y=yy;}
	Point(Point &p);
	int GetX() {return X;}
	int GetY() {return Y;}
private:
	int X,Y;
};
Point::Point(Point &p)	//拷贝构造函数的实现
{
	X=p.X;
	Y=p.Y;
	cout<<"Point拷贝构造函数被调用"<<endl;
}
//类的聚集
class Distance	//Distance类的定义
{
public:	//外部接口
	Distance(Point xp1, Point xp2);
	double GetDis(){return dist;}
private:	//私有数据成员
	Point p1,p2;	//Point类的对象p1,p2
	double dist;	
};
//类的聚集的构造函数
Distance::Distance(Point xp1, Point xp2)
:p1(xp1),p2(xp2)
{
	cout<<"Distance构造函数被调用"<<endl;
	double x=double(p1.GetX()-p2.GetX());
	double y=double(p1.GetY()-p2.GetY());
	dist=sqrt(x*x+y*y);
}
//主函数
void main()
{
	Point myp1(1,1),myp2(4,5);	//定义Point类的对象
	Distance myd(myp1,myp2);	//定义Distance类的对象
	cout<<"The distance is:";
	cout<<myd.GetDis()<<endl;
}
