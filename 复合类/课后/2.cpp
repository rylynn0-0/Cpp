#include<iostream>
using namespace std;

class CDate{
	public:
		CDate(int a,int b,int c):year(a),month(b),day(c){}
	
		void print(){
			cout<<year<<"."<<month<<"."<<day;
		}
		
		int getY(){
			return year;
		}
		
		int getM(){
			return month;
		}
		
		int getD(){
			return day;
		}
		
	private:
		int year;
		int month;
		int day;
}; 


class Tle{
	public:
	Tle(){};
	Tle(char type,string number,int state,int y,int m,int d){
		this->type=type;
		this->number=number;
		this->state=state;
		time=new CDate(y,m,d);
		cout<<"Construct a new phone "<<number<<endl;
		print();
		
	}
	
	Tle(Tle & t){
		type ='D';
		number=t.number;
		state=t.state;
		time=new CDate(t.time->getY(),t.time->getM(),t.time->getD());
		cout<<"Construct a copy of phone "<<number<<endl;
		number+="X";
		print();
	}
	
	void stop(){
		state=3;
		cout<<"Stop the phone "<<number<<endl;
		print();
	}
	~Tle(){
		delete time;
	}
	
	private:
		char type;
		string number;
		int state;
		CDate *time;
		
		void print(){
			cout<<"类型=";
			switch(type){
				case 'A':
					cout<<"机构";
					break;
				case 'B':
					cout<<"企业";
					break;
				case 'C':
					cout<<"个人";
					break;
				case 'D':
					cout<<"备份";
					break;
			}
			
			cout<<"||号码="<<number<<"||State=";
			switch(state){
				case 1:
					cout<<"在用";
					break;
				case 2:
					cout<<"未用";
					break;
				case 3:
					cout<<"停用||停机日期=";
					time->print(); 
					break;
					
			}
			cout<<endl;
		}
};

int main(){
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		char type;
		string number;
		int state;
		int a,b,c;
		cin>>type>>number>>state>>a>>b>>c;
		Tle t(type,number,state,a,b,c);
		Tle t_(t);
		t.stop();
		cout<<"----"<<endl;
	}
	return 0;
}
