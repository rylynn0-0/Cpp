#include<iostream>
using namespace std;

class Str{
	public:
		Str(){}
		Str(string s){
			str=s;
			num=0;
			for(int i=0;i<str.length();i++){
				if(str[i]>='0'&&str[i]<='9'){
					num=num*10+str[i]-'0';
					
				}
			}
			
		}
	private:
		string str;
		int num;
		friend void ADD(Str s1,Str s2);
		friend void MINUS(Str s1,Str s2);
};

void ADD(Str s1,Str s2){
	cout<<s1.num+s2.num<<endl;
}

void MINUS(Str s1,Str s2){
	cout<<s1.num-s2.num<<endl;
}

int main(){
	int n;
	while(cin>>n){
		Str s[n];
		for(int i=0;i<n;i++){
			string str;
			cin>>str;
			s[i]=Str(str);
		}
		int t;
		cin>>t;
		for(int j=0;j<t;j++){
			
		
		int a,b;
		string mode;
		cin>>mode;
		cin>>a>>b;
		if(mode=="ADD"){
			
				ADD(s[a],s[b]);
			}
			
			else{
			
				MINUS(s[a],s[b]);

			}}
	}
	return 0;
}
