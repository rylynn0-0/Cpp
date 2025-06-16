#include<iostream>
using namespace std;

class CExaminee{
	public:
		CExaminee(string id,int p,int e,int m,int c){
			this->id=id;
			Politics=p;
			English=e;
			Math=m;
			Computer=c;
			sum=p+e+m+c;
		}
	
	void check(int total,int hun,int fif){
		string str=(sum>=total&&Politics>=hun&&English>=hun&&Math>=fif&&Computer>=fif)?"pass":"fail";
		cout<<id<<str<<endl;
			
		
	}
	
	private:
	
	string id;
	int Politics;
	int English;
	int Math;
	int Computer;
	int sum;
}; 

int main(){
	int total,hun,fif;
	cin>>total>>hun>>fif;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string id;
		int Politics;
		int English;
		int Math;
		int Computer;
		cin>>id>>Politics>>English>>Math>>Computer;
		CExaminee exam(id,Politics,English,Math,Computer);
		exam.check(total,hun,fif);
	}
	return 0;
}
