#include<iostream>
using namespace std;



class vip_card{
	protected:
		int num;
		int cent;
	public:
		vip_card(int num,int cent=0):num(num),cent(cent){}
		
		
};

class money_card{
	protected:
		int num;
		string name;
		int edu;
		float money;
		int cent;
	public:
		money_card(int num,string name,int edu,float money=0,int cent=0):
		num(num),name(name),edu(edu),money(money),cent(cent){}
		
		void xiaofei(float m){
			if(money+m<=edu){
			
			money+=m;
			cent+=m;
		}
		}
		
		void tuikuan(float m){
			money-=m;
			cent-=m;
		}
		
};

class Card:public vip_card ,public money_card{
	private:
		void book(float m){
			money+=m;
			vip_card::cent+=m;
			money_card::cent+=(int)(m+0.5);
		}
		
		void duihuan(float m){
			money_card::cent-=m;
			vip_card::cent+=m/2;
		}
	
	public:
		Card(int vip_num,int money_num,string name,int edu):vip_card(vip_num),money_card(money_num,name,edu){}
		void display(){
			cout<<vip_card::num<<" "<<vip_card::cent<<endl;
			cout<<money_card::num<<" "<<name<<" "<<money<<" "<<money_card::cent<<endl;
		}
		
		void check(char flag,float money){
			if(flag=='o'){
				book(money);
			}else if(flag=='c'){
				xiaofei(money);
			}else if(flag=='q'){
				tuikuan(money);
			}else{
				duihuan(money);
			}
		}
};

int main(){
	int vip_num,money_num;
	string name;
	int edu;
	cin>>vip_num>>money_num>>name>>edu;
	Card  c(vip_num,money_num,name,edu);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		char flag;
		float money;
		cin>>flag>>money;
		c.check(flag,money);
	}
	c.display();
	return 0;
}
