#include<iostream>
using namespace std;
class Animal{
	protected:
	string name;
	int age;

	public:
		Animal(string name,int age):name(name),age(age){}
		virtual void speak()=0;
};

class Tiger:public Animal{
	public:
		Tiger(string name,int age):Animal(name,age){}
		void speak(){
			cout<<"Hello,I am "<<name<<",AOOO."<<endl;
		}
};

class Dog:public Animal{
	public:
		Dog(string name,int age):Animal(name,age){}
		void speak(){
			cout<<"Hello,I am "<<name<<",WangWang."<<endl;
		}
};

class Duck:public Animal{
	public:
		Duck(string name,int age):Animal(name,age){}
		void speak(){
			cout<<"Hello,I am "<<name<<",GAGA."<<endl;
		}
};

class Pig:public Animal{
	public:
		Pig(string name,int age):Animal(name,age){}
		void speak(){
			cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
		}
};

int main(){
	Animal *p;
	int n,age;
	string type;
	string name;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>type>>name>>age;
		
		if(type=="Tiger"){
			p=new Tiger(name,age);
			p->speak() ;
		}
		else if(type=="Dog"){
			p=new Dog(name,age);
			p->speak() ;
		}
		else if(type=="Duck"){
			p=new Duck(name,age);
			p->speak() ;
		}
		else if(type=="Pig"){
			p=new Pig(name,age);
			p->speak() ;
		}else{
			cout<<"There is no "<<type<<" in our Zoo."<<endl; 
		}
	}
	return 0;
}
