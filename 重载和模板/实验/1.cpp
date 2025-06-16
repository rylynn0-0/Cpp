#include <iostream>
using namespace std;

class RMB;
ostream & operator <<(ostream &, RMB &);
istream & operator >>(istream &, RMB &);

class RMB{
protected:
	int yuan, jiao, fen;
public:
	RMB(double a=0.0); //ע�⣺��Ĭ��ֵ�ĳ�Ա������������ʵ��ʱ��Ҫȥ��Ĭ��ֵ
	RMB (int, int, int); 
	bool operator > (RMB &);
	friend ostream & operator <<(ostream &, RMB&); //һ��������޻���
	friend istream & operator >>(istream &, RMB&);
	friend RMB operator +(RMB&, RMB&);
};
//��������ඨ������
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
//������
int main()
{	int t;
	double val_yuan; 
	cin>>t;
	while (t--)
	{	cin>>val_yuan;	//����һ��������������1.23 
		RMB r1(val_yuan); //������һ������1.23�������ɶ���r1��1Ԫ2��3�� 
		RMB r2;
		cin>>r2;	//����һ������������������Ԫ���ǡ������� 

		if (r1>r2) 		cout<<r1<<" > "<<r2<<endl;
		else 			cout<<r1<<" <= "<<r2<<endl;
		RMB r3 =r1+r2;
		cout<<r1<<" + "<<r2<<" = "<<r3<<endl;
	}
	return 0;
}

