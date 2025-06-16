//ͷ�ļ���������
#include <iostream>
using namespace std;

class MyDate {
private:
	int year;
	int month;
	int day;
public:
	MyDate(); //�޲ι��죬Ĭ������2022-4-1�������ع�����Ϣ
	MyDate(int ty, int tm, int td); //�вι��죬���ݲ�����ʼ���������ع�����Ϣ
	~MyDate(); 
	bool Before(MyDate &rd);
	void print()
	{ cout<<year<<"-"<<month<<"-"<<day; }
};
//������д��ʵ�ֺ�������
/********** Write your code here! **********/

MyDate::MyDate(){
	year=2022;
	month=4;
	day=1;
	cout<<"Date 2022-4-1 default constructed"<<endl;
}
MyDate::MyDate(int ty, int tm, int td){
	year=ty;
	month=tm;
	day=td;
	cout<<"Date ";
	print();
	cout<<" constructed"<<endl;
}

bool MyDate::Before(MyDate &rd){
	if(rd.year!=year)return rd.year<year;
	if(rd.month!=month)return rd.month<month;
	if(rd.day!=day)return rd.day<day;
	
}

MyDate::~MyDate(){
	cout<<"Date ";
	print();
	cout<<" destructed"<<endl;
}

int main(){
	MyDate M;
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int y,m,d;
		cin>>y>>m>>d;
		MyDate D(y,m,d);
		if(!M.Before(D)){
			M.print();
			cout<<" before ";
			D.print();
			cout<<endl;
		}
		else{
			D.print();
			cout<<" before ";
			M.print();
			cout<<endl;
		}
		
	}
	
	return 0;
}



/*******************************************/
//main end 
