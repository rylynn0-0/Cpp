#include<iostream>
using namespace std;

class Count{
	public:
		Count(int id,char type,double money){
			this->id=id;
			this->type=type;
			this->money=money;
			rate=0.005;
		}
		
		Count(Count &c){
			id=c.id+50000000;
			type=c.type;
			money=c.money;
			rate=0.015;
		}
		
		void check(char str){
			if(str=='C'){
				cout<<"Account="<<id<<"--sum="<<money*(1+rate)<<endl;
			}
			else{
				string s=(type=='P')?"Person":"Enterprise";
				cout<<"Account="<<id<<"--"<<s<<"--"<<"sum="<<money<<"--rate="<<rate<<endl;
			}
		}
		
	private:
		double money;
		double rate;
		int id;
		char type;
};


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		double money;
		double rate;
		int id;
		char type;
		cin>>id>>type>>money;
		Count count1(id,type,money);
		Count count2(count1);
		char c;
		cin>>c;
		count1.check(c);
		cin>>c;
		count2.check(c); 
		
	}
	return 0;
}
