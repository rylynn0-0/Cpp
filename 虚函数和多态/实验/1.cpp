#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Pet { //���࣬Ҳ�ǳ�����
protected:
	string kind; //��������
	int ID;	//�����ţ��̶�����Ϊ5λ������	
public:
	Pet(): kind("unset"), ID(-1) { }
	virtual void set(string tk, int ti)=0; //��������������ͺͱ��
	virtual void print()	{ cout<<"NONE"<<endl; }
};

//�����Cat����Dog�����
/********** Write your code here! **********/
class Cat:public Pet{
	string name ,food;
	public:
		Cat(string name,string food):name(name),food(food){}
		
		void set(string tk,int ti){
			kind =tk;
			ID=ti+10000;
		}
		
		void print(){
			cout<<"Cat's ID="<<ID<<endl;
			cout<<name<<" likes "<<food<<endl;
		}
};

class Dog:public Pet{
	string name ;
	int size;
	public:
		Dog(string name,int size):name(name),size(size){}
		
		void set(string tk,int ti){
			kind =tk;
			ID=ti+20000;
		}
		
		void print(){
			string S;
			if(size==1)S="small";
			else if(size==2)S="medium";
			else S="big";
			cout<<kind<<"'s ID="<<ID<<endl;
			cout<<name<<" is "<<S<<endl;
		}
};

/*******************************************/
//�������������ȫ�ֺ������£�
void print_pet(Pet &pr)
{	pr.print();	}

int main()
{	string tk, ts, tf;
	int t, ti, tt;
	char ptype;
	cin>>t;
	while (t--)
	{	cin>>ptype;
		if (ptype=='C')
		{	cin>>tk>>ti>>ts>>tf; //���͡���š�������ʳ��
			Cat cc(ts, tf);
			cc.set(tk, ti);
			print_pet(cc);
		}
		if (ptype=='D')
		{	cin>>tk>>ti>>ts>>tt; //���͡���š�������Ȯ��С
			Dog dd(ts, tt);
			dd.set(tk, ti);
			print_pet(dd);
		}
	}
	
	return 0;
}

