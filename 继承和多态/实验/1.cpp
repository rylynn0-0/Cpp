#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//假设点坐标均为整数 
class Point {
protected:
	int x;
public:
	Point(int);
	void distance(); //计算当前点到原点的距离，并输出结果信息
};

class Point_2D: public Point {
protected:
	int y;
public:
	Point_2D(int, int); //有参构造，设置二维平面的x\y坐标
	void distance(); //计算当前点到原点的距离，并输出结果信息
};

class Point_3D: public Point_2D {
protected:
	int z;
public:
	Point_3D(int, int, int); //有参构造，设置三维平面的x\y\z坐标
	void distance();//计算当前点到原点的距离，并输出结果信息
	//三维点到原点距离，等于x\y\z坐标平方的总和的开方
};

//完成三个类实现的填空 
/********** Write your code here! **********/
Point::Point(int x):x(x){}
void Point::distance(){
	double dis=sqrt(pow(x,2));
	cout<<"Distance between ["<<x<<"] and [0] = "<<fixed<<setprecision(2)<<dis<<endl;
}

Point_2D::Point_2D(int x,int y):Point(x),y(y){}
void Point_2D::distance(){
	double dis=sqrt(pow(x,2)+pow(y,2));
	cout<<"Distance between ["<<x<<", "<<y<<"] and [0, 0] = "<<fixed<<setprecision(2)<<dis<<endl;
}

Point_3D::Point_3D(int x,int y,int z):Point_2D(x,y),z(z){}
void Point_3D::distance(){
	double dis=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	cout<<"Distance between ["<<x<<", "<<y<<", "<<z<<"] and [0, 0, 0] = "<<fixed<<setprecision(2)<<dis<<endl;
}

/*******************************************/
//主函数如下 
int main()
{	int num,tx, ty, tz;
	cin>>num;
	while (num)
	{	switch (num) {
		case 1: 
			{	cin>>tx;
				Point p1(tx);
				p1.distance();
				break;
			}
			case 2:
			{	cin>>tx>>ty;
				Point_2D p2(tx, ty);
				p2.distance();
				break;
			}
			case 3:
			{	cin>>tx>>ty>>tz;
				Point_3D p3(tx, ty, tz);
				p3.distance();
				break;
			}
		}
		cin>>num;
	}
	return 0;

}
