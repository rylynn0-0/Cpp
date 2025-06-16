#include<iostream>
using namespace std;

class P{
	public:
		P(){}
		P(int PID,string user,char RorW,int time){
			this->user=user;
			this->PID=PID;
			this->RorW=RorW;
			this->time=time;
			int x=0;
		}
		
		void show(){
			string str=(RorW=='R')?"reader":"writer";
			cout<<"PID-"<<PID<<" User-"<<user<<" as a "<<str<<" used time-"<<time<<endl;
		}
		
		static void add_read_time(int t){
			read_sum_time+=t;
		}
		
		static void add_write_time(int t){
			write_sum_time+=t;
		}
		
		static void set_max_write(int t){
			max_write_time=max(t,max_write_time);
		}
		
		static void set_max_read(){
			max_read_num=max(max_read_num,x);
		}
		
		static void show_static(){
			max_read_num+=1;
			cout<<"Total readers' time-"<<read_sum_time<<" with maximum "<<max_read_num<<" readers at the same time"<<endl;
			cout<<"Total writers' time-"<<write_sum_time<<" with maximum writing time "<<max_write_time<<endl;
		}
		
		void set_x(int t){
			x=t;
		}
		
	private:
		int PID;
		string user;
		char RorW;
		int time;
		static int x;
		static int read_sum_time;
		static int write_sum_time;
		static int max_write_time;
		static int max_read_num;
		static int pre_r;
};
int P::x=0; 
int P::read_sum_time=0;
int P::write_sum_time=0;
int P::max_write_time=0;
int P::max_read_num=0;
int P::pre_r=0;


int main(){
	int id;
	string name;
	char type;
	int t;
	cin>>id;
	int f=0;
	int X=0;
	while(id!=0){
		cin>>name>>type>>t;
		
		P p(id,name,type,t);
		p.show();
		if(type=='R'){
			p.add_read_time(t);
			if(f==1){
				X+=1;
			
			}else{
				X=0;
			}
				p.set_x(X);
			f=1;
			p.set_max_read();
		}
		else{
			f=0;
			p.add_write_time(t);
			p.set_max_write(t);  
		}
		
		cin>>id;
	}
	cout<<endl;
	
	P::show_static();
	
	return 0;
}
