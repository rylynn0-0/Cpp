#include<iostream>
using namespace std;

class Fraction{
	int numerator,denominator;
	int common_divisor;
	void contracted();
	public:
		Fraction(int n=0,int d=1):numerator(n),denominator(d){}
		Fraction operator+(Fraction f){
			Fraction ans;
			int x=numerator*f.denominator +denominator*f.numerator;
			int y=f.denominator*denominator;
			
			if(y<0){
				y=0-y;
				x=0-x;
			}
			ans.set(x,y);
			return ans;
		}
		
		Fraction operator-(Fraction f){
			Fraction ans;
			int x=numerator*f.denominator -denominator*f.numerator;
			int y=f.denominator*denominator;
			if(y<0){
				y=0-y;
				x=0-x;
			}
			ans.set(x ,y);
			return ans;
		}
		Fraction operator*(Fraction f){
			Fraction ans;
			int x=numerator*f.numerator;
			int y=f.denominator*denominator;
			if(y<0){
				y=0-y;
				x=0-x;
			}
			ans.set(x ,y);
			return ans;
		}
		Fraction operator/(Fraction f){
			Fraction ans;
			int x=numerator*f.denominator ;
			int y=f.numerator*denominator;
			if(y<0){
				y=0-y;
				x=0-x;
			}
			ans.set(x ,y);
			return ans;
		}
		void set(int n=0,int d=1){
			numerator=n;
			denominator=d;
		}
		void disp(){
			cout<<"fraction="<<numerator<<"/"<<denominator<<endl;
		}
		
};

int main(){
	int a,b;
	cin>>a>>b;
	Fraction x(a,b);
	cin>>a>>b;
	Fraction y(a,b);
	Fraction z=x+y;
	z.disp();
	z=x-y;
	z.disp() ;
	z=x*y;
	z.disp() ;
	z=x/y;
	z.disp() ;
	
	
	
	return 0;
}
