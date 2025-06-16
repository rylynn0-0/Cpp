#include<iostream>
using namespace std;

class Account{
	public:
		Account(){}
		Account(string accno,string name ,float balance){
		_accno=accno;
		_accname=name;
		_balance=balance;	
		sum+=balance;
		}
		~Account(){}
		void Deposit(float amount){
			_balance+=amount;
			sum+=amount;
		}
		void Withdraw(float amount){
			_balance-=amount;
			sum-=amount;
		}
		float GetBalance(){
			return _balance;
		}
		void Show(){
			cout<<_accno<<" "<<_accname<<" "<<GetBalance();
		}
		
		void Show_balance(){
			cout<<" "<<_balance;
		}
		static int GwtCount(){
			return count;
		}
		static float GetInteresetRate(){
			return InterestRate;
		}
		
		static void setCount(int c){
			count=c;
		}
		static void setInterestRate(float rate){
			InterestRate=rate;
		}
		friend void Update(Account& a);
		static void Show_sum(){
			cout<<sum<<endl;
		}
	private:
		static int count;
		static float InterestRate;
		string _accno,_accname;
		float _balance;
		static float sum;
};


float Account::InterestRate=0;
int Account::count=0;
float Account::sum=0;
void Update(Account& a){
	a.sum-=a._balance;
	a._balance+=a._balance*a.InterestRate;
	a.sum+=a._balance;
}

int main(){
	float rate;
	int count;
	cin>>rate>>count;
	Account* acc=new Account[count];
	Account::setCount(count);
	Account::setInterestRate(rate);  
	for(int i=0;i<count;i++){
		
		string accno,accname;
		float balance;
		cin>>accno>>accname>>balance;
		acc[i]=Account(accno,accname,balance);
		
		float deposit,withdraw;
		cin>>deposit>>withdraw;
		acc[i].Deposit(deposit);
		acc[i].Show();
		Update(acc[i]);
		acc[i].Show_balance();
		acc[i].Withdraw(withdraw);
		acc[i].Show_balance();
		cout<<endl;
		
	}
	Account::Show_sum();
	return 0;
}
