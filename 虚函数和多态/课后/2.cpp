#include<iostream>
#include<iomanip>
using namespace std;

class 	CBook{
	protected:
		string type;
		string name;
		double m;
		char flag;
	public:
		CBook(string type,string name,double m,char flag):type(type),name(name),m(m),flag(flag){}
		
		virtual void display()=0;
};

class Textbook:public CBook{
	double m_;
	public:
		Textbook(string type,string name,double m,char flag):CBook(type ,name ,m,flag){
		m_=m*0.5;
		if(flag=='Y')m_*=0.8;
		}
		
		void display(){
			if(m_<5&&m>5)m_=5;
			cout<<type<<" "<<name<<" "<<fixed<<setprecision(2)<<m_<<endl;
		}
};

class Science:public CBook{
	double m_;
	public:
		Science(string type,string name,double m,char flag):CBook(type ,name,m,flag){
			m_=m*0.8+5;
			if(flag=='Y')m_*=0.8;
		}
		
		void display(){
			if(m_<5&&m>5)m_=5;
			cout<<type<<" "<<name<<" "<<fixed<<setprecision(2)<<m_<<endl;
		}
};

class History:public CBook{
	double m_;
	public:
		History(string type,string name,double m,char flag):CBook(type ,name,m,flag){
		m_=m*0.75-5;
		if(flag=='Y')m_*=0.8;
		}
		
		void display(){
			if(m_<=0||m_>m)m_=m;
			else if(m_<5&&m>5)m_=5;
			cout<<type<<" "<<name<<" "<<fixed<<setprecision(2)<<m_<<endl;
		}	
};


int main(){
	int n;
	cin>>n;
	string type,name;
	double m;
	char flag;
	CBook *p;
	for(int i=0;i<n;i++){
		cin>>type>>name>>m>>flag;
		if(type=="Textbook"){
			p=new Textbook(type,name,m,flag);
		}else if(type=="Science"){
			p=new Science(type,name,m,flag);
		}else p=new History(type,name,m,flag);
		p->display() ;
		delete p;
	}
	return 0;
}
