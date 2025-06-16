#include<iostream>
using namespace std;

class CAccount{
	public:
		CAccount(long account,char *name,float balance):account(account),balance(balance){
			for(int i=0;i<10;i++){
				this->name[i]=name[i];
			}
		}
		
		void deposit(float money){
			balance+=money;
			cout<<"saving ok!"<<endl;
			check();
		}
		
		void withdraw(float money){
			if(money>balance){
				cout<<"sorry! over balance!"<<endl;
			}
			else{
				balance-=money;
				cout<<"withdraw ok!"<<endl;
			}
			check();
		}
		
		void check(){
			cout<<"balance is "<<balance<<endl;
		}
		
	protected:
		long account;
		char name[10];
		float balance;
};

class CCreditcard:public CAccount{
	private:
		float limit;
	public:
		CCreditcard(long account,char *name,float balance,float limit):CAccount(account,name,balance),limit(limit){}
	void withdraw(float money){
		if(money>balance+limit){
			cout<<"sorry! over limit!"<<endl;
		}else{
			balance-=money;
			cout<<"withdraw ok!"<<endl;
		}
		check();
	}
};

int main(){
	long account;
	char *name=new char[10];
	float balance;
	float limit;
	float money;
	
	cin>>account>>name>>balance;
	CAccount caccount(account,name,balance);
	
	cin>>money;
	caccount.check();
	caccount.deposit(money);
	cin>>money;
	caccount.withdraw(money);  
	
	cin>>account>>name>>balance>>limit;
	CCreditcard card(account,name,balance,limit);
	
	cin>>money;
	card.check();
	card.deposit(money);
	cin>>money;
	card.withdraw(money);  
	
	return 0;
}
