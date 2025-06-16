#include<iostream>
using namespace std;

class 	CPoint{
	protected:
		double x,y;
		
	public:
		CPoint(double x,double y):x(x),y(y){}
		void Print(){
			cout<<"("<<x<<","<<y<<")";
		}
};

class CCircle:public CPoint{
	protected:
	double r;
	public:
		CCircle(double x,double y,double r):CPoint(x,y),r(r){}
		
		double getArea(){
			return 3.14*r*r;
		}
		
		void printArea(){
			cout<<"Area:"<<getArea()<<endl;
		}
		void Print(){
			cout<<"Circle:";
			CPoint::Print();
			cout<<","<<r<<endl;
		};
		
		
};

class CCylinder:public CCircle{
	private:
		double h;
	public:
		CCylinder(double x,double y,double r,double h):CCircle(x,y,r),h(h){}
		
		double getV(){
			return getArea()*h;
		} 
		
		void PrintV(){
			cout<<"Volume:"<<getV()<<endl; 
		}
		void Print(){
			cout<<"Cylinder:";
			CPoint::Print() ;
			cout<<","<<r<<","<<h<<endl;
		}
};

int main(){
	double x1,y1,r1,x2,y2,r2,h;
	cin>>x1>>y1>>r1;
	cin>>x2>>y2>>r2>>h;
	CCircle circle(x1,y1,r1);
	CCylinder cy(x2,y2,r2,h);
	circle.Print() ;
	circle.printArea();
	cy.Print();
	cy.PrintV() ;
	return 0;
}
