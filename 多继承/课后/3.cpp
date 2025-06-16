#include<iostream>
using namespace std;

class Node2D{
	protected:
		string location;
	public:
		Node2D(string l):location(l){}
		
};

class Body:virtual public Node2D{
	protected:
		int health;
		int defense;
	public:
		Body(string l,int h,int d):Node2D(l),health(h),defense(d){}
		
};

class Weapon:virtual public Node2D{
	protected:
		string w_name;
		int damage;
	public:
		Weapon(string l,string w,int d):Node2D(l),w_name(w),damage(d){}
		
};

class Player:public Body,public Weapon{
	private:
		string name;
	public:
		Player(string l,int h,int de,string w,int da,string n):Node2D(l),Body(l,h,de),Weapon(l,w,da),name(n){}
		
		friend int attack(Player &p1,Player&p2){
			cout<<p1.name<<" deal "<<p1.damage-p2.defense<<" damage to "<<p2.name<<endl;
			p2.health -=p1.damage-p2.defense;
			if(p2.health <=0){
				cout<<p1.name<<" defeated "<<p2.name<<" by "<<p1.w_name<<" in "<<p1.location<<endl;
				return 0;
			}else{
				cout<<p2.name<<" still have "<<p2.health <<" health"<<endl;
				cout<<endl;
				return 1;
			}
		}
};

int main(){
	string l;
	cin>>l;
	string n,w;
	int h,de,da;
	cin>>n>>h>>de>>w>>da;
	Player p1(l,h,de,w,da,n);
	cin>>n>>h>>de>>w>>da;
	Player p2(l,h,de,w,da,n);
	int flag=attack(p1,p2);
	bool x=0;
	while(flag!=0){
		flag=(x==0)?attack(p2,p1):attack(p1,p2) ;
		x=!x;
	} 
	
	
	return 0;
}
