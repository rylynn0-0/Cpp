#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Body{
	public:
		Body(string name,double height,double weight,double yaowei){
			this->name=name;
			this->height=height;
			this->weight=weight;
			this->yaowei=yaowei;
//			cout<<name<<endl;
//			cout<<height<<endl;
//			cout<<weight<<endl;
//			cout<<yaowei<<endl;			
		}
		
		string get(){return name;}
		
		int BMI(){
			float x=(weight/(height*height));
			int n=(int)(x+0.5);
			return n;
		}
		
		float BFR(){
			return (yaowei*0.74-weight*0.082-34.89)/weight;
		}
		
	private:
		string name;
		double height;
		double weight;
		double yaowei;
};

int main(){
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string name;
		double height;
		double weight;
		double yaowei;
		cin>>name>>height>>weight>>yaowei;
		Body b(name,height,weight,yaowei);
		cout<<b.get()<<"'s BMI: "<<b.BMI()<<"--BFR: "<<fixed<<setprecision(2)<<b.BFR()<<endl;
	}
	return 0;
}
