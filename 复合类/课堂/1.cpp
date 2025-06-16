#include <iostream>
#include <cmath>
using namespace std;

class Point {
	double x, y;  //x和y坐标
public:
	Point();  //缺省构造函数，设x和y坐标为0
	Point(double x_value, double y_value); //有参构造
	double getX();	//返回x的值
	double getY();	//返回U的值
	void setXY(double x1, double y1);
	void setX(double x_ualue);
	void setY(double y_ualue);
	double getDisTo(Point &p);
};

class Circle {
	Point centre; //圆心
	double radius;	//半径
public:
	Circle();	//设置圆心位置为(0，0)，半径为1
	Circle(double x, double y, double r);	//有参构造，设置圆心和半径
	void moveCentreTo(double x1, double y1);	//圆心位置移动到(x1，y1)
	int contain(Point &p);	//判断圆与点p的关系，如果点p在y园内则返回1，否则返回0
};
//下面完成两个类的类定义和主函数
/********** Write your code here! **********/
Point::Point(){
	x=0;
	y=0;
}

Point::Point(double x_value, double y_value):x(x_value),y(y_value){}

double Point::getX(){return x;}

double Point::getY(){return y;}

void Point::setXY(double x1, double y1){
	x=x1;
	y=y1;
}

void Point::setX(double x_value){x=x_value;}

void Point::setY(double y_value){y=y_value;}

double Point::getDisTo(Point &p){
	double dis_x=x-p.getX();
	double dis_y=y-p.getY();
	double dis=pow(pow(dis_x,2)+pow(dis_y,2),0.5);
	return dis;
} 


Circle::Circle(){
	radius=1;
} 

Circle::Circle(double x,double y,double r):centre(x,y){
	radius=r;
} 

void Circle::moveCentreTo(double x1, double y1){
	centre.setX(x1);
	centre.setY(y1);
	
}

int Circle::contain(Point &p) {
	if(radius-centre.getDisTo(p) >=0.001||radius-centre.getDisTo(p)==0)return 1;
	return 0;
}

int main(){
	double x,y,r;
	cin>>x>>y>>r;
	Circle c(x,y,r);
	int n;
	cin>>n;
	Point p[n];
	for(int i=0;i<n;i++){
		double xp,yp;
		cin>>xp>>yp;
		p[i].setX(xp);
		p[i].setY(yp);
		if(c.contain(p[i])==1)cout<<"inside"<<endl;
		else cout<<"outside"<<endl;
		
	}
	cin>>x>>y;
	c.moveCentreTo(x,y);
	cout<<"after move the centre of circle:"<<endl;
	for(int i=0;i<n;i++){
		if(c.contain(p[i])==1)cout<<"inside"<<endl;
		else cout<<"outside"<<endl;
	} 
}
/*******************************************/
//--------------------
