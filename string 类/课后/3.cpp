#include<bits/stdc++.h>
using namespace std;

class Player{
	protected:
		string name;
		double height;
		double weight;
	public:
		Player(){}
		Player(string name,double height,double weight){
			this->name=name;
			this->height=height;
			this->weight=weight;
		}
		
		void set(string name,double height,double weight){
			this->name=name;
			this->height=height;
			this->weight=weight;
		}
		
		void display(){
			//球员姓名:Michael 身高:198 体重:96
			cout<<"球员姓名:"<<name<<" 身高:" <<height<<" 体重:"<<weight<<endl;
		}
		
};

class MVP:public Player{
	int year;
	double score;
	double lanban;
	double zhugong;
	int is_MVP;
	public:
		MVP(){}
		void set(string name,double height,double weight,int year){
			Player::set(name,height,weight);
			this->year=year;
			cin>>score>>lanban>>zhugong;
			//得分>25，篮板>6，助攻>6；
			if(score>25&&lanban>6&&zhugong>6)is_MVP=1;
			else is_MVP=0;
		}
		
		void display(){
			//MVP年份:2014 得分:26.6 篮板:8.1 助攻:6.2
			if(is_MVP){
				cout<<"MVP年份:"<<year<<" 得分:"<<fixed<<setprecision(1)<<score<<" 篮板:"<<lanban<<" 助攻:"<<zhugong<<endl;
			}
		}
		double get_lanban(){
			return lanban;
		}
		
};

class DPOY:public Player{
	int year;
	double lanban;
	double qiangduan;
	double gaimao;
	int is_DPOY;
	public:
		DPOY(){}
		void set(string name,double height,double weight,int year,double lanban){
			Player::set(name,height,weight);
			this->year=year;
			this->lanban=lanban;
			cin>>gaimao>>qiangduan;
			if(lanban>12&&gaimao>2.5&&qiangduan>1.5)is_DPOY=1;
			else is_DPOY=0;
		}
		void display(){
			if(is_DPOY){
				//DPOY年份:2016 盖帽:2.7 篮板:12.3 抢断:1.8
				cout<<"DPOY年份:"<<year<<" 盖帽:"<<fixed<<setprecision(1)<<gaimao<<" 篮板:"<<lanban<<" 抢断:"<<qiangduan<<endl;
			}
		}
};
int main(){
	string name;
	double height;
	double weight;
	cin>>name>>height>>weight;
	Player player(name,height,weight);
	MVP mvp[12];
	DPOY dpoy[12];
	for(int year=2010;year<=2021;year++){
		mvp[year-2010].set(name,height,weight,year);
		dpoy[year-2010].set(name,height,weight,year,mvp[year-2010].get_lanban());
	}
	player.display() ;
	for(int i=0;i<12;i++){
		mvp[i].display() ;
	}
	for(int i=0;i<12;i++){
		dpoy[i].display();
	}
	return 0;
}
