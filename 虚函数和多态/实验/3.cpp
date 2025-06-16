#include<iostream>
using namespace std;



class BaseAccount{
	protected:
		string name;
		string account;
		double balance;
	public:
	
	BaseAccount(string name,string account,double balance):name(name),account(account),balance(balance){}
	
	virtual void  deposit(double m){
		balance+=m;
	}
	
	virtual void withdraw(double m){
		if(balance >=m)balance-=m;
		else cout<<"insufficient"<<endl;
	}
	
	virtual void display(){
		cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<endl;
	}
};

class BasePlus:public BaseAccount{
	double limit;
	double limit_sum;
	public:
	BasePlus(string name,string account,double balance):BaseAccount(name,account,balance){
	limit=5000;
	limit_sum=0;
	}
	
	virtual void  deposit(double m){
		balance+=m;
	}
	
	virtual void withdraw(double m){
		if(balance >=m)balance-=m;
		else if(balance + limit>=m){
			
			limit-=(m-balance);
			limit_sum+=(m-balance);
			balance =0;
		}
		else cout<<"insufficient"<<endl;
	}
	
	virtual void display(){
		cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<" limit:"<<limit<<endl;
	}
};

int main(){
	int n;
	string name,account;
	double balance,m;
	cin>>n;
	BaseAccount* p;
	for(int i=0;i<n;i++){
		cin>>name>>account>>balance;
		if(account[1]=='A'){
			p=new BaseAccount(name,account,balance);
			cin>>m;
			p->deposit(m);
			cin>>m;
			p->withdraw(m);
			cin>>m;
			p->deposit(m);
			cin>>m;
			p->withdraw(m);
			p->display();
		}
		else{
			p=new BasePlus(name,account,balance);
			cin>>m;
			p->deposit(m);
			cin>>m;
			p->withdraw(m);
			cin>>m;
			p->deposit(m);
			cin>>m;
			p->withdraw(m);
			p->display();
		}
		delete p;
	}
	
	return 0;
}
