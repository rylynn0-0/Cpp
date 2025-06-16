#include <iostream>
using namespace std;

class RMB;
ostream & operator <<(ostream &, RMB &);
istream & operator >>(istream &, RMB &);

class RMB{
protected:
	int yuan, jiao, fen;
public:
	RMB(double a=0.0); //注意：带默认值的成员函数，在类外实现时，要去掉默认值
	RMB (int, int, int); 
	bool operator > (RMB &);
	friend ostream & operator <<(ostream &, RMB&); //一行输出，无换行
	friend istream & operator >>(istream &, RMB&);
	friend RMB operator +(RMB&, RMB&);
};
//完成以下类定义的填空
/********** Write your code here! **********/

RMB::RMB(double a){
	a+=0.005;
	yuan=(int)a;
	jiao=(int)(a*10)%10;
	fen=(int)(a*100)%10;
} 

RMB::RMB(int y,int j,int f):yuan(y),jiao(j),fen(f){}

bool RMB::operator >(RMB & r){
	double n1=r.yuan+r.fen*0.01+r.jiao*0.1;
	double n=yuan+fen*0.01+jiao*0.1;
	return n>n1;
}

istream &operator >>(istream & s,RMB &r){
	s>>r.yuan>>r.jiao>>r.fen;
	return s;
} 

ostream &operator <<(ostream & s,RMB &r){
	s<<r.yuan<<"yuan"<<r.jiao<<"jiao"<<r.fen<<"fen";
	return s;
} 

RMB operator+(RMB&r1,RMB&r2){
	double sum=r1.yuan+r2.yuan+r1.jiao*0.1+r2.jiao*0.1+r1.fen*0.01+r2.fen*0.01;
	return RMB(sum);
}

/*******************************************/
//主函数
int main()
{	int t;
	double val_yuan; 
	cin>>t;
	while (t--)
	{	cin>>val_yuan;	//输入一个浮点数，例如1.23 
		RMB r1(val_yuan); //例如上一行输入1.23，则生成对象r1是1元2角3分 
		RMB r2;
		cin>>r2;	//输入一行三个整数参数，按元、角、分输入 

		if (r1>r2) 		cout<<r1<<" > "<<r2<<endl;
		else 			cout<<r1<<" <= "<<r2<<endl;
		RMB r3 =r1+r2;
		cout<<r1<<" + "<<r2<<" = "<<r3<<endl;
	}
	return 0;
}

