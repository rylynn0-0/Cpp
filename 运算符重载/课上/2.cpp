#include <iostream>
#include<cstring>
using namespace std;

class Str{
   char *p;
public:
    Str(){p=0;}
    Str(char* s){
      p=new char[strlen(s)+1];
      strcpy(p,s);
    }
    friend bool operator>(Str&,Str&);
    friend bool operator<(Str&,Str&);
    friend bool operator==(Str&,Str&);
    void show(){
       cout<<p<<endl;
    }
};
/********** Write your code here! **********/
bool operator>(Str& a,Str& b){
	int i=0;
	while(a.p[i]&&b.p[i]){
		if(a.p[i]>b.p[i])return true;
		else if(a.p[i]<b.p[i])return false;
		i++;
	}
	if(a.p[i])return true;
	else return false;
}

bool operator<(Str& a,Str& b){
	int i=0;
	while(a.p[i]&&b.p[i]){
		if(a.p[i]<b.p[i])return true;
		else if(a.p[i]>b.p[i])return false;
		i++;
	}
	if(!a.p[i])return true;
	else return false;
}

bool operator==(Str& a,Str& b){
	int i=0;
	while(a.p[i]&&b.p[i]){
		if(a.p[i]>b.p[i])return false;
		else if(a.p[i]<b.p[i])return false;
		i++;
	}
	if(a.p[i]||b.p[i])return false;
	else return true;
}


int main(){
	char* p=new char[50];
	cin.getline(p,50);
	Str a(p);
	cin.getline(p,50);
	Str b(p);
	cin.getline(p,50);
	Str c(p);
	
	if(a>b)a.show();
	else b.show();
	
	if(a<c)a.show();
	else c.show();
	
	if(b==c)b.show();
	else c.show();
	
	return 0;
}



/*******************************************/

