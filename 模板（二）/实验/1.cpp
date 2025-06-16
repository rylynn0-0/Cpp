#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;




class Point{
	double x;
	double y;
	public:
		Point(double x=0,double y=0):x(x),y(y){}
		bool operator >(Point& p){
			return abs(x)+abs(y)>abs(p.x)+abs(p.y);
		}
		
		friend istream& operator>>(istream &i,Point& p){
			i>>p.x>>p.y;
			return i;
		}
		
		friend ostream& operator<<(ostream &o,const Point&p){
			o<<fixed<<setprecision(1)<<"("<<p.x<<", "<<p.y<<")";
			return o;
		}
};


template<class T>
class Data{
	T x[100];
	int n;
	public:
	Data(int n):n(n){
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
	}
	
	void mysort(){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(x[i]>x[j]){
					T temp =x[i];
					x[i]=x[j];
					x[j]=temp;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			cout<<x[i]<<" ";
		}cout<<endl;
}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		int n;
		cin>>c>>n;
		if(c=='I'){
			Data<int> d(n);
			d.mysort();
		}else if(c=='D'){
			Data<double> d(n);
			d.mysort();
		}else if(c=='S'){
			Data<string> d(n);
			d.mysort();
		}else if(c=='P'){
			Data<Point> d(n);
			d.mysort();
		}
	}
	return 0;
} 
