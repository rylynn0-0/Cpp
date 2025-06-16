#include<bits/stdc++.h>
using namespace std;

template<class T>
class Data{
	T x[100];
	int n;
	public:
		Data(int n):n(n){
			for(int i=0;i<n;i++){
				cin>>x[i];
			}
			next_permutation(x,x+n);
			cout<<x[0];
			for(int i=1;i<n;i++){
				cout<<" "<<x[i];
			}cout<<endl;
		}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		int n;
		cin>>c>>n;
		if(c=='C'){
			Data<char> d(n);
		}else if(c=='I'){
			Data<int> d(n);
		}else if(c=='D'){
			Data<double> d(n);
		}else if(c=='S'){
			Data<string> d(n);
		}
	}
	return 0;
}
