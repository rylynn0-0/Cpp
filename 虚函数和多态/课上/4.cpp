#include<iostream>
using namespace std;
#define PI 3.14
class Shape{
	public:
	Shape(){}
	
	virtual double getArea()=0;
	virtual void display()=0;
};

class Circle:public Shape{
	double r;
	public:
		Circle(double r):r(r){}
		double getArea(){
			return PI*r*r;
		}
		void display(){
			cout<<"Area of the Circle is: "<<getArea()<<endl;
		}
		
};

class Rentangle:public Shape{
	double x,y;
	public:
		Rentangle(double x,double y):x(x),y(y){}
		double getArea(){
			return x*y;
		}
		void display(){
			cout<<"Arear of the Rectangle is: "<<getArea()<<endl;
		}
};

int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		char x;
		cin>>x;
		if(x=='C'){
			double r;
			cin>>r;
			Shape* s=new Circle(r);
			s->display();
		}
		else{
			double a,b;
			cin>>a>>b;
			Shape* s=new Rentangle(a,b);
			s->display();
		}
	}
	return 0;
	
}
