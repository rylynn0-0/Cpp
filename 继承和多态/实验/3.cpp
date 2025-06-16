#include<iostream>
using namespace std;

class Person{
	protected:
	string name ;
	int age;
	public:
		Person(string name,int age):name(name),age(age){}
		
		void display(){
			cout<<name<<" "<<age<<" ";
		}
};

class Student_R:public Person{
	public:
		Student_R(string name,int age,int score,int ex_score):Person(name,age){
			this->score=score;
			this->ex_score=ex_score;
			int final=score*0.4+ex_score*0.6;
			
			if(final>=85)final_score='A';
			else if(75<=final)final_score='B';
			else if(65<=final)final_score='C';
			else if(60<=final)final_score='D';
			else final_score='F';
		}
		
		void display(){
			Person::display() ;
			cout<<final_score<<endl; 
		}
		
		
	private:
		int score;
		int ex_score;
		char final_score;
};

class Student_S:public Person{
	public:
		Student_S(string name,int age,int score):Person(name,age){
			this->final=score;
			
			if(final>=85)final_score='A';
			else if(75<=final)final_score='B';
			else if(65<=final)final_score='C';
			else if(60<=final)final_score='D';
			else final_score='F';
		}
		
		void display(){
			Person::display() ;
			cout<<final_score<<endl; 
		}
		
		
	private:
		int final;
		char final_score;
};

int main(){
	string name;
	int age;
	int score;
	int ex_score;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char x;
		cin>>x;
		cin>>name>>age>>score;
		if(x=='R'){
		
				cin>>ex_score;
				Student_R stu1(name,age,score,ex_score);
				stu1.display() ;
			
			}
			
			else{
			
				Student_S stu2(name,age,score);
				stu2.display() ;
			
			}
	
	}
	return 0;
}
