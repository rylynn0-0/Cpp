#include<iostream>
using namespace std;

template<class T>

void get_max(T num[5]){
	
	for(int i=0;i<5;i++){
		cin>>num[i];
	}
	T maxx=0;
	for(int i=0;i<5;i++){
		if(maxx<num[i])maxx=num[i];
	}
	cout<<maxx<<endl;
}

int main(){
	int n1[5];
	float n2[5];
	long n3[5];
	get_max(n1);
	get_max(n2);
	get_max(n3);
	
	return 0;
}
