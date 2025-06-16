#include<iostream>
#include<string>
using namespace std;

template<class T>
void mySort(T num[],int n){

	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(num[i]<num[j]){
				T temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<num[i]<<" ";
	}cout<<endl;
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
			mySort(num,n);
		}else if(c=='C'){
			char num[n];
			mySort(num,n);
		}else if(c=='S'){
			string num[n];
			mySort(num,n);
		}
		else if(c=='D'){
			double num[n];
			mySort(num,n);
		}
	}
	return 0;
}
