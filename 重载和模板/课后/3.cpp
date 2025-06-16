#include<iostream>
using namespace std;


class CXGraph{
	int n;
	public:
		CXGraph(int n):n(n){}
		
		CXGraph& operator++(){
			if(this->n<21)this->n+=2;
			return (*this);
		}
		
		CXGraph& operator++(int){
			CXGraph *c=new CXGraph(*this);
			if(this->n<21)(*this).n+=2;
			return *c;
		}
		
		CXGraph& operator--(){
			if(this->n>1)this->n-=2;
			return (*this);
		}
		
		CXGraph& operator--(int){
			CXGraph *c=new CXGraph(*this);
			if(this->n>1)(*this).n-=2;
			return *c;
		}
		
		friend ostream & operator<<(ostream& Out,CXGraph& c){
			
			for(int i=0;i<c.n;i++){
				if(i<=c.n/2){
					for(int j=0;j<i;j++)Out<<" ";
					for(int j=0;j<(c.n/2-i)*2+1;j++)Out<<"X";
				}
				else {
					for(int j=0;j<c.n-i-1;j++)Out<<" ";
					for(int j=0;j<(i-c.n/2)*2+1;j++)Out<<"X";
				}
				Out<<endl;
			}
			return Out;
		}
}; 

int main(){
	int t,n;
	string command;
	cin>>n;
	CXGraph xGraph(n);
	cin>>t;
	while(t--){
		cin>>command;
		if(command=="show++"){
			cout<<xGraph++<<endl;
		}else if(command=="++show"){
			cout<<++xGraph<<endl;
		} else if(command=="show--"){
			cout<<xGraph--<<endl;
		} else if(command=="--show"){
			cout<<--xGraph<<endl;
		}else if(command=="show"){
			cout<<xGraph<<endl;
		}
	}
	
	return 0;
}
