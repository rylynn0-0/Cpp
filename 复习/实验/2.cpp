#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define SET(type,T) void set_##T(type T){this->T=T;}

class CStock{
	public:
		CStock(){
			name="ChinaPingan";
			code="000001";
		}
		CStock(string name,string code):name(name),code(code){}
		
		CStock(CStock &cs,double cur){
			name=cs.name;
			code=cs.code;
			prePrice=cs.curPrice;
			curPrice=cur;
		}
		
		SET(string,name);
		SET(string,code);
		SET(double,prePrice);
		SET(double,curPrice);
		
		double getChange(){
			return (curPrice-prePrice)/prePrice*100;
		}
		
		void print(){
			cout<<name<<" "<<code<<" "<<fixed<<setprecision(2)<<prePrice<<" "<<curPrice<<" "<<getChange()<<"%"<<endl;
		}
		
	
	private:
		string name;
		string code;
		double prePrice;
		double curPrice;
};

int main(){
	
	int n;
	cin>>n;
	for(int o=0;o<n;o++){
		int mode;
		cin>>mode;
		if(mode==1){
			CStock cs;
			double cur;
			cin>>cur;
			cs.set_curPrice(cur);
			for(int i=0;i<5;i++){
				cin>>cur;
				cs=CStock(cs,cur);
				cs.print();
			}
		}
		
		else{
			string name;
			string code;
			cin>>name>>code;
			CStock cs(name,code);
			double cur;
			cin>>cur;
			cs.set_curPrice(cur);
			for(int i=0;i<5;i++){
				cin>>cur;
				cs=CStock(cs,cur);
				cs.print();
			}
		}
	}
	
	return 0;
}
