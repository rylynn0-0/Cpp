#include<iostream>
using namespace std;
#define SET(x,type) void set_#x(type x){this->x=x}

class Vehicle{
	protected:
	int weight;
	public:
		Vehicle(int weight):weight(weight){
		cout<<"载入Vehicle类构造函数"<<endl;
		}
		
		void setWeight(int weight){
			this->weight=weight;
			cout<<"重新设置重量"<<endl;
		}
		
		void display(){
			cout<<"重量："<<weight<<"吨";
		}
	
};

class Car:virtual public Vehicle{
	protected:
		int aird;
	public:
		Car(int w,int a):Vehicle(w),aird(a){
			cout<<"载入Car类构造函数"<<endl;
		}
		
		void setAird(int a){
			aird=a;
			cout<<"重新设置空气排量"<<endl;
		}
		
		void display(){
			cout<<"空气排量："<<aird<<"CC";
		}
};

class Boat:virtual public Vehicle{
	protected:
	float tonnage;
	public:
		Boat(int w,float t):Vehicle(w),tonnage(t){
			cout<<"载入Boat类构造函数"<<endl;
		}
		
		void setTonnage(float t){
			tonnage=t;
			cout<<"重新设置排水量"<<endl;
		}
		
		void display(){
			cout<<"排水量："<<tonnage<<"吨";
		}
};

class AmphibianCar:public Car,public Boat{
	public:
		AmphibianCar(int w,int a,float t):Vehicle(w),Car(w,a),Boat(w,t){
			cout<<"载入AmphibianCar类构造函数"<<endl;
		}
		
		void set(int w,int a,float t){
			setWeight(w);
			setAird(a);
			setTonnage(t);
		}
		
		void display(){
			Vehicle::display();
			cout<<"，";
			Car::display();
			cout<<"，";
			Boat::display();
			cout<<endl;
		}
};

int main(){
	int w,a;
	float t;
	cin>>w>>a>>t;
	AmphibianCar abc(w,a,t);
	abc.display();
	cin>>w>>a>>t;
	abc.set(w,a,t);
	abc.display();
	return 0;
}
