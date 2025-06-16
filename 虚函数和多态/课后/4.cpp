#include<iostream>
#include<iomanip>
using namespace std;

class CDate{
	int year,month,day;
	public:
	CDate(int y,int m,int d):year(y),month(m),day(d){}
	
	bool is_p(int y){
		if(y%100==0)y/=100;
		return y%4==0;
	}
	
	 int to(CDate &cd){
		int x[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int num=0;
		if(cd.year <year)return -1;
		else if(cd.year>year){
			for(int i=year;i<cd.year;i++){
				num+=365;
				if(is_p(i))num++;
			}
		}
		for(int i=1;i<month;i++){
			num-=x[i];
			if(is_p(cd.year)&&i==2)num--;
		}
		for(int i=1;i<cd.month;i++){
			num+=x[i];
			if(is_p(cd.year)&&i==2)num++;
		}
		num+=cd.day;
		num-=day;
		return num;
	}
};

class Pet

{ protected:

     string name;//姓名
     float length;//身长
     float weight;//体重
     CDate current;//开始记录时间（日期类CDate包含年、月、日三个私有数据，其他方法根据需要自拟。）

public:
	Pet(string name,float length,float weight,CDate& cd):name(name),length(length),weight(weight),current(cd){}
     virtual void display(CDate& day)=0;//输出目标日期时宠物的身长和体重

};

class Cat:public Pet{
	public:
		Cat(string name,float length,float weight,CDate& cd):Pet(name,length,weight,cd){}
		void display(CDate& day){
			int x=current.to(day);
			if(x>0 ){
				cout<<name<<" after "<<x<<" day: length="<<fixed<<setprecision(2)<<length+0.1*x<<",weight="<<weight+ 0.2*x<<endl;
			}
			else{
				cout<<"error"<<endl;
			}
		}
};

class Dog:public Pet{
	public:
		Dog(string name,float length,float weight,CDate& cd):Pet(name,length,weight,cd){}
		void display(CDate& day){
			int x=current.to(day);
			if(x>0 ){
				cout<<name<<" after "<<x<<" day: length="<<fixed<<setprecision(2)<<length+0.2*x<<",weight="<<weight+ 0.1*x<<endl;
			}
			else{
				cout<<"error"<<endl;
			}
		}
};

int main(){
	int n;
	cin>>n;
	int flag;
	float weight,length;
	string name;
	int y,m,d;
	cin>>y>>m>>d;
	CDate now(y,m,d);
	Pet*p;
	for(int i=0;i<n;i++){
		cin>>flag>>name>>length>>weight>>y>>m>>d;
		CDate late(y,m,d);
		if(flag==1){
			p=new Cat(name,length,weight,now);
		}else{
			p=new Dog(name,length,weight,now);
		}
		p->display(late);
		delete p;
	}
	
	return 0;
}
