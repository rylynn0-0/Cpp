#include<iostream>
using namespace std;

template<class T>
void Find_max(T num[],int n){
	int key[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
		key[i]=0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(num[i]==num[j])key[i]++;
		}
	}
	int p=0;
	for(int i=0;i<n;i++){
		if(key[i]>key[p]){
			p=i;
		}
	}
	cout<<num[p]<<" "<<key[p]<<endl;
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
			Find_max(num,n);
		}else if(c=='C'){
			char num[n];
			Find_max(num,n);
		}else if(c=='S'){
			string num[n];
			Find_max(num,n);
		}
	}
	return 0;
}
