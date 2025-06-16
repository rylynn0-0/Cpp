#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

class Student{
	public:
		void set(string id,string name,string birthday,float score){
			this->id=id;
			this->name=name;
			this->birthday=birthday;
			this->score=score;
		}
		
		string get_id(){
			return id;
		}
		
		void show(){
			string bir=f(birthday);
			cout<<"id:"<<id<<" name:"<<name<<" birthday:"<<bir<<" score:"<<fixed<<setprecision(1)<<score<<endl;
		}
		
	private:
		string  f(string str){
			string s1=string(str,0,4);
			string s2=string(str,5,2);
			if(s2[0]=='0')s2=string(s2,1,1);
			string s3 =string(str,8,2);
			if(s3[0]=='0')s3=string(s3,1,1);
			string s=s1+"_"+s2+"_"+s3;
			return s;
		}
		
		string id;
		string name;
		string birthday;
		float score;
};

int cmp(Student s1,Student s2){
	return s1.get_id()<s2.get_id();
}

int main(){
	
	int t;
	cin>>t;
	
	int p=0;
	Student s[t];
	for(int i=0;i<t;i++){
		int h=0;
		string id;
		string name;
		string birthday;
		float score;
		cin>>id>>name>>birthday>>score;
		for(int j=0;j<i;j++){
			if(id==s[j].get_id()){
				s[j].set(id,name,birthday,score); 
				p++;
				
				h=1;
			}
		}
		if(h!=1) s[i-p].set(id,name,birthday,score); 
	}
	
	sort(s,s+t-p,cmp);
	
	for(int i=0;i<t-p;i++){
		s[i].show();	
	}
	
	return 0;
}
