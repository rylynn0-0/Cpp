#include<bits/stdc++.h>
using namespace std;


class CDate{
	private:
		int year, month, day;
		
	public:

		CDate(int y,int m,int d){
			year=y;
			month=m;
			day=d;
		}

		bool check(){
		    if(month<1||month>12)return 0;
		    else{
		    	int m[]={0,31,30,31,30,31,30,31,31,30,31,30,31};
				if(isLeap())m[2]=29;
				else m[2]=28;
				
				if(day>=1&&day<=m[month])return 1;
				else return 0;
			}
		} //检验日期是否合法

		bool isLeap(){
			int y=(year%100==0)?year/100:year;
			return y%4==0;
		}

		void print(){
			//2006年1月20日
			cout<<year<<"年"<<month<<"月"<<day<<"日"; 
		}
		
		int get_year(){
			return year;
		}
		
		int get_month(){
			return month;
		}
		
		int get_day(){
			return day;
		}

};

class COldID{

	protected:

		 //15位身份证号码，姓名
		string p_id15,p_name; 
		CDate birthday; //出生日期

	public:

		COldID(string id15,string name ,CDate &day):birthday(day){
			p_id15=id15;
			p_name=name;
		
		}

		bool check(){
			int len=p_id15.length();
			if(len!=15)return 0; 
			if( !birthday.check())return 0;
			for(int i=0;i<len;i++){
				if(p_id15[i]<'0'||p_id15[i]>'9')return 0;
			}
			int y=(p_id15[6]-'0')*10+p_id15[7]-'0'+1900;
			int m=(p_id15[8]-'0')*10+p_id15[9]-'0';
			int d=(p_id15[10]-'0')*10+p_id15[11]-'0';
			if(birthday.get_year() !=y||birthday.get_month() !=m||birthday.get_day() !=d)return 0; 
			return 1;
		}

		void print(){}

		~COldID(){}

};

class CNewID:public COldID{
	private:
		string p_18id;
		CDate issueday;
		int validyear;
	public:
		CNewID(string id15,string name ,CDate &day,string id18,int y,int m,int d,int validyear):COldID(id15,name,day),issueday(y,m,d){
			p_18id=id18;
			this->validyear=validyear;
		}
		
		bool check(){
			if(!COldID::check()) return 0;
			if(!issueday.check())return 0;
			if(p_18id.compare(0,5,p_id15,0,5)!=0||p_18id.compare(8,9,p_id15,6,9)!=0)return 0;
			int len=p_18id.length();
			if(len!=18)return 0; 
			for(int i=0;i<18;i++){
				if((p_18id[i]<'0'||p_18id[i]>'9')&&p_18id[17]!='X')return 0;
			}
			if(issueday.get_year()+validyear<2017)return 0;
			if(issueday.get_year()+validyear==2017&&issueday.get_month()<5)return 0;
			if(issueday.get_year()+validyear==2017&&issueday.get_month()==5&&issueday.get_day()<10)return 0;
			
			int num[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
			char c[11]={'1','0','X','9','8','7','6','5','4','3','2'};
			long sum=0;
			for(int i=0;i<17;i++){
				sum+=(p_18id[i]-'0')*num[i];
			}
			sum%=11;
			if(p_18id[17]!=c[sum])return 0;
			
			return 1;
		
		}
		
		void print(){
			cout<<p_name<<endl;
			if(check()){
				cout<<p_18id<<" ";
				issueday.print() ;
				cout<<" ";
				if(validyear>=100){
					cout<<"长期"<<endl; 
				}
				else cout<<validyear<<"年"<<endl;
			}
			else cout<<"illegal id"<<endl;
		}
		
};

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string name;
		int y,m,d,va;
		cin>>name>>y>>m>>d;
		CDate day(y,m,d);
		string id15,id18;
		cin>>id15>>id18>>y>>m>>d>>va;
		CNewID p(id15,name,day,id18,y,m,d,va);
		p.print() ;
	}
	
	return 0;
}
