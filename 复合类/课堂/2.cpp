#include <iostream>
using namespace std;

class MyDate {
private:
	int year, month, day;
public:
	void set(int ty=0, int tm=0, int td=0)	
	{	year = ty, month = tm, day = td; }
	void print()
	{	cout<<year<<"-"<<month<<"-"<<day<<endl;	}
};
MyDate today; //全局变量，用于毕业日期设置

class STU {
private:
	long id;	//学号
	int gra_state; //未毕业为0，毕业为1
	MyDate *gra_date; //毕业日期，初始为空
public:
	STU(int ti);	//有参构造，输出相关信息
	STU(STU & rs);	//拷贝构造，设置毕业状态和毕业日期，输出相关信息
	~STU()
	{	if (gra_state==1) //判断是否毕业
		{	cout<<"毕业生"<<id<<"已析构"<<endl;
			cout<<"毕业日期";
			gra_date->print();
			delete gra_date;
		}
		else
			cout<<"学生"<<id<<"已析构"<<endl;
	}
};
//实现STU类的有参构造和拷贝构造
/********** Write your code here! **********/
STU::STU(int ti){
	id=ti;
	gra_state=0;
	cout<<"学生"<<id<<"已构造"<<endl;
}

STU::STU(STU & rs){
	gra_state=1;
	id=rs.id;
	gra_date=new MyDate(today);
	cout<<"毕业生"<<id<<"已构造"<<endl;
}


/*******************************************/
//主函数如下
int main()
{	int y, m, d, ti;
	cin>>y>>m>>d;
	today.set(y,m,d);
	cin>>ti;
	STU s1(ti); //通过构造函数生成一个在校学生
	STU s2=s1;	//通过拷贝构造生成毕业生

	return 0;
}
