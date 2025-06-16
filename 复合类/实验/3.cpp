#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class CTelNumber{
	public:
		CTelNumber(char *p){
			num=new char[10];
			int i=0;
			while(*(p+i)){
				*(num+i)=*(p+i);
				i++;
			}
			*(num+i)='\0';
		}
		~CTelNumber(){
			delete num;
		}
		CTelNumber(const CTelNumber& src){
			num=new char[10];
			int i=0;
			string s1="234";
			string s2="5678";
			if(s1.find(src.num[0])<=2)num[0]='8';
			if(s2.find(src.num[0])<=3)num[0]='2';
			
		
			
			while(src.num[i]){
				num[i+1]=src.num[i];
				i++;
			}
			num[i+1]='\0';
			
		}
		
		void print(){
			cout<<num<<endl;
		}
		bool check(){
			int len=strlen(num);
			string str1="2345678";
			string str="1234567890";
			if(len!=7)return 0;
			if(str1.find(num[0])>6)return 0;
			for(int i=0;i<len;i++){
				if(str.find(num[i])>9)return 0;
			}
			return 1;
		}
		
	private:
		char*num;
};

int main(){
	int n;
	cin>>n;
	for(int o=0;o<n;o++){
		char *p=new char[10];
		cin>>p;
	
		CTelNumber ctn(p);
		if(ctn.check()){
			CTelNumber ctn_(ctn);
			ctn_.print();
		}
		else{
			cout<<"Illegal phone number"<<endl;
		}
	}
	return 0;
}
