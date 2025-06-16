#include<iostream>
using namespace std;

class Animal{
	protected:
		int age;
	public:
		Animal(int a):age(a){
			cout<<"Animal constructed."<<endl;
		}
		void display(){
			cout<<"Animal age: "<<age<<endl;
		}
		
};

class Bird:virtual public Animal{
	protected:
		float wingspan;
	public:
		Bird(int a,float w):Animal(a),wingspan(w){
			cout<<"Bird constructed."<<endl;
		}
		void display(){
			cout<<"Wingspan: "<<wingspan<<"m"<<endl;
		}
};

class Mammal:virtual public Animal{
	protected:
		double weight;
	public:
		Mammal(int a,double wt):Animal(a),weight(wt){
			cout<<"Mammal constructed."<<endl;
		}
		void display(){
			cout<<"Weight: "<<weight<<"kg"<<endl;
		}
};

class Platypus:public Bird,public Mammal{
	public:
		Platypus(int a,float w,double wt):Animal(a),Bird(a,w),Mammal(a,wt){
			cout<<"Platypus constructed."<<endl;
		}
		
		void display(){
			Animal::display() ;
			Bird::display();
			Mammal::display() ;
		}
		
};
int main(){
	int a;
	float w;
	double wt;
	cin>>a>>w>>wt;
	Platypus p(a,w,wt);
	p.display();
	return 0;
}
