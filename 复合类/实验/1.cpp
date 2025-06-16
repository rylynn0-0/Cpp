//头文件区域
#include <iostream>
using namespace std;
//填空区域1：类CDate的定义
/********** Write your code here! **********/
class CDate{
	public:
		CDate(int a,int b,int c):year(c),month(b),day(a){}
		CDate(const CDate& cd){
			year=cd.year;
			month=cd.month;
			day=cd.day+1;
			int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
			if(check(year))days[2]++;
			if(day>days[month]){
				day=1;
				month++;
			}
			if(month>12){
				year++;
				month=1;
			}
		}
		
		void print(){
			cout<<year<<"/"<<month<<"/"<<day<<endl;
		}
		
	private:
		bool check(int y){
			int x=(y%100==0)?y%100:y;
			return x%4==0;
		}
		int year;
		int month;
		int day;
}; 



/*******************************************/
//主函数区域
int main()
{	int a,b,c;
	cin>>a>>b>>c;
	CDate d1(a,b,c);
	CDate d2=d1;
	CDate d3(d2);
	d1.print();
	d2.print();
	d3.print();
	return 0;
}


