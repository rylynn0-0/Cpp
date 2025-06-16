#include<iostream>
#include<cstring>
using namespace std;

class STR{
	public:
		STR(char *t){
			s=new char[strlen(t)+1];
			strcpy(s,t);
			cout<<"constructing..."<<endl;
		}
		
		STR(const STR& obj){
			s=new char[strlen(obj.s)+1];
			strcpy(s,obj.s);
			cout<<"copy constructing..."<<endl;
		}
		
		~STR(){
			delete s;
			cout<<"delete space..."<<endl;
		}
		
		void fun(){
			char* q=new char [1000];
			char* k=new char [1000];
			char *c =new char [1000];
			int i=0;
			int j=0;
			int u=0;
			while(s[i]){
				
				if(s[i]!=' '){
					q[j++]=s[i];
				}
				if(s[i]==' '||i==strlen(s)-1){
					q[j++]='\0';
					j=0;
					backward(q,k);
					
					for(int e=0;e<strlen(k);e++){
						c[u++]=k[e];
					}
					c[u++]=' ';
				}
				
				i++;
			}
			c[strlen(s)]='\0';
			delete q;
			delete k;
			s=c;
		}
		
		void print(){
			cout<<s;
		}
		
	private:
		char*s;
		void backward(char *t1,char *t2){
			for(int i=0;i<strlen(t1);i++){
				t2[i]=t1[strlen(t1)-i-1];
			}
			t2[strlen(t1)]='\0';
		}
};

int main(){
	char *p=new char [1000];
	string q;
	getline(cin,q);
	
	for(int i=0;i<q.length();i++){
		p[i]=q[i];
	}p[q.length()]='\0';
	//cout<<p<<endl;
	
	STR s(p);
	STR s_cpy(s);
	s_cpy.fun() ;
	s.print();
	cout<<" can be tranformed to ";
	s_cpy.print();
	cout<<endl;
	
	return 0;
}
