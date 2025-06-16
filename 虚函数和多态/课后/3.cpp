#include<iostream>
using namespace std;

class Employee{
	protected:
		string name;
		int jibie;
		int nianxian;
		int salary;
		public:
	Employee(string name,int jibie,int  nianxian):name(name),jibie(jibie),nianxian(nianxian){
	if(jibie<0||nianxian<0)salary=-1;
	else{
		salary=1000+500*jibie+50*nianxian;
	}
	}
	
	virtual void display(){
		if(salary!=-1)cout<<name<<":Employee,Salary:"<<salary<<endl;
		else cout<<"error grade or year."<<endl;
	}
};

class Teamleader:public Employee{
	public:
	Teamleader(string name,int jibie,int nianxian):Employee(name,jibie,nianxian){
	if(jibie<0||nianxian<0)salary=-1;
	else{
		salary=3000+800*jibie+100*nianxian;
	}
	}
	
	virtual void display(){
		if(salary!=-1)cout<<name<<":Teamleader,Salary:"<<salary<<endl;
		else cout<<"error grade or year."<<endl;
	}
};

class Manager:public Employee{
	public:
	Manager(string name,int jibie,int nianxian):Employee(name,jibie,nianxian){
	if(jibie<0||nianxian<0)salary=-1;
	else{
		salary=5000+1000*jibie+1000*nianxian;
	}
	}
	
	virtual void display(){
		if(salary!=-1)cout<<name<<":Manager,Salary:"<<salary<<endl;
		else cout<<"error grade or year."<<endl;
	}
};

int main(){
	int n;
	cin>>n;
	string name,type;
	int jibie,nianxian;
	Employee*p;
	for(int i=0;i<n;i++){
		cin>>name>>type>>jibie>>nianxian;
		if(type=="Employee"){
			p=new Employee(name,jibie,nianxian);
			p->display();
		}else if(type=="Teamleader"){
		p=new Teamleader(name,jibie,nianxian);
		p->display();}
		else if(type=="Manager"){
		p=new Manager(name,jibie,nianxian);
		p->display();}
		else{
			cout<<"error position."<<endl;
		}
	}
	return 0;
}
