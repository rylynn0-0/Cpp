#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//class Geometry{
//	public:
//		virtual double getArea()=0; //计算面积，结果保留小数点后两位
//};
//
//class Rect:public Geometry{
//	double x,y;
//	public:
//		Rect(double x,double y):x(x),y(y){}
//		
//		virtual double getArea(){
//			return x*y;
//		}
//		
//};

//class Circle:public Geometry{
//	double r;
//	public:
//		Circle(double r):r(r){}
//		
//		virtual double getArea(){
//			return r*r*3.14;
//		}
//		
//};

//class TotalArea{
//		
//	public:
//		static void computerMaxArea(Geometry** t,int n){
//			double Max_area=0;
//			for(int i=0;i<n;i++){
//				if(t[i]->getArea() >Max_area)
//				Max_area=t[i]->getArea();
//			}
//			cout<<"最大面积="<<fixed<<setprecision(2)<<Max_area<<endl;
//		}
//
//};
int main(){
	return 0;
}

//int main(){
//	int n;
//	std::cin>>n;
//	Geometry**t=new Geometry*[n];
//		int f;
//		double x,y,r;
//			int idex=0;
//			for(int i=0;i<n;i++){
//				cin>>f;
//				if(f==1){
//					cin>>x>>y;
//					t[idex]=new Rect(x,y);
//					idex++;
//				}else{ 
//					cin>>r;
//					t[idex]=new Circle(r);
//					idex++;
//				}
//			}
	//TotalArea::computerMaxArea(t,n);
//	return 0;
//}
