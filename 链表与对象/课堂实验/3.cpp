//头文件和日期类声明
#include<iostream>
#include<iomanip>
using namespace std;
 
class TDate {
private:
    int year,month,day;
public:
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
    void set(int y,int m,int d);
    void print();
    void addOneDay();
};

//----在以下区域完成部分成员函数的类外定义----
/********** Write your code here! **********/
void TDate::set(int y,int m,int d){
	year=y;
	month=m;
	day=d;
}

void TDate::print(){
	cout<<year<<setfill('0')<<setw(2)<<month<<setfill('0')<<setw(2)<<day;
}

void TDate::addOneDay() {
	day++;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day>31){
		day=1;
		month++;}
	}
	else if(month==4||month==6||month==9||month==11){
		if(day>30){
			day=1;
			month++;
		}
	}
	else{
		int y;
		if(year%100==0)y=year%100;
		else y=year;
		
		if(y%4==0){
			if(day>29){
			day=1;
			month++;
			}
		}
		else{
			if(day>28){
			day=1;
			month++;
			}
		}
	}
	
	if(month>12){month=1;
	year++;} 
}


/*******************************************/
//主函数如下
int main()
{   int t, y,m,d;
    cin>>t;
    while(t--)
    {	TDate d1;
		cin>>y>>m>>d;
		d1.set(y, m, d);
        cout<<"Today-";
        d1.print();
        d1.addOneDay();
        cout<<" Tomorrow-";
        d1.print();
		cout<<endl;
    }
    return 0;
}

