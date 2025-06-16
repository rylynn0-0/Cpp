#include <iostream>
using namespace std;

class CDate{
	public:
		CDate(int a,int b,int c):year(a),month(b),day(c){}
		CDate(const CDate& cd){
			year=cd.year;
			month=cd.month;
			day=cd.day+1;
			int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
			if(check(year))days[2]++;
			if(day>days[month]){
				day=1;
				month++;
			}
			if(month>12){
				year++;
				month=1;
			}
		}
		
		int get_m(){
		return month;
		}
		
		int get_d(){
			return day;
		}
		
		void print(){
			cout<<year<<"/"<<month<<"/"<<day<<endl;
		}
		
	private:
		bool check(int y){
			int x=(y%100==0)?y%100:y;
			return x%4==0;
		}
		int year;
		int month;
		int day;
}; 

class VIP{
	public:
		VIP(int id,int a,int b,int c):id(id),birth(a,b,c){};
		
		double Discount(CDate & today){
			if(today.get_m()==birth.get_m()&&today.get_d()==birth.get_d())return 0.5;
			else return 0.95;
		}
		
		int get_id(){
			return id;
		}
	private:
		int id;
		CDate birth;
};


int main(){
	int a,b,c;
	cin>>a>>b>>c;
	CDate today(a,b,c);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int id,money;
		cin>>id>>a>>b>>c;
		VIP vip(id,a,b,c);
		cin>>money;
		cout<<vip.get_id()<<"'s consumption is "<<(int)(money*vip.Discount(today))<<endl; 
	}
}


