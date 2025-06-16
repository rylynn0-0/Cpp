#include<iostream>
using namespace std;
class RMB;
class MY;
class Base{
	protected:

	public:
	 virtual void set(istream& Cin)=0;
	 virtual void show()=0;
	 virtual operator double()=0;
};

istream &operator>>(istream& Cin,Base *b){
	b->set(Cin);
	return Cin;
}

class RMB:public Base{
	int yuan;
	int jiao;
	int fen;
	public:
		RMB(){}
		RMB(int y,int j,int f):yuan(y),jiao(j),fen(f){}
		void set(istream& Cin){
			Cin>>yuan>>jiao>>fen;
		}
		void show(){
			cout<<yuan<<" "<<jiao<<" "<<fen<<endl;
		}
		operator double(){
			double num=yuan+jiao*0.1+fen*0.01;
		
			return num;
		}
		
};

class MY:public Base{
	int dollar;
	int cent;
	public:
		MY(){}
		MY(int d,int c):dollar(d),cent(c){}
		void set(istream &Cin){
			Cin>>dollar>>cent;
			
		}
		
		void show(){
			cout<<dollar<<" "<<cent<<endl;
		}
		operator double(){
		double num=(dollar+cent*0.01)*7.2;
	
			return num;
		}
		
};



int main(){
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		string s1,s2;
		Base *b1,*b2;
		
		cin>>s1;
		if(s1=="RMB"){
			b1=new RMB();
			cin>>b1;
		}else{
			b1=new MY();
			cin>>b1;
		}
		cin>>s2; 
		if(s2=="RMB"){
			b2=new RMB();
			cin>>b2;
		}else{
			b2=new MY();
			cin>>b2;
		}
		string ans;
		if((double)(*b1)>(double)(*b2))ans=">";
		else if((double)(*b1)<(double)(*b2))ans="<";
		else ans="=";
		
		cout<<ans<<endl;
		
	}
	return 0;
}
