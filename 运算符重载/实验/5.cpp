#include<iostream>
#include<cmath>
using namespace std;

class Student{
	string name;
	int y,m,d;
	bool is_p(int i){
		if(i%100==0)i/=100;
		return i%4==0;
	}
	
	public:
		
	void set(string name,int y,int m,int d){
		this->name=name;
		this->y=y;
		this->m=m;
		this->d=d;
	}
	
	friend void display(Student& s1,Student&s2,int maxx);
	
	int operator-(Student& s){
		int num1=0,num2=0;
		int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int y_m=min(y,s.y);
		if(y!=y_m){
			for(int i=y_m+1;i<=y;i++){
				if(is_p(i))num1+=366;
				else num1+=365;
			}
		}
		if(s.y!=y_m){
			for(int i=y_m+1;i<=s.y;i++){
				if(is_p(i))num2+=366;
				else num2+=365;
			}
		}
		
		for(int i=1;i<=m;i++){
			num1+=month[i];
			if(i==2&&is_p(y))num1++;
		}
		
		for(int i=1;i<=s.m;i++){
			num2+=month[i];
			if(i==2&&is_p(s.y))num2++;
		}
		
		num1+=d;
		num2+=s.d;
		
		return num1-num2+1;
	}
};

void display(Student& s1,Student&s2,int maxx){
	cout<<s1.name<<"和"<<s2.name<<"年龄相差最大，为"<<maxx<<"天"<<endl;
}


int main(){
	string name;
	int y,m,d;
	int t;
	cin>>t;
	Student *s=new Student[t];
	for(int i=0;i<t;i++){
		cin>>name>>y>>m>>d;
		s[i].set(name,y,m,d);
	}
	int maxx=0;
	int pi,pj;
	for(int i=0;i<t-1;i++){
		for(int j=i+1;j<t;j++){
			if(abs(s[i]-s[j])>maxx){
				maxx=abs(s[i]-s[j]);
				pi=i;
				pj=j;
			}
		}
	}
	
	display(s[pi],s[pj],maxx);
	
	return 0;
}
