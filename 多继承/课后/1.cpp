#include<iostream>
using namespace std;
#define SET(x,type) void set_#x(type x){this->x=x}

class Vehicle{
	protected:
	int weight;
	public:
		Vehicle(int weight):weight(weight){
		cout<<"����Vehicle�๹�캯��"<<endl;
		}
		
		void setWeight(int weight){
			this->weight=weight;
			cout<<"������������"<<endl;
		}
		
		void display(){
			cout<<"������"<<weight<<"��";
		}
	
};

class Car:virtual public Vehicle{
	protected:
		int aird;
	public:
		Car(int w,int a):Vehicle(w),aird(a){
			cout<<"����Car�๹�캯��"<<endl;
		}
		
		void setAird(int a){
			aird=a;
			cout<<"�������ÿ�������"<<endl;
		}
		
		void display(){
			cout<<"����������"<<aird<<"CC";
		}
};

class Boat:virtual public Vehicle{
	protected:
	float tonnage;
	public:
		Boat(int w,float t):Vehicle(w),tonnage(t){
			cout<<"����Boat�๹�캯��"<<endl;
		}
		
		void setTonnage(float t){
			tonnage=t;
			cout<<"����������ˮ��"<<endl;
		}
		
		void display(){
			cout<<"��ˮ����"<<tonnage<<"��";
		}
};

class AmphibianCar:public Car,public Boat{
	public:
		AmphibianCar(int w,int a,float t):Vehicle(w),Car(w,a),Boat(w,t){
			cout<<"����AmphibianCar�๹�캯��"<<endl;
		}
		
		void set(int w,int a,float t){
			setWeight(w);
			setAird(a);
			setTonnage(t);
		}
		
		void display(){
			Vehicle::display();
			cout<<"��";
			Car::display();
			cout<<"��";
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
