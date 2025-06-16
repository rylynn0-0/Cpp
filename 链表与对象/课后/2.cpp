#include<iostream>
using namespace std;

class CAccount{
	public:
		CAccount(long account,char name[],float balance){
			this->account =account;
			this->balance=balance;
			int i=0;
			while(name[i]){
				this->name[i]=name[i];
				i++;
			} 
			this->name[i]='\0';
		}
	
		void check(){
			cout<<name<<"'s balance is "<<balance<<endl;
		}
		
		void deposit(float money){
			balance+=money;
			cout<<"saving ok!"<<endl; 
			check();
		}
		
		void withdraw(float money){
			if(money>balance){
				cout<<"sorry! over limit!"<<endl;
			}
			else{
				balance-=money;
				cout<<"withdraw ok!"<<endl;
			}
			check();
		}
	
	private:
		long account;
		char name[10];
		float balance;
		
};

int main(){
	for(int i=0;i<2;i++){
		long account;
		char name[10];
		float balance;
		cin>>account>>name>>balance;
		CAccount ca(account,name,balance);
		ca.check() ;
		float money;
		cin>>money;
		ca.deposit(money); 
		cin>>money;
		ca.withdraw(money); 
	}
	
	
	return 0;
}
