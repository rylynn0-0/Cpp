#include<iostream>
using namespace std;

class CPerson{
	protected:
		string name;
		string phone_num;
	public:
		CPerson(string name,string phone_num):name(name),phone_num(phone_num){}
		
};

class Student_normal:public CPerson{
	private:
		int Atime[12];
	public:
		Student_normal(string name,string phone_num):CPerson(name,phone_num){
			for(int i=0;i<12;i++){
				cin>>Atime[i];
			} 
		}
		void check(){
			int n=0;
			for(int i=0;i<12;i++){
				if(Atime[i]>=60)n++;
			}
			
			if(n>=10){
				cout<<name<<"达到学时要求可以预约！电话"<<phone_num<<endl;
			}
			else cout<<name<<"未达到学时要求不能预约！电话"<<phone_num<<endl;
		}
};

class Student_vip:public CPerson{
	private:
		int Atime[12];
		int Btime[12];
	public:
		Student_vip(string name,string phone_num):CPerson(name,phone_num){
			for(int i=0;i<12;i++){
				cin>>Atime[i];
			} 
			for(int i=0;i<12;i++){
				cin>>Btime[i];
			}
		}
		
		void check(){
			int n=0;
			
			for(int i=0;i<12;i++){
				if(Atime[i]>=60)n++;
			} 
			
			for(int i=0;i<12;i++){
				if(Btime[i]>=120)n+=2;
				else if(Btime[i]>=60)n++;
			}
			
			if(n>=10){
				cout<<name<<"达到学时要求可以预约！电话"<<phone_num<<endl;
			}
			else cout<<name<<"未达到学时要求不能预约！电话"<<phone_num<<endl;
		}
};


int main(){
	int n;
	string name;
	string num;
	char x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		cin>>name>>num;
		if(x=='F'){
			Student_normal f(name,num);
			f.check();
		}
		else {
			Student_vip v(name,num);
			v.check();
		}
	}
	return 0;
}
