#include<iostream>
using namespace std;

class cd{
	public:
	cd(int type,string name,int money,int statu){
		this->type=type;
		this->name=name;
		this->money=money;
		this->statu=statu;
	}
	
	void set(int type,string name,int money,int statu){
		this->type=type;
		this->name=name;
		this->money=money;
		this->statu=statu;
	}
	
	void Print(){
		string t;
		if(type==1)t="BF";
		if(type==2)t="CD";
		if(type==3)t="VCD";
		if(type==4)t="DVD";
		cout<<t<<"["<<name<<"]";
		if(statu==0)cout<<"not rented"<<endl;
		if(statu==1){cout<<"rented"<<endl;}
		
	}
	
	void Fee(int x){
		if(x==0)return;
		else{
			if(statu==0)cout<<"No rental"<<endl;
			else cout<<"Rental: "<<x*money<<endl;
		}
		
	}
	
	private:
		int type;
		string name;
		int money;
		int statu;
};

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int type;
		string name;
		int money;
		int statu;
		cin>>type>>name>>money>>statu;
		cd c(type,name,money,statu);
		int x;
		cin>>x;
		c.Print();
		c.Fee(x); 
	}
	
	return 0;
} 
