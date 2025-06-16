#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

class CBook{
	public:
		CBook(){};
		
		void set(string suoqu,string name,int num,int able_num){
		this->suoqu= suoqu;
		this->name= name;
		this->num=num;
		this->able_num= able_num;
		borrow_num+=(num-able_num);
		left_num+=(able_num);
		}
		
		void show()const{
			cout<<suoqu<<" "<<name<<" "<<num<<" "<<able_num<<endl;
		}
		
		string get_name(){
			return name;
		}
		
		void borrow(){
			cout<<name;
			if(able_num==0){
				cout<<" 该书已全部借出"<<endl;
			}
			else{
				able_num--;
				borrow_num++;
				left_num--;
				cout<<" 索取号: "<<suoqu<<endl; 
			}
		}
		
		static void show_all(){
			cout<<"借出图书: "<<borrow_num<<"本  剩余馆藏图书: "<<left_num<<"本"<<endl;
		}
		
		
	private:
		string suoqu;
		string name;
		int num;
		int able_num;
		static int borrow_num;
		static int left_num;
		
};
int CBook::borrow_num=0;
int CBook::left_num=0;

int main(){
	int n,m;
	cin>>n;
	CBook cb[n];
	string suoqu;
	string name;
	int num;
	int able_num;
	for(int i=0;i<n;i++){
		cin>>suoqu>>name>>num>>able_num;
		cb[i].set(suoqu,name,num,able_num);
		
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>name;
		for(int j=0;j<n;j++){
			
		if(name==cb[j].get_name()){
			cb[j].borrow();
		}
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cb[i].show() ;
	}
	cb[0].show_all();
	return 0;
} 
