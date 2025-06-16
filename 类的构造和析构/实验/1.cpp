#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

class Point{
	private:
		double x,y;
	public:
	Point();
	Point(double x_value,double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point p); 
};

Point::Point(double x_value,double y_value){
	x=x_value;
	y=y_value;
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

double Point::distanceToAnotherPoint(Point p){
	return pow((x-p.getX())*(x-p.getX())+(y-p.getY())*(y-p.getY()),0.5);
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		double x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		Point p1(x1,y1);
		Point p2(x2,y2);
		cout<<fixed<<setprecision(2)<<"Distance of Point("<<p1.getX()<<","<<p1.getY()<<") to Point("<<p2.getX()<<","<<p2.getY()<<") is "<<p1.distanceToAnotherPoint(p2)<<endl; 
		
	}
	return 0;
} 
