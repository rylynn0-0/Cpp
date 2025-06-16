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
			//��Ա����:Michael ���:198 ����:96
			cout<<"��Ա����:"<<name<<" ���:" <<height<<" ����:"<<weight<<endl;
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
			//�÷�>25������>6������>6��
			if(score>25&&lanban>6&&zhugong>6)is_MVP=1;
			else is_MVP=0;
		}
		
		void display(){
			//MVP���:2014 �÷�:26.6 ����:8.1 ����:6.2
			if(is_MVP){
				cout<<"MVP���:"<<year<<" �÷�:"<<fixed<<setprecision(1)<<score<<" ����:"<<lanban<<" ����:"<<zhugong<<endl;
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
				//DPOY���:2016 ��ñ:2.7 ����:12.3 ����:1.8
				cout<<"DPOY���:"<<year<<" ��ñ:"<<fixed<<setprecision(1)<<gaimao<<" ����:"<<lanban<<" ����:"<<qiangduan<<endl;
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
