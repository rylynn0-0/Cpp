#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int b=n/100;
	int s=n%100/10;
	int g=n%10;
    string str;
    for(int i=0;i<b;i++){
    	str+="B";
	}
	for(int i=0;i<s;i++){
		str+="S";
	}
	string s2("0");
	for(int i=0;i<g;i++){
		s2[0]+=1;
		str+=s2;
	}
	cout<<str<<endl;
	return 0;
}
