#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Cat{
	public:
		void set(string name,int weight){
			this->name=name;
			this->weight=weight;
		}
		
		int get_w(){
			return weight;
		}
		
		void show_name(){
			cout<<name;
		}
	private:
		string name;
		int weight;
};

int cmp(Cat c1,Cat c2){
	return c1.get_w()<c2.get_w() ; 
}

int main(){
	int t;
	cin>>t;
	Cat *cat=new Cat[t];
	for(int i=0;i<t;i++){
		string name;
		int weight;
		cin>>name>>weight;
		cat[i].set(name,weight);
	}
	sort(cat,cat+t,cmp);
	cat[0].show_name() ;
	for(int i=1;i<t;i++){
		cout<<" ";
		cat[i].show_name() ;
	}
	cout<<endl;
	
	return 0;
}
