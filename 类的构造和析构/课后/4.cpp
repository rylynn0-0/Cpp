#include<iostream>
using namespace std;

class CSieve
{
private:
char *p_sieve;
unsigned long num;                //numÊÇ×î´ó·¶Î§
public:
CSieve(unsigned long n);
void printPrime();
~CSieve();
};

CSieve::CSieve(unsigned long n){
	num=n;
	p_sieve =new char[n+1];
}

void CSieve::printPrime() {
	cout<<2;
	for(int i=3;i<=num;i++){
		if(i%2==0)p_sieve[i]='0';
		else p_sieve[i]='1';
	}
	
	for(int i=3;i<=num;i++){
		
		
		for(int j=i+1;j<=num;j++){
			if(j%i==0)p_sieve[j]='0';
		}
		
		if(p_sieve[i]=='1'){
			cout<<" "<<i;
		}
	}
	cout<<endl;
}

CSieve::~CSieve(){
	delete p_sieve;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		unsigned long n;
		cin>>n;
		CSieve c(n);
		c.printPrime();
	}
	
	return 0;
}
