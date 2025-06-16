#include<iostream>
#include<iomanip>
using namespace std;

class Date{
	protected:
		int year;
		int month;
		int day;
	public:
		Date(int y,int m,int d):year(y),month(m),day(d){}
		void display(){
			cout<<year<<"/"<<setw(2)<<setfill('0')<<month<<"/"<<setw(2)<<day;
		}
};

class Time{
	protected:
		int hour;
		int minute;
		int second;
	public:
		Time(int h,int m,int s):hour(h),minute(m),second(s){}	
		void display(){
		
		cout<<setw(2)<<hour<<":"<<setw(2)<<minute<<":"<<setw(2)<<second;
	}
};

class Schedule:public Date,public Time{
	int ID;
	public:
		Schedule(int id,int y,int m,int d,int h,int mn,int s):Date(y,m,d),Time(h,mn,s),ID(id){}
		
		friend bool before(const Schedule & s1,const Schedule & s2);
		
		void display(){
			cout<<"The urgent schedule is No."<<ID<<": ";
			Date::display();
			cout<<" ";
			Time::display();
			cout<<endl;
		}
}; 

bool before(const Schedule & s1,const Schedule & s2){
	if(s1.year!=s2.year)return s1.year<s2.year;
	else if(s1.month!=s2.month)return s1.month<s2.month;
	else if(s1.day!=s2.day)return s1.day<s2.day;
	else if(s1.hour!=s2.hour)return s1.hour<s2.hour;
	else if(s1.minute!=s2.minute)return s1.minute<s2.minute;
	else return s1.second<s2.second;
}

int main(){
	int id;
	int y,m,d,h,mn,s;
	cin>>id;
	cin>>y>>m>>d>>h>>mn>>s;
	Schedule zao(id,y,m,d,h,mn,s);
	cin>>id;
	while(id!=0){
		cin>>y>>m>>d>>h>>mn>>s;
		Schedule S(id,y,m,d,h,mn,s);
		if(before(S,zao)){
			zao=S;
		}
		cin>>id;
	}
	
	zao.display();
	return 0;
}
