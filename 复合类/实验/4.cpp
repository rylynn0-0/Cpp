#include<iostream>
using namespace std;

class CDate
{
private:
int year, month, day;
public:
CDate(){
year=0;
month=0;
day=0;}
CDate(int y, int m, int d) { year = y; month = m; day = d; }
bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
int getYear() { return year; }
int getMonth() { return month; }
int getDay() { return day; }
int getDayofYear()        
{
int i, sum=day;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

if (isLeapYear())   a[2]=29;

for(i=1;i<month;i++)   sum +=a[i];

return sum;
}
};


class Soft{
	public:
	
	Soft(string name,char type,char media,int a,int b,int c):name(name),type(type),media(media),time(a,b,c){};
	
	Soft(Soft& src){
		name=src.name;
		time=src.time;
		type='B';
		media='H';
	}
	
	void print(){
		cout<<"name:"<<name<<endl;
		cout<<"type:";
		switch(type){
			case 'O':
				cout<<"original"<<endl;
				break;
			case 'T':
				cout<<"trial"<<endl;
				break;
			case 'B':
				cout<<"backup"<<endl;
				break;
		}
		
		cout<<"media:";
		switch(media){
			case 'D':
				cout<<"optical disk"<<endl;
				break;
			case 'H':
				cout<<"hard disk"<<endl;
				break;
			case 'U':
				cout<<"USB disk"<<endl;
				break;
		}
		
		CDate limit(2015,4,7);
		
		
		
		if(time.getDay()==0&&time.getMonth()==0&&time.getYear()==0 ){
			cout<<"this software has unlimited use"<<endl;
		}else if(time.getYear()<2015||(time.getYear()==2015&&time.getDayofYear()<limit.getDayofYear())){
			cout<<"this software has expired"<<endl;
		} else{
			int sum=0;
			int y=time.getYear(); 
			if(y==2015)sum=time.getDayofYear()-limit.getDayofYear();
			 else{
			 	sum+=365-limit.getDayofYear() ;
			 	sum+=time.getDayofYear() ;
			 	int leap=0;
			 	for(int i=y-1;i>2015;i--){
			 		if((y%4 == 0 && y%100 != 0) || y%400 == 0)leap++;
				 }
			 	sum+=time.getYear()-2016*365+leap;
			 }
			 cout<<"this software is going to be expired in "<<sum<<" days"<<endl;
		}
		
		cout<<endl;
	}
	
	private:
		string name;
		char type;
		char media;
		CDate time;
};

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		
		string str;
		char type;
		char media;
		int a,b,c;
		cin>>str>>type>>media>>a>>b>>c;
		Soft s(str,type,media,a,b,c);
		s.print();
		Soft s1(s);
		s1.print();
		
	}
	return 0;
}
