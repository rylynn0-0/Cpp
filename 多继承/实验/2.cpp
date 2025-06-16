#include<iostream>
using namespace std;

class CVehicle{
	protected:
	int max_speed;
	int speed;
	int weight;
	public:
		CVehicle(int m,int s,int w):max_speed(m),speed(s),weight(w){}
		void display(){
			cout<<"Vehicle:"<<endl;
			cout<<"max_speed:"<<max_speed<<endl;
			cout<<"speed:"<<speed<<endl;
			cout<<"weight:"<<weight<<endl;
		}
};

class CBicycle:virtual public CVehicle{
	protected:
		int height;
	public:
		CBicycle(int m,int s,int w,int h):CVehicle(m,s,w),height(h){}
		void display(){
			cout<<"Bicycle:"<<endl;
			cout<<"max_speed:"<<max_speed<<endl;
			cout<<"speed:"<<speed<<endl;
			cout<<"weight:"<<weight<<endl;
			cout<<"height:"<<height<<endl;
		}
};

class CMotocar:virtual public CVehicle{
	protected:
		int seat_num;
	public:
		CMotocar(int m,int s,int w,int sn):CVehicle(m,s,w),seat_num(sn){}
		void display(){
			cout<<"Motocar:"<<endl;
			cout<<"max_speed:"<<max_speed<<endl;
			cout<<"speed:"<<speed<<endl;
			cout<<"weight:"<<weight<<endl;
			cout<<"seat_num:"<<seat_num<<endl;
		}
};

class CMotoCycle:public CBicycle,public CMotocar{
	public:
		CMotoCycle(int m,int s,int w,int h,int sn):CVehicle(m,s,w),CMotocar(m,s,w,sn),CBicycle(m,s,w,h){}
		void display(){
			CVehicle::display() ;
			cout<<endl;
			CBicycle::display();
			cout<<endl;
			CMotocar::display() ;
			cout<<endl;
			
			cout<<"Motocycle:"<<endl;
			cout<<"max_speed:"<<max_speed<<endl;
			cout<<"speed:"<<speed<<endl;
			cout<<"weight:"<<weight<<endl;
			cout<<"height:"<<height<<endl;
			cout<<"seat_num:"<<seat_num<<endl;
		}
};

int main(){
	int max_speed,speed,weight,height,seat_num;
	cin>>max_speed>>speed>>weight>>height>>seat_num;
	CMotoCycle c( max_speed,speed,weight,height,seat_num);
	c.display();
	return 0;
}
