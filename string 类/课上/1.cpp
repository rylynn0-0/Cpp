
#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	while(getline(cin,str)){
		stringstream ss;
		ss<<str;
		string n;
		while(getline(ss,n,' ')){
			int num=n[0]-'0';
			cout<<num+1<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
