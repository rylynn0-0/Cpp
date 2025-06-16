#include<iostream>
using namespace std;
template<class T>	
class 	BoundArry{
	T x[100];
	int n;
	public:
		BoundArry(int n):n(n){
			for(int i=0;i<n;i++){
				cin>>x[i];
			}
		}
		
		void Sort(){
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(x[i]>x[j]){
						T temp=x[i];
						x[i]=x[j];
						x[j]=temp;
					}
				}
			}
			
			for(int i=0;i<n;i++){
				cout<<x[i]<<" ";
			}cout<<endl;
		}
		
		void Find(T m){
			for(int i=0;i<n;i++){
				if(x[i]==m){
					cout<<i<<endl;
					return;
				}
			}
			cout<<-1<<endl;
		}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		int n;
		cin>>c>>n;
		if(c=='I'){
			int m;
		
			BoundArry<int> b(n);
			b.Sort();
			cin>>m;
			b.Find(m);
		}
		else if(c=='D'){
			double m;
		
			BoundArry<double> b(n);
			b.Sort();
				cin>>m;
			b.Find(m);
		}
		else if(c=='C'){
			char m;
			
			BoundArry<char> b(n);
			b.Sort();
				cin>>m;
			b.Find(m);
		}
	}
	return 0;
}
