#include<iostream>
#include<iomanip>
using namespace std;

class Car{
	protected:
		string name;
		int rent;
		
	public:
		Car(string name,int rent):name(name),rent(rent){}
		static int sum_people;
		static float sum_weight;
		static int sum_rent;
		int get_rent(){
			return rent;
		}
};

class Bus:virtual public Car{
	protected :
	int num;
	
	public:
		Bus(string name,int num,int rent):Car(name,rent),num(num){}
		int get_num(){
			return num;
		}
};

class Truck:virtual public Car{
	protected :
	float num;
	
	public:
		Truck(string name,float num,int rent):Car(name,rent),num(num){}
		float get_num(){
			return num;
		}
};

class Pika:public Bus,public Truck{
	public:
		Pika(string name,int ren_num,float huo_num,int rent):Car(name,rent),Bus(name,ren_num,rent),Truck(name,huo_num,rent){}
		
		int get_ren_num(){
			return  Bus::get_num();
		}
		
		float get_huo_num(){
			return Truck::get_num();
		}
};

int Car::sum_people=0;
int Car::sum_rent=0;
float Car::sum_weight =0.0;

int main(){
	string bus_name[5]={"A","B","C","D","E"};
	int bus_num[5]={5,5,5,51,55};
	int bus_rent[5]={800,400,800,1300,1500};
	
	string pika_name[2]={"F","G"};
	int pika_num[2]={5,5};
	float pika_huo_num[2]={0.45,2.0};
	int pika_rent[2]={500,450};
	
	string truck_name[3]={"H","I","J"};
	float truck_num[3]={3,25,35};
	int truck_rent[3]={200,1500,2000};
	
	
	
	Bus **bus =new Bus*[5];
	for(int i=0;i<5;i++){
		bus[i]=new Bus(bus_name[i],bus_num[i],bus_rent[i]);
	}
	
	Pika** pika=new Pika*[2];
	for(int i=0;i<2;i++){
		pika[i]=new Pika(pika_name[i],pika_num[i],pika_huo_num[i],pika_rent[i]);
	}
	
	Truck ** truck=new Truck*[3];
	for(int i=0;i<3;i++){
		truck[i]=new Truck(truck_name[i],truck_num[i],truck_rent[i]);
	}
	
	int flag;
	cin>>flag;
	if(flag==1){
		
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int x,day;
			cin>>x>>day;
			
			if(0<x&&x<=5){
				int idex=x-1;
				Car::sum_people+=bus[idex]->get_num()*day;
				Car::sum_rent +=bus[idex]->get_rent()*day;
				
			} 
			if(6<=x&&x<=7){
				
				int idex=x-6;
				Car::sum_people +=pika[idex]->get_ren_num()*day;
				Car::sum_weight+=pika[idex]->get_huo_num()*day ;
				Car::sum_rent +=pika[idex]->get_rent() *day;
				
			}
			
			 if(8<=x&&x<=10){
			 	int idex=x-8;
				Car::sum_weight+=truck[idex]->get_num()*day ;
				Car::sum_rent +=truck[idex]->get_rent() *day;
				
			}
			
			
		}
		
		
	}
	
	cout<<Car::sum_people <<" "<<fixed<<setprecision(2)<<Car::sum_weight <<" "<<Car::sum_rent <<endl;
	for(int i=0;i<5;i++){
		delete bus[i];
	} delete []bus;
	
	for(int i=0;i<2;i++){
		delete pika[i];
	} delete []pika;
	
	for(int i=0;i<3;i++){
		delete truck[i];
	} delete []truck;
	
	
	return 0;
}
