#include<iostream>
using namespace std;

template<class T>
class Data{
	int n;
	T x[100];
	public:
		Data(int n):n(n){
			
			for(int i=0;i<100;i++){
				x[i]=-1;
			}
			for(int i=0;i<n;i++){
				cin>>x[i];
			}
			
		}
		
		void Insert(int index,T num){
			for(int i=n;i>index;i--){
				x[i]=x[i-1];
			}
			x[index]=num;
			n++;
		}
		
		void Delete(int index){
			for(int i=index;i<n;i++){
				x[i]=x[i+1];
			}
			n--;
		}
		
		void show(){
			cout<<x[0];
			for(int i=1;i<n;i++){
				cout<<" "<<x[i];
			}cout<<endl;
			
		}
};

int main(){
	int n;
	int index,num;
	
	cin>>n;
	Data<int> d(n);
	
	cin>>index>>num;
	d.Insert(index,num);
	cin>>index;
	d.Delete(index);
	d.show();
	
	
	
	cin>>n;
	Data<double> d2(n);
	double num2;
	cin>>index>>num2;
	d2.Insert(index,num2);
	
	cin>>index;
	d2.Delete(index);
	d2.show();
	
	return 0;
}
