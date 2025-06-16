#include<iostream>
using namespace std;

class cube{
	public:
		cube(int n,int m){
			this->n=n;
			this->m=m;
			num=new int *[n];
			for(int i=0;i<n;i++){
				num[i]=new int[m];
			}
			
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cin>>num[i][j];
				}
			}
			
			cout<<"before:"<<endl;
			
			print();
		}
		
		cube(const cube &c){
			n=c.m;
			m=c.n;
			num=new int *[n];
			for(int i=0;i<n;i++){
				num[i]=new int[m];
			}
			
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					num[i][j]=c.num[m-1-j][i];
				}
			}
			cout<<"after:"<<endl;
			print();
		}
		
		void print(){
			for(int i=0;i<n;i++){
				cout<<num[i][0];
				for(int j=1;j<m;j++){
					cout<<" "<<num[i][j];
				}cout<<endl;
			}
		}
		
		~cube(){
			for(int i=0;i<n;i++){
				delete[] num[i];
			}delete[] num;
		}
	
	private:
		int n,m;
		int** num;
};

int main(){
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		int n,m;
		cin>>n>>m;
		cube c(n,m);
		cube c_(c);
		cout<<endl;
	}
	return 0;
}
