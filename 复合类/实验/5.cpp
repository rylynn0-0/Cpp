#include<iostream>
using namespace std;
class lottery{
	public:
		lottery(int g[],int n){
			for(int i=0;i<6;i++){
				group1[i]=g[i];
			}
			num=n;
			groupn=new int*[n];
			for(int i=0;i<n;i++){
				groupn[i]=new int[6];
			}
		}
		
		lottery(const lottery &ly){
			for(int i=0;i<6;i++){
				group1[i]=ly.group1[i];
			}
			num=ly.num;
			groupn=new int*[num];
			for(int i=0;i<num;i++){
				groupn[i]=new int[6];
			}
			
			groupn[0][0]=group1[5]+1;
			for(int i=1;i<6;i++){
				groupn[0][i]=group1[i-1]+1;
			}
			
			for(int i=1;i<ly.num;i++){
				fun(groupn[i],groupn[i-1]);
			}
		}
		
		void print(){
			cout<<group1[0];
			for(int i=1;i<6;i++){
				cout<<" "<<group1[i];
			}cout<<endl;
			
			for(int i=0;i<num;i++){
				cout<<groupn[i][0];
				for(int j=1;j<6;j++){
					cout<<" "<<groupn[i][j];
				}cout<<endl;
			}
		}
	
	private:
		
		void fun(int *p,int *q){
			p[0]=q[5]+1;
			for(int i=1;i<6;i++){
				p[i]=q[i-1]+1;
			}
		}
		
		int group1[6];
		int num;
		int **groupn;
};

int main(){
	int t=0;
	cin>>t;
	for(int o=0;o<t;o++){
		int g1[6];
		int n;
		for(int i=0;i<6;i++)cin>>g1[i];
		cin>>n;
		lottery ly(g1,n);
		lottery ly_(ly);
		ly_.print(); 
		
	}
	return 0;
}
