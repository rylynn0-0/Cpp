#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class CBook{
	string name;
	string writer;
	double money;
	string publisher;
	public:
		CBook(){}
		CBook(string n,string w,double m,string p):name(n),writer(w),money(m),publisher(p){};
		int find(CBook *book, int n, int &max1index,int &max2index);
		
		friend istream & operator>>(istream& In,CBook &cb){
			string x;
			getline(In,x);
			int p=x.find(",");
			cb.name=string(x,0,p);
			
			if(p!=-1)
			x=string(x,p+1);
			p=x.find(",");
			cb.writer =string(x,0,p);
			
			if(p!=-1)
			x=string(x,p+1);
			p=x.find(",");
			string mon;
			mon =string(x,0,p);
			cb.money=0;
			int l=1;
			int f=0;
			for(int i=0;i<mon.length();i++){
				if(f==0&&mon[i]!='.')
				cb.money=cb.money*10+mon[i]-'0';
				
				else if(mon[i]!='.'){
				cb.money+=((mon[i]-'0')*pow(0.1,l));
				l++;
			}
				else if(mon[i]=='.'){
					f=1;
				}
				
			}
			
			if(p!=-1)
			x=string(x,p+1);
			p=x.find(",");
			cb.publisher =string(x,0,p);
			
			return In;
			
		}
		
		friend ostream& operator<<(ostream& Out,CBook& cb){
			Out<<cb.name<<endl;
			Out<<cb.writer <<endl;
			Out<<fixed<<setprecision(2)<<cb.money<<endl;
			Out<<cb.publisher <<endl;
			Out<<endl;
			
			return Out;
		}
		
		friend bool operator>(CBook&c1,CBook&c2){
			return c1.money>c2.money;
		}
		
		friend bool operator==(CBook&c1,CBook&c2){
			return c1.money==c2.money;
		}
};



int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		CBook cb[n];
		getchar();
		for(int i=0;i<n;i++){
			cin>>cb[i];
		}
		
		int p1=0;
		int p2=1;
		
		for(int i=0;i<n;i++){
			if(cb[i]>cb[p1]){
				p1=i;
			}
		}
		for(int i=0;i<n;i++){
			if(cb[i]>cb[p2]&&i!=p1){
				p2=i;
			}
		}
		
		cout<<cb[p1]<<cb[p2];
	}
	return 0;
}
