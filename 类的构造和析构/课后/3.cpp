#include<iostream>
using namespace std;

class Account{
	
	public:
		void set(int i,int p,int k,int m){
			id=i;
			phone=p;
			key=k;
			money=m;
		}
		
		int get_id(){
		return id;}
		
		int get_phone(){
		return phone;}
		
		int get_money(){
		return money;}
		
		bool check(int key){
		return key==this->key;} 
		
		void qukuan(int m){
			
			if(money>=m){
				money-=m;
				cout<<"¿¨ºÅ"<<id<<"--"<<"Óà¶î"<<money<<endl; 
			}
			else{
				cout<<"¿¨ºÅ"<<id<<"--"<<"Óà¶î²»×ã"<<endl;
			}
		}
	
	private:
		int id;
		int phone;
		int key;
		int money;
		
};

int main(){
	
	int n;
	cin>>n;
	Account a[n];
	for(int i=0;i<n;i++){
		int id;
		int phone;
		int key;
		int money;
		cin>>id>>phone>>key>>money;
		a[i].set(id,phone,key,money);
		//cout<<a[i].get_phone() <<endl;
	} 
	
	
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int f=0;
		int p,key,mon;
		cin>>p>>key>>mon;
		for(int j=0;j<n;j++){
			if(a[j].get_phone()==p){
				f=1;
				if(a[j].check(key)){
					a[j].qukuan(mon); 
				}
				else cout<<"ÃÜÂë´íÎó"<<endl;
			}
		}
		if(f==0)cout<<"ÊÖ»úºÅ²»´æÔÚ"<<endl;
	}
	
	return 0;
}
