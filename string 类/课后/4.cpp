#include<bits/stdc++.h>
using namespace std;

class xiang{
	int a,b;
	
	public:
		xiang(){}
		void set(string str){
			
			b=0;
			a=0;
			int p;
			int b_idex=str.find('^');
			int x_idex=str.find('x');
			if(x_idex==string::npos)b=0;
			else if(b_idex==string::npos)b=1;
			else{
			    p=b_idex+1;
				while(str[p]){
					b=b*10+str[p]-'0';
					p++;
				}
			}
			p=0;
			if(str[0]=='-'||str[0]=='+')p++;
			
			while(str[p]<='9'&&str[p]>='0'){
				a=a*10+str[p]-'0';
				p++;
			}
			if(a==0)a++;
			if(str[0]=='-')a=0-a;
			
		}
		
		void display(){
			cout<<a<<" "<<b<<endl;
		}
};

class Str{
	string str;
	int n;
	xiang *x;
	public:
		Str(){
			cin>>str;
			n=1;
			int len=str.length();
			for(int i=1;i<len;i++){
				if(str[i]=='-'||str[i]=='+')n++;
			}
			x=new xiang[n];
			for(int i=0;i<n;i++){
				string s;
				int idex;
				idex=str.find_last_of("+-");
				if(idex==string::npos)idex=0;
				s=string(str,idex,len);
				str.erase(idex,len); 
				x[i].set(s);
			}
		}
		
		void display(){
			for(int i=n-1;i>=0;i--){
				x[i].display();
			}
		}
};

int main(){
	Str str;
	str.display() ;
	return 0;
}
