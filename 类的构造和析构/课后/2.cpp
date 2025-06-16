#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Equation{
	public:
	Equation(){
		a=1;
		b=1;
		c=0;
	}
	
	void set(double a,double b,double c){
		this->a=a;
		this->b=b;
		this->c=c;
		
	}
	
	void get_root(){
		double delta=b*b-4*a*c;
		double x=-b/(2*a);
		if(delta==0){
			
			cout<<fixed<<setprecision(2)<<"x1=x2="<<x<<endl;
		}
		else if(delta>0){
			double y=pow(delta,0.5)/(2*a);
			cout<<fixed<<setprecision(2)<<"x1="<<x+y<<" x2="<<x-y<<endl;
		}
		else if(delta<0){
			double y=pow(0-delta,0.5)/(2*a);
			cout<<fixed<<setprecision(2)<<"x1="<<x<<"+"<<y<<"i x2="<<x<<"-"<<y<<"i"<<endl;
		}
	}
	
	private:
		double a;
		double b;
		double c;
};

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		double a,b,c;
		cin>>a>>b>>c;
		Equation e;
		e.set(a,b,c);
		e.get_root();
	}
	
	return 0;
}
