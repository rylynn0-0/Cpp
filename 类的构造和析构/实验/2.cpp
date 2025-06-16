#include<iostream>
#include<cmath>
using namespace std;

class Point{
	private:
		double x,y;
	public:
	Point()=default;
	Point(double x_value,double y_value);
	~Point();
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point &p); 
};

Point::Point(double x_value,double y_value){
	x=x_value;
	y=y_value;
} 

Point::~Point(){
	cout<<"point clear"<<endl;
	x=0;
	y=0;
	
}
double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}

void Point::setX(double x_value){
	x=x_value;
}

void Point::setY(double y_value){
	y=y_value;
}

double Point::distanceToAnotherPoint(Point& p){
	return pow((x-p.getX())*(x-p.getX())+(y-p.getY())*(y-p.getY()),0.5);
}

class Circle{
	
	public:
		Circle( Point& p,int r){
			x=p.getX();
			y=p.getY();
			this->r=r;
		}
		~Circle(){
			x=0;
			y=0;
			r=0;
			cout<<"circle clear"<<endl;
		}
		
		void contain(Point &p){
			double dis=pow((x-p.getX())*(x-p.getX())+(y-p.getY())*(y-p.getY()),0.5);
			if(dis<=r){
				cout<<"in"<<endl;
			}else cout<<"out"<<endl;
		}
		
	private:
		double x;
		double y;
		double r;
		
};

int main(){
	double x,y;
	cin>>x>>y;
	Point p1(x,y);
	int t;
	cin>>t;
	Point *p=new Point[t];
	for(int i=0;i<t;i++){
		double a,b;
		cin>>a>>b;
		p[i].setX(a);
		p[i].setY(b);
	}
	double cx,cy,r;
	cin>>cx>>cy>>r;
	Point *pc=new Point(cx,cy);
	Circle c(*pc,r);
	c.contain(p1);
	for(int i=0;i<t;i++){
		c.contain(p[i]);
	} 
	return 0;
}
