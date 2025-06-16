#include<iostream>
using namespace std;

class Player{
	protected:
		string name;
		int height;
		int weight;
	public:
		Player(string n,int h,int w):name(n),height(h),weight(w){}
		
		void display(){
			cout<<"Player:"<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"height:"<<height<<endl;
			cout<<"weight"<<weight<<endl;
		}
};

class MVP:virtual public Player{
	protected:
		int year;
	public:
		MVP(string n,int h,int w,int year):Player(n,h,w),year(year){}
		
		void display(){
			cout<<"MVP:"<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"height:"<<height<<endl;
			cout<<"weight:"<<weight<<endl;
			cout<<"reward:win the MVP reward in "<<year<<endl;
		}
};

class DPOY:virtual public Player{
	protected:
		int year;
	public:
		DPOY(string n,int h,int w,int year):Player(n,h,w),year(year){}
		
		void display(){
			cout<<"DPOY:"<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"height:"<<height<<endl;
			cout<<"weight:"<<weight<<endl;
			cout<<"reward:win the DPOY reward in "<<year<<endl;
		}
};	

class HallOfFame:public MVP,public DPOY{
	public:
		HallOfFame(string n,int h,int w,int y1,int y2):Player(n,h,w),MVP(n,h,w,y1),DPOY(n,h,w,y2){}
		
		void display(){
			Player::display() ;
			cout<<endl;
			MVP::display();
			cout<<endl;
			DPOY::display() ;
			
			cout<<endl;
			
			cout<<"Hall of fame:"<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"height:"<<height<<endl;
			cout<<"weight:"<<weight<<endl;
			cout<<"reward1:win the MVP reward in "<<MVP::year<<endl;
			cout<<"reward2:win the DPOY reward in "<<DPOY::year<<endl;
		}	
};

int main(){
	string name;
	int h,w,y1,y2;
	cin>>name>>h>>w>>y1>>y2;
	HallOfFame hof(name,h,w,y1,y2);
	hof.display();
	return 0;
}
