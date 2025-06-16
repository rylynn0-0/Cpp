#include<iostream>
using namespace std;
template <class T>
class Matrix{
	int n,m;
	T x[100][100];
	public:
		Matrix(int n,int m):n(n),m(m){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cin>>x[i][j];
				}
			}
		}
		
		void transport(){
			int mn=max(m,n);
			for(int i=0;i<mn;i++){
				for(int j=i+1;j<mn;j++){
					T temp=x[i][j];
					x[i][j]=x[j][i];
					x[j][i]=temp;
				}
			}
			
			int mid=n;
			n=m;
			m=mid;
		}
		
		void print(){
			for(int i=0;i<n;i++){
				cout<<x[i][0];
				for(int j=1;j<m;j++){
					cout<<" "<<x[i][j];
				}cout<<endl;
			}
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		int n,m;
		cin>>c>>n>>m;
		if(c=='I'){
			Matrix<int> ma(n,m);
			ma.transport() ;
			ma.print() ;
		}else if(c=='D'){
			Matrix<double> ma(n,m);
			ma.transport() ;
			ma.print() ;
		}
		else if(c=='C'){
			Matrix<char> ma(n,m);
			ma.transport() ;
			ma.print() ;
		}
	}
	return 0;
}
