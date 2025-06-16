#include<iostream>
using namespace std;
int main(){
	string s1="440301880228113";
	string s2="440301198802281133";
	cout<<s1.compare(6,9,s2,8,9);
	return 0;
}
