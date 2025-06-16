#include<iostream>
using namespace std;

class Vehicle{ 
protected:
	string no;//编号
public:
	Vehicle(string no=""):no(no){}
	virtual void display()=0;//应收费用

};

class Car:public Vehicle{
	int num;
	int weight;
	public:
		Car(string no,int num,int weight):Vehicle(no),num(num),weight(weight){}
		void display(){
			cout<<no<<" "<<num*8+weight*2<<endl;
		}
};


class Truck:public Vehicle{
	
	int weight;
	public:
		Truck(string no,int weight):Vehicle(no),weight(weight){}
		void display(){
			cout<<no<<" "<<weight*5<<endl;
		}
};

class Bus:public Vehicle{
	int num;
	
	public:
		Bus(string no,int num):Vehicle(no),num(num){}
		void display(){
			cout<<no<<" "<<num*3<<endl;
		}
};

int main(){
	int n;
	cin>>n;
	string no;
	int num;
	int weight;
	Vehicle* pv;
	int f;
	for(int i=0;i<n;i++){
		cin>>f;
		if(f==1){
			cin>>no;
			cin>>num>>weight;
			pv=new Car(no,num,weight);
			pv->display() ;
		}else if(f==2){
			cin>>no;
			cin>>weight;
			pv=new Truck(no,weight);
			pv->display() ;
		} else{
			cin>>no;
			cin>>num;
			pv=new Bus(no,num);
			pv->display();
		}
		delete pv;
	}
	return 0;
} 
