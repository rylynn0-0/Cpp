#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Point{
	public:
		friend double Distance(Point &a,Point &b);
		Point(double XX,double YY){
			x=XX;
			y=YY;
		};
	private:
		double x;
		double y;
		
		
};

double Distance(Point &a,Point &b){
	return pow(pow(a.x-b.x,2)+pow(a.y-b.y,2),0.5); 
} 

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		
		double x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2; 
		Point p1(x1,y1);
		Point p2(x2,y2);
		cout<<fixed<<setprecision(0)<<Distance(p1,p2)<<endl;
	}
	return 0;
}
