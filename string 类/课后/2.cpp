#include<bits/stdc++.h>
using namespace std;

class Person{
	protected:
		string name;
		int age;
	public:
		Person(){}
		Person(string name,int age):name(name),age(age){}
		
		void set(string name,int age){
			this->name=name;
			this->age=age;
		}
		void display(){
			cout<<name<<" "<<age<<" ";
		}
};

class Student:public Person{
	double ps_score;
	double ks_score;
	double zp_score;
	public:
		Student(){}
		Student(string name,int age,double ps_score,double ks_score):Person(name,age){
			this->ps_score =ps_score;
			this->ks_score =ks_score;
			zp_score=ps_score*0.4+ks_score*0.6;
		}
		
		void set(string name,int age,double ps_score,double ks_score){
			Person::set(name,age);
			 this->ps_score =ps_score;
			this->ks_score =ks_score;
			zp_score=ps_score*0.4+ks_score*0.6;
		}
		
		double get_score(){
			return zp_score;
		}
		
		void display(){
			Person::display() ;
			cout<<fixed<<setprecision(2)<<zp_score<<endl;
		}
};

class Teacher:public Person{
	int num;
	double pj_score;
	
	Student *stu;
	public:
		Teacher(){}
		Teacher(string name,int age):Person(name,age){
			cin>>num;
			double sum_score=0;
			stu= new Student[num];
			for(int i=0;i<num;i++){
				string sname;
				int sage;
				double ps_score;
				double ks_score;
				cin>>sname>>sage>>ps_score>>ks_score;
				stu[i].set(sname,sage,ps_score,ks_score);
				sum_score+=stu[i].get_score();
			}
			pj_score=sum_score/num;
		}
		
		void display(){
			Person::display() ;
			cout<<num<<" "<<fixed<<setprecision(2)<<pj_score<<endl;
			for(int i=0;i<num;i++){
				stu[i].display();
			}
		}
		~Teacher(){
			delete []stu;
		}
};

int main(){
	string name;
	int age;
	cin>>name>>age;
	Teacher t(name,age);
	t.display() ;
	return 0;
}
