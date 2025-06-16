#include<iostream>
using namespace std;

class Student{
	public:
	void set(string name,string num,string xueyuan,string zhuanye,string xingbie,string sushe,string shoujihao){
		this->name =name;
		this->num =num;
		this->xueyuan =xueyuan;
		this->zhuanye =zhuanye;
		this->xingbie =xingbie;
		this->sushe =sushe;
		this->shoujihao =shoujihao;
	}
	
	void show(){
		cout<<name<<" "<<num<<" "
		<<xueyuan<<" "
		<<zhuanye<<" "
		<<xingbie<<" "
		<<sushe<<" "
		<<shoujihao<<endl;
	}
	
	private:
		string name;
		string num;
		string xueyuan;
		string zhuanye;
		string xingbie;
		string sushe;
		string shoujihao;
};

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		Student s;
		string name;
		string num;
		string xueyuan;
		string zhuanye;
		string xingbie;
		string sushe;
		string shoujihao;
		cin>>name>>num>>xueyuan>>zhuanye>>xingbie>>sushe>>shoujihao;
		s.set(name,num,xueyuan,zhuanye,xingbie,sushe,shoujihao);
		s.show();
	}
	
	return 0;
} 
