#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Person{
	public:
		Person(){}
		Person(char _name[],char _num[]){
			strcpy(name,_name);
			strcpy(num,_num);
		}	
	
	private:
		friend class Compute;
		char name[10];
		char num[10];
		
};

class Compute{
	public:
		int cmp(Person& a,Person& b){
			return 1;
		}
		void setdata(int i,char name[],char num[]){
			person[i]=Person(name,num);
		}
		void Sort(){
			if(s(person[0],person[1]))swap(person[0],person[1]);
			if(s(person[1],person[2]))swap(person[1],person[2]);
			if(s(person[0],person[1]))swap(person[0],person[1]);
		}
		
		int s(Person &a,Person &b){
			int p=0;
			while(a.name[p]==b.name[p]){
				p++;
			}
			return a.name[p]>b.name[p];
		}
		
		void swap(Person &a,Person &b){
			Person c=a;
			a=b;
			b=c;
		}
		void print(){
			for(int i=0;i<3;i++){
				cout<<person[i].name<<" "<<person[i].num<<endl;
			}
		}
		
	private:
		Person person[3];
		
};

int main(){
	char name[3][10];
	char num[3][10];
	Compute cp;
	for(int i=0;i<3;i++){
		cin>>name[i]>>num[i];
		cp.setdata(i,name[i],num[i]);
		}
		cp.Sort();
		cp.print();
	return 0;
}
