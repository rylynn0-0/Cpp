#include<iostream>
using namespace std;

class yt{
	public:
	
	void set_m(double m){
		mol=m;
	}
	void set_p(double p){
		price =p;
	}
	
	void jiayou(double youliang){
		if(mol==0){
			cout<<"empty"<<endl;
			return;
		}
		
		if(youliang <=mol){
			
			cout<<"before: "<<mol<<" "<<price<<endl;
			mol-=youliang;
			cout<<youliang<<" "<<price*youliang<<endl;
			cout<<"after: "<<mol<<" "<<price<<endl;
		}
		
		if(youliang >mol){
			cout<<"before: "<<mol<<" "<<price<<endl;
			
			cout<<mol<<" "<<price*mol<<endl;
			mol=0;
			cout<<"after: "<<mol<<" "<<price<<endl;
		}
		
		cout<<endl;
		
	}
	
	private:
		
	double price;
	double mol;
	
	
};

int main(){
	double price,mol;
	cin>>mol>>price;
	
	yt y;
	y.set_m(mol);
	y.set_p(price);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		double p;
		cin>>p;
		y.jiayou(p);
	}
	return 0;
} 
