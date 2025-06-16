#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class CTriangle{
	public:
		CTriangle()=default;
		CTriangle(double a,double b,double c){
			this->a=a;
			this->b=b;
			this->c=c;
			if(!is_triangle())type="no triangle";
			else if(is_equilateral())type="equilateral triangle";
			else if(is_isosceles()&&is_right())type="isosceles right triangle";
			else if(is_isosceles())type="isosceles triangle";
			else if(is_right())type="right triangle";
			else type="general triangle";
		}
		~CTriangle(){
			a=0;
			b=0;
			c=0;
			type="none";
		} 
		
		double get_s(){
			if(is_triangle()){
				double p=get_p();	
				return pow(p*(p-a)*(p-b)*(p-c),0.5);
			}
		}
		
		string get_type(){
			return type;
		}
		
		bool is_triangle(){
		if(a+b>c&&b+c>a&&c+a>b)return true;
		else return false;
	}
		
	private:
		double a;
		double b;
		double c;
		string type;
		
	bool is_isosceles(){
		if(a==b||b==c||a==c)return true;
		else return false;
	}
	
	bool is_right(){
		if(pow(a,2)-pow(b,2)-pow(c,2)<0.001)return true;
		else if(pow(b,2)-pow(a,2)-pow(c,2)<0.001)return true;
		else if(pow(c,2)-pow(b,2)-pow(a,2)<0.001)return true;
		else return false;
	}
	
	bool is_equilateral(){
		if(a==b&&b==c)return true;
		else return false;
	}
	
	
	
	double get_p() {
	return (a+b+c)/2;}
};

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		double a,b,c;
		cin>>a>>b>>c;
		CTriangle tri(a,b,c);
		if(tri.is_triangle()){
			cout<<tri.get_type()<<", "<<fixed<<setprecision(1)<<tri.get_s()<<endl;
		}
		else cout<<"no triangle"<<endl;
	}
	
	return 0;
}
