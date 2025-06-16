#include<iostream>
#include<cmath>
using namespace std;

class Group
{
public:
	virtual int add(int x, int y)=0;//输出加法的运算结果
	virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class GroupA:public Group{
	public:
		virtual int add(int x, int y){
		return x+y;
		}
		
		virtual int sub(int x, int y){
			return x-y;
		}
};

class GroupB:public Group{
	public:
		virtual int add(int x, int y){
		return x+y;
		}
		
		int f(int x,int i){
			return x/(int)pow(10,i)%10;
		}
		
		virtual int sub(int x, int y){
			int num=x-y;
			int len=log(y)/log(10)+1;
			for(int i=0;i<len;i++){
				if(f(x,i)<f(y,i))num+=pow(10,i+1);
				
			}
			return num;
		}
};

class GroupC:public Group {
	public:
		
		int f(int x,int i){
			return x/(int)pow(10,i)%10;
		}
		
		virtual int add(int x, int y){
		int num=x+y;
		int len=log(y)/log(10)+1;
		for(int i=0;i<len;i++){
			if(f(x,i)+f(y,i)>=10)num-=pow(10,i+1);
		}
		return num;
		}
		
		virtual int sub(int x, int y){
			int num=x-y;
			int len=log(y)/log(10)+1;
			for(int i=0;i<len;i++){
				if(f(x,i)<f(y,i))num+=pow(10,i+1);
				
			}
			return num;
		}
};

int main(){
	int n;
	cin>>n;
	int x,y,f;
	char c;
	Group *p;
	for(int i=0;i<n;i++){
		cin>>f>>x>>c>>y;
		if(f==1){
			p=new GroupA;
			cout<<((c=='+')?p->add(x,y):p->sub(x,y) )<<endl;
		}
		else if(f==2){
			p=new GroupB;
		cout<<	((c=='+')?p->add(x,y):p->sub(x,y) )<<endl;
		}
		else if(f==3){
			p=new GroupC;
			cout<<((c=='+')?p->add(x,y):p->sub(x,y) )<<endl;
		}
	}
	return 0;
}
