#include<iostream>
#include<cstring>
using namespace std;
class CDate

{

private:

int year, month, day;

public:
CDate(){}
CDate(int y,int m,int d):year(y),month(m),day(d){
};

bool check(){
	int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeap())days[2]++;
	
	if(days[month]<day)return false;
	if(month<=0||month>12)return false;
	return true;
}; //检验日期是否合法

bool isLeap(){
	return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}

int gety(){
	return year;
}

int getm(){
	return month;
}

int getd(){
	return day;
}

void print(){
	cout<<year<<"年"<<month<<"月"<<day<<"日";
}

};

class CStudentID

{

private:

char *p_id, *p_name; //身份证号码，姓名

CDate birthday; //出生日期

int registered; //登记否

public:

CStudentID(char *p_idval, char *p_nameval, CDate &day){
	registered=1;
	p_name=new char[10];
	p_id=new char[20];
	birthday=day;
	strcpy(p_name,p_nameval);
	strcpy(p_id,p_idval);
	int len_id=strlen(p_idval);
	int len_name=strlen(p_nameval);
	if(!day.check()){
		registered=0;
	}
	if(len_id!=15&&len_id!=18){
		registered=0;
	}
	for(int i=0;i<=len_id;i++){
		p_id[i]=p_idval[i];
	}
	for(int i=0;i<=len_name;i++){
		p_name[i]=p_nameval[i];
	}
	string str="1234567890X";
	for(int i=0;i<len_id;i++){
		if(str.find(p_id[i])>10){
			registered=0;
		}
	}
	
	if(len_id==15){
		int y=(p_id[6]-'0')*10+(p_id[7]-'0');
		y+=1900;
		int m=(p_id[8]-'0')*10+(p_id[9]-'0');
		int d=(p_id[10]-'0')*10+(p_id[11]-'0');
		if(y!=birthday.gety()||m!=birthday.getm()||d!=birthday.getd()){
			registered=0;
		}
	}
	
	if(len_id==18){
		int y=(p_id[8]-'0')*10+(p_id[9]-'0');
		y+=1900;
		int m=(p_id[10]-'0')*10+(p_id[11]-'0');
		int d=(p_id[12]-'0')*10+(p_id[13]-'0');
		if(y!=birthday.gety()||m!=birthday.getm()||d!=birthday.getd()){
			registered=0;
		}
	}
	
	if(len_id==18 && jianyan()!=p_id[17]){
		registered=0;
	}
	if(registered==0){
		cout<<p_name<<" illegal id"<<endl;
	}
	else{
		cout<<p_name<<" ";
		birthday.print();
		cout<<" "<<p_id<<endl;
	}
	
} //构造函数，若:日期非法;日期与id日期不符;id有非法字符;id不是15位或18位;id是18位但检验码不对,则输出"illegal id"并置registered=0。否则输出对象的属性并置registered=1.

CStudentID(const CStudentID &r){
	p_name=new char[10];
	p_id=new char[20];
	birthday=r.birthday;
	strcpy(p_name,r.p_name);
	strcpy(p_id,r.p_id);
	int len_id=strlen(p_id);
	int len_name=strlen(p_name);
	
	if(len_id==15){
		for(int i=0;i<9;i++){
			p_id[16-i]=p_id[14-i];
		}
		p_id[6]='1';
		p_id[7]='9';
		p_id[18]='\0';
		p_id[17]=jianyan();
		
	}
	
	cout<<p_name<<" ";
	birthday.print();
	cout<<" "<<p_id<<endl;
} //拷贝构造函数，若r.p_id为15位则升到18位(加年份的19和校验位)

bool checked() { return registered; }

char jianyan(){
	int s[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	unsigned long long sum=0;
	for(int i=0;i<17;i++){
		sum+=((p_id[i]-'0')*(s[i]));
	}
	sum%=11;
	string str="10X98765432";
	return str[sum];
}

~CStudentID(){
	delete p_id;
	delete p_name;
}

};

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int y,m,d;
		cin>>y>>m>>d;
		char*p_name=new char[10];
		char*p_id=new char [20];
		cin>>p_name>>p_id;
		CDate now(y,m,d);
		CStudentID c(p_id,p_name,now);
		if(c.checked()){
			CStudentID c_(c);
		}
	}
	return 0;
}
