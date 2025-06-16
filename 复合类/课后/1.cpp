#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//���ʵ����STU�Ķ���
/********** Write your code here! **********/

class STU{
	public:
	STU(string str){
		cout<<"Construct student "<<str<<endl;
		name=str;
	}
	
	STU(STU& s){
		cout<<"Construct student "<<s.name<<"_copy"<<endl;
		name=s.name+"_copy";
	}
	
	~STU(){
		cout<<"Destruct student "<<name<<endl;
	}
	
	private:
		string name;
};


/*******************************************/
//������������
int IDs; //ȫ�ֱ�����������������ʾ
class Tutor {
private:
	STU stu;
public:
	Tutor(STU & s): stu(s)
	{	cout<<"Construct tutor "<<IDs<<endl;	}
	~Tutor()
	{	cout<<"Destruct tutor "<<IDs<<endl;	}

};
void fuc(Tutor x)
{	cout<<"In function fuc()"<<endl;	}

int main()
{	cin>>IDs;
	STU s1("Tom"); //����ѧ������Tom
	Tutor t1(s1);
	IDs++;
	cout<<"Calling fuc()"<<endl;
	fuc(t1);

	return 0;
}
