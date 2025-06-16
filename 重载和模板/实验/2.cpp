#include<iostream>
using namespace std;

template<class T>

int Find(T num[],T x,int n){
	int p=0;
	for(int i=0;i<n;i++){
		if(num[i]==x){
			p=i+1;
		}
	}
	return p;
}

int main(){
	int t;
	cin>>t;
	
	
	for(int o=0;o<t;o++){
		char c;
		int n;
		cin>>c>>n;
		
		if(c=='I'){
			int num[n];
			for(int i=0;i<n;i++){
				cin>>num[i];
			}
			int x;
			cin>>x;
			cout<<Find(num,x,n)<<endl;
		}else if(c=='D'){
			double num[n];
			for(int i=0;i<n;i++){
				cin>>num[i];
			}
			double x;
			cin>>x;
				cout<<Find(num,x,n)<<endl;
		} else if(c=='C'){
			char num[n];
			for(int i=0;i<n;i++){
				cin>>num[i];
			}
			char x;
			cin>>x;
				cout<<Find(num,x,n)<<endl;
		}else{
			string num[n];
			for(int i=0;i<n;i++){
				cin>>num[i];
			}
			string x;
			cin>>x;
				cout<<Find(num,x,n)<<endl;
		}
		
		
	
		
	}
	return 0;
}
