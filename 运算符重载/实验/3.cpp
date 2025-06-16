#include<iostream>
#include<cmath>
using namespace std;

class N_4{
	int num[999];
	int len;
	
	public:
		
		N_4(N_4 &k){
			len=k.len;
			for(int i=0;i<len;i++){
				num[i]=k.num[i];
			}
		}
		
		N_4(int n){
			int len=(int)(log(n)/log(10)+1);
			for(int i=0;i<len;i++){
				num[i]=n/(int)pow(10,i)%10;
				//cout<<num[i]<<endl;
			}
			//cout<<len<<endl;
		}
		
		void operator +=(const N_4 &k){
			int m=min(len,k.len);
			cout<<len<<" "<<k.len<<endl;
			for(int i=0;i<m;i++){
				num[i]+=k.num[i];
				if(num[i]>=4){
					num[i]-=4;
					num[i+1]++;
				}
			}
		}
		
		void display(){
			cout<<len<<endl;
		}
};

int main(){
	int n;
	cin>>n;
	int x;
	cin>>x;
	N_4 num(x);
	
	//num.display();
	for(int i=1;i<n;i++){
		cin>>x;
		N_4 add(x);
		//add.display() ;
		num+=add;
	}
	num.display();
		return 0;
}
