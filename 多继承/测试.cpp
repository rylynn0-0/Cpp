#include<iostream>
using namespace std;

class A{
	
public:
//void f(){cout<<"A"<<endl;}
int x;
};

class B:public A{
public:
void f(){cout<<"B"<<endl;}
int y;
};

int main(){
A a;
A*p_a=&a;
B b;
B*p_b=&b;
a=b;//���������ֵ���������
//ֻ������Ļ����Ա���ָ�ֵ���������
//a.f();// A
a.x=0;
b.x=1;
b.y=4;
//���Խ�bǿ��ת����A����

(A)b=a;

b.f();
p_a=p_b;
cout<<((B*)p_a)->y<<endl;;
	return 0;
} 
