#include<iostream>
#include<cmath>
using namespace std;

class Clock{
	int h,m,s;
	public:
		Clock(int h,int m,int s):h(h),m(m),s(s){}
		
		Clock operator++(){
			s++;
			if(s>=60){
				s-=60;
				m++;
			}
			if(m>=60){
				m-=60;
				h++;
			}if(h>=12){
				h-=12;
			}
			
			return *this;
		} 
		
		
		Clock operator--(int){
			Clock temp(*this);
			s--;
			if(s<0){
				s+=60;
				m--;
			}
			if(m<0){m+=60;
			 h--;
			}
			if(h<0){
				h+=12;
			}
			return temp;
		} 
		
		void display(){
			cout<<h<<":"<<m<<":"<<s<<endl;
		}
};


int main(){
	int h,m,s;
	cin>>h>>m>>s;
	Clock c(h,m,s);
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x>0){
			for(int j=0;j<x;j++){++c;}
		}else{
			x=0-x;
			for(int j=0;j<x;j++){c--;}
		}
		c.display();
	}
	
	return 0;
}
