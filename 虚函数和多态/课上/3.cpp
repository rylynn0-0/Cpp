#include<iostream>
using namespace std;
/********** Write your code here! **********/
class Animal{
	protected:
		int age;
	public:
		Animal(int age):age(age){
			cout<<"Animal constructed."<<endl;
		}
		Animal(Animal &a){
			age=a.age;
			cout<<"Animal copy constructed."<<endl;
		}
		
		virtual void display(){
			cout<<"Animal age: "<<age<<endl;
		}
};

class Bird:public Animal{
	double wingspan;
	public:
		Bird(int age,double wingspan):Animal(age),wingspan(wingspan){
			cout<<"Bird constructed."<<endl;
		}
		
		void display(){
			Animal::display() ;
			cout<<"Wingspan: "<<wingspan<<"m"<<endl;
		}
};



/*******************************************/
void display(Animal* obj) {
	obj->display();
}

int main() {
	int a; float w; 
	cin >> a >> w;
	Bird obj(a, w);
	obj.display();
	cout << endl;
	display(&obj);
	return 0;
}
//Animal constructed.
//Bird constructed.
//Animal age: 5
//Wingspan: 3.6m
//
//Animal age: 5
//Wingspan: 3.6m
