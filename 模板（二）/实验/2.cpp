#include<iostream>
#include<iomanip>
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
		}
		
		void show(){
			cout<<"[";
			for(int i=0;i<n-1;i++){
				cout<<fixed<<setprecision(1)<<x[i]<<", ";
			}cout<<fixed<<setprecision(1)<<x[n-1]<<"]"<<endl;
		}
		
		void mysort(int l,int r){
			if(l<r){
				l=max(0,l);
				r=min(r,n);
				for(int i=l;i<r-1;i++){
					for(int j=i+1;j<r;j++){
						if(x[i]>x[j]){
							T temp=x[i];
							x[i]=x[j];
							x[j]=temp;
						}
					}
				}
				
			}
			
			show();
		}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		int n,l,r;
		char c;
		cin>>s>>n;
		cin>>c;
		cin>>l;
		cin>>c;
		cin>>r;
		cin>>c;
		cin>>c;
		
		if(s=="int"){
			Data<int> d(n);
			d.mysort(l,r);
		}else if(s=="string"){
			Data<string> d(n);
			d.mysort(l,r);
		}else if(s=="float"){
			Data<float> d(n);
			d.mysort(l,r);
		}
	}
	return 0;
}
