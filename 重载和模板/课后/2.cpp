#include<iostream>
#include<string>
using namespace std;

template<class T>
void my(T num[],T num2[],int n){

	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int i=0;i<n;i++){
		cin>>num2[i];
	}
	
	
for(int i=0;i<n;i++)cout<<num2[i];
for(int i=0;i<n;i++)cout<<num[i];
cout<<endl;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		int n;
		cin>>c>>n;
		if(c=='I'){
			int num[n];
			int num2[n];
			my(num,num2,n);
		}else if(c=='C'){
			char num[n];
			char num2[n];
			my(num,num2,n);
		}else if(c=='S'){
			string num[n];
			string num2[n];
			my(num,num2,n);
		}
		else if(c=='D'){
			double num[n];
			double num2[n];
			my(num,num2,n);
		}
	}
	return 0;
}
