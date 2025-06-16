#include<iostream>
#include<iomanip>


class Per{
	public:
		void set(int id,int n,double price){
			this->id=id;
			num+=n;
			if(n>10){
				discount=0.98;
			}else discount=1;
			sum+=price*n*discount;
		}
		
		static void display(){
			std::cout<<"num="<<num<<std::endl;
			std::cout<<"sum="<<std::fixed<<std::setprecision(2)<<sum<<std::endl;
			std::cout<<"average="<<std::fixed<<std::setprecision(2)<<average()<<std::endl;
		}
		
	private:
		int id;
		int cout;
		double price;
		static double discount;
		static double sum;
		static int num;
		static double average(){
			return sum/num;
		}
};

double Per::discount=1;
double Per::sum=0;
int Per::num=0;

int main(){
	Per p[3];
	for(int i=0;i<3;i++){
		int id;
		int n;
		double price;
		std::cin>>id>>n>>price;
		p[i].set(id,n,price);
	}
	p[0].display() ;
	return 0;
}
