#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Student{
	protected:
		string num;
		string name;
	public:
		Student(string num,string name):num(num),name(name){}
		
		virtual void display()=0;
};

class GroupA:public Student{
	protected:
	int s1,s2;
	
	public:
		static int max_m;
		GroupA(string num,string name,int s1,int s2):Student(num,name),s1(s1),s2(s2){
		max_m=max(s1+s2,max_m);
		}
		
		virtual void display(){
			if(s1+s2==max_m){
				cout<<num<<" "<<name<<endl;
			}
		}
};

class GroupB:public GroupA{
	char gs;
	public:
		GroupB(string num,string name,int s1,int s2,char gs):GroupA(num,name,s1,s2),gs(gs){
		max_m=max(s1+s2,max_m);
		}
		
		virtual void display(){
			if(s1+s2==max_m||(s1+s2)*10>=max_m*7&&gs=='A'){
				cout<<num<<" "<<name<<endl;
			}
		}
};

class GroupC:public GroupA{
	int s3,s4,s5;
	public:
		GroupC(string num,string name,int s1,int s2,int s3,int s4,int s5):GroupA(num,name,s1,s2),s3(s3),s4(s4),s5(s5){
		}
		
		virtual void display(){
			double x=(s1+s2+s3+s4+s5)/5.0;
			double y=max_m/2.0*0.9;
			if(x>=y){
				cout<<num<<" "<<name<<endl;
				
			}
		}
};
int GroupA::max_m=0;
int main()
{
    const int Size = 50;
    string num, name;
    int i, ty, s1, s2, s3, s4, s5;
    char gs;
    Student *pS[Size];
    int count = 0;
    for (i = 0; i < Size; i++)
    {
        cin >> ty;
        if (ty == 0)
            break;
        cin >> num >> name >> s1 >> s2;
        switch (ty)
        {
        case 1:
            pS[count++] = new GroupA(num, name, s1, s2);
            break;
        case 2:
            cin >> gs;
            pS[count++] = new GroupB(num, name, s1, s2, gs);
            break;
        case 3:
            cin >> s3 >> s4 >> s5;
            pS[count++] = new GroupC(num, name, s1, s2, s3, s4, s5);
            break;
        }
    }
    for (i = 0; i < count; i++)
    {
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}
