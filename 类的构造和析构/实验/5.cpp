#include<iostream>
using namespace std;

class ID{
	public:
		ID(string s){
			id=s;
			cout<<"construct ID=";
			cout<<id<<endl;
		}
		
		void update(){
			string s1=string(id,0,6);
			string s2=string(id,6,9);
			
			id=s1+"19"+s2+jy();
			
			cout<<"upgrade ID=";
			cout<<id<<endl;
		}
		
		~ID(){
			string str =string(id,14,4);
			cout<<"destruct ID=";
			cout<<str<<endl;
		}
	private:
		string id;
		
	string jy(){
		int num1[]={7,9,10,5,8,4};
		int num2[]={6,3,7,9,10,5,8,4,2};
		string s1=string(id,0,6);
		string s2=string(id,6,9);
		unsigned long long sum=0;
		for(int i=0;i<6;i++){
			sum+=(s1[i]-'0')*num1[i];
		}
		sum+=1*2+9*1;
		for(int i=0;i<9;i++){
			sum+=(s2[i]-'0')*num2[i];
		}
		sum%=11;
		
		string s="0";
		if(sum==0)return"1";
		if(sum==1)return "0";
		sum=12-sum;
		if(sum<10){
			s[0]+=sum;
		return s;}
		if(sum==10)return "X";
	}
};


int main(){
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string str;
		cin>>str;
		ID id(str);
		id.update();
	}
	return 0;
}
