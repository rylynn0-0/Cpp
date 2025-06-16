#include<iostream>
#include<cstring>
using namespace std;

class Str{
	int length;
	char *p;
	
	public:
	Str(){}
	Str(char *s){
		length=0;
	    while(s[length])length++;
	    p=new char[length];
		for(int i=0;i<length;i++){
			p[i]=s[i];
		}
		p[length]='\0';
	}
	
	Str operator+(Str &S){
		int l=length+S.length;
		char *s=new char[l+5];
		for(int i=0;i<length;i++){
			s[i]=p[i];
		}
		for(int i=length;i<l;i++){
			s[i]=S.p[i-length];
		}
		s[l]='\0';
	
		return Str(s);
	}
	
	Str operator-(Str &S){
		char *re=strstr(p,S.p);
		int x=(re-p);
		
		if(!re){
			return Str(p);
		}
		else{
			int index=x;
			char *s=new char[50];
			int j=0;
			
			for(int i=0;i<length;i++){
				if(i>=index&&i<index+S.length)continue;
				s[j]=p[i];
				j++;
			}
			s[length-S.length]='\0';
			return Str (s);
		}
	}
	
	void show(){
		cout<<"length="<<length<<" "<<p<<endl;
	}
};

int main(){
	char *s=new char[50];
	cin.getline(s,50);
	Str s1(s);
	cin.getline(s,50);
	Str s2(s);
	
	(s1+s2).show();
	(s1-s2).show();
	
	return 0;
}
