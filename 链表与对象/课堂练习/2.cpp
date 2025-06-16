#include<iostream>
using namespace std;

class 	CTollBooth{
	int shou;
	int unshou;
	int money;
	
	public:
		
	void c(){
		shou=0;
		unshou=0;
		money=0;
	}
		
	void payingCar(char str){
		if(str=='S'){
			unshou++;
		}
		else if(str=='C'){
			shou++;
			money+=5;
		}
		else if(str=='V'){
			shou++;
			money+=8;
		}
	}
	
	void show(){
		cout<<shou<<" "<<unshou<<" "<<money<<endl;
	}
};

int main(){
	
	CTollBooth c;
	c.c() ;
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		char x;
		cin>>x;
		c.payingCar(x); 
		c.show();
	}
	return 0;
}
