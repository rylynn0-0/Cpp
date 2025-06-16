#include<iostream>
#include<cmath>
using namespace std;

class N{
	protected:
	int num[9999];
	int len;
	
	public:
		N(int n=0){
			len=log(n)/log(10)+1;
			for(int i=0;i<len;i++){
				num[i]=n/(int)pow(10,i)%10;
				//cout<<num[i]<<endl;
			}
			//cout<<len<<endl;
		}
		
		void operator+=(N &n){
			int m=min(len,n.len);
			for(int i=0;i<m;i++){
				num[i]+=n.num[i];
				if(num[i]>=4){
					num[i]-=4;
					num[i+1]++;
				}
			}
		}
		
		void display(){
			for(int i=len;i>=0;i--){
				cout<<num[i];
			}cout<<endl;
		}
};

int main(){
	int n;
	cin>>n;
	int x;
	cin>>x;
	N num(x);
	//num.display();
	for(int i=1;i<n;i++){
		cin>>x;
		N num_(x);
		num+=num_;
	}
	num.display();
		return 0;
}
