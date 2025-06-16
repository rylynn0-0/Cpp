#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

class Point{
	private:
		double x,y;
	public:
	Point();
	//Point(double x_value,double y_value);
	~Point();
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point &p); 
};

Point::Point(){
	
	cout<<"Constructor."<<endl;
} 

Point::~Point(){
	cout<<"Distructor."<<endl;
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

double Point::distanceToAnotherPoint(Point &p){
	return pow((x-p.getX())*(x-p.getX())+(y-p.getY())*(y-p.getY()),0.5);
}
int main(){
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		int n;
		cin>>n;
		Point p[n];
		for(int i=0;i<n;i++){
		double x,y;
		cin>>x>>y;
		p[i].setX(x);
		p[i].setY(y); 
	}
	double m=0; 
	int f,g;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(p[i].distanceToAnotherPoint(p[j])>m){
				m=p[i].distanceToAnotherPoint(p[j]);
				f=i;
				g=j;
			}
		}
	}
		cout<<fixed<<setprecision(2)<<"The longest distance is "<<m<<",between p["<<f<<"] and p["<<g<<"]."<<endl;
	}
	return 0;
} 
