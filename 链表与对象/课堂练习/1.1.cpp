#include<iostream>
using namespace std;
class Pump {
	double quantity;
	double price;
/********** Write your code here! **********/
	public:
	void set_m(double m){
		quantity=m;
	}
	void set_p(double p){
		price =p;
	}
	
	void jiayou(double youliang){
		if(quantity==0){
			return;
		}
		
		if(youliang <quantity){
			
			cout<<"before: "<<quantity<<" "<<price<<endl;
			quantity-=youliang;
			cout<<youliang<<" "<<price*youliang<<endl;
			cout<<"after: "<<quantity<<" "<<price<<endl;
		}
		
		else if(youliang >=quantity){
			cout<<"before: "<<quantity<<" "<<price<<endl;
			
			cout<<quantity<<" "<<price*quantity<<endl;
			quantity=0;
			cout<<"after: "<<quantity<<" "<<price<<endl;
			cout<<endl;
			cout<<"empty"<<endl;
			return; 
		}
		
		cout<<endl;
		
	}

};

int main(){
	double price,mol;
	cin>>mol>>price;
	
	Pump y;
	y.set_m(mol);
	y.set_p(price);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		double p;
		cin>>p;
		y.jiayou(p);
	}
/*******************************************/
	return 0;
}
