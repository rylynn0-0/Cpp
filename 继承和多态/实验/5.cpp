#include<iostream>
#include<iomanip>
using namespace std;

class Time{
	protected:
		int m;
		int h;
		int s;
		
	public:
		Time(int h,int m,int s):m(m),s(s),h(h){}
		void show(){
			cout<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s<<endl;
		}
};

class Time_12hours:public Time{
	string interval;
	public:
		Time_12hours(int h,int m,int s,int AMorPM):Time(h,m,s){
			if(AMorPM==121)interval="AM";
			else interval="PM";
		}
		void show(){
			cout<<interval<<" ";
			Time::show() ;
		}
		
		void add(){
			s++;
			if(s>=60){
				s=0;
				m++;
			}
			if(m>=60){
				m=0;
				h++;
			}
			if(h>=12){
				h=0;
				interval=(interval=="AM")?"PM":"AM";
			}
		}
		
		void sub(){
			s--;
			if(s<0){
				m--;
				s=59;
			}
			if(m<0){
				h--;
				m=59;
			}
			if(h<0){
				h=11;
				m=59;
				s=59;
				interval=(interval=="AM")?"PM":"AM";
			}
		}
};

int main(){
	int h;
	int m;
	int s;
	int n;
	char x;
	int flag;
	cin>>flag;
	while(flag!=0){
		cin>>h>>m>>s;
		Time_12hours time(h,m,s,flag);
		cin>>x>>n;
		for(int i=0;i<n;i++){
			if(x=='+')time.add();
			else time.sub();
		}
		time.show();
		cin>>flag;
	}
	return 0;
}
