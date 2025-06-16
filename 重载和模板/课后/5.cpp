#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class P{
	int n;
	int num[100];
	public:
		P(){
		for(int i=0;i<100;i++){
				num[i]=0;
			}
		}
		
		friend istream& operator>>(istream& In,P&p){
			In>>p.n;
			int a,b;
			
			for(int i=0;i<p.n;i++){
				In>>a>>b;
				p.num[b]=a;
			}
			return In;
		}
		
		friend ostream& operator<<(ostream& Out,P&p){
			int f=0;
			int f2=0;
			for(int i=0;i<100;i++){
				if(p.num[i]==0){
					if(i<99&&p.num[i+1]>0&&f2==1){
				   Out<<"+";}
				continue;}
				f=1;
				if(abs(p.num[i])!=1||i==0){
				Out<<p.num[i];
				f2=1;}
				if(p.num[i]==-1&&i!=0)Out<<"-";
				if(i!=0){
					f2=1;
					Out<<"x";
					if(i!=1){
						Out<<"^"<<i;
					}
				}
				if(i<99&&p.num[i+1]>0&&f2==1){
				Out<<"+";}
				
				
			}
			
			if(f==0)Out<<0;
			
			return Out;
			
		}
		
		friend P& operator+(P&p1,P&p2){
			P *p=new P(p1);
			for(int i=0;i<100;i++){
				p->num[i]+=p2.num[i];
			}
			
			return (*p);
		}
		
		friend P& operator-(P&p1,P&p2){
			P *p=new P(p1);
			for(int i=0;i<100;i++){
				p->num[i]-=p2.num[i];
			}
			
			return (*p);
		}
		
		friend P& operator*(P&p1,P&p2){
			P *p=new P;
			for(int i=0;i<100;i++){
				for(int j=0;j<100;j++){
					p->num[i+j]+=p1.num[i]*p2.num[j];
				}
			}
			
			return (*p);
		}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		P p1,p2;
		cin>>p1>>p2;
		cout<<p1+p2<<endl;
		cout<<p1-p2<<endl;	
		cout<<p1*p2<<endl;
	}
	return 0;
} 


