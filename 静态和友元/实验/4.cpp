#include<iostream>
#include<iomanip>
using namespace std;
class CTime;
class CDate{
	public:
		CDate(int y,int m,int d):year(y),month(m),day(d){}
		friend void Display(CDate &cd, CTime &ct);
	private:
		int year;
		int month;
		int day;
		
};

class CTime{
	public:
		CTime(int h,int min,int s):hour(h),min(min),sec(s){}
		friend void Display(CDate &cd, CTime &ct);
	private:
		int hour;
		int min;
		int sec;
		
};


void Display(CDate &cd, CTime &ct){
	cout<<cd.year<<"-"<<setfill('0')<<setw(2)<<cd.month<<"-"<<setfill('0')<<setw(2)<<cd.day<<" ";
	cout<<setfill('0')<<setw(2)<<ct.hour<<":"<<setfill('0')<<setw(2)<<ct.min<<":"<<setfill('0')<<setw(2)<<ct.sec<<endl;
}

int main(){
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++){
		int y,m,d,h,min,s;
		cin>>y>>m>>d>>h>>min>>s;
		CDate cd(y,m,d);
		CTime ct(h,min,s);
		Display(cd,ct);
	}
	
	return 0;
}
