#include<iostream>
using namespace std;

class A{
	public:
	A(int n){
		this->n=n;
		cout<<"Constructing object "<<n<<endl;
	}
	~A(){
		cout<<"Destructing object "<<n<<endl;
	}
	private:
		int n;
};

int main(){
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			A a(i);
		}
		cout<<endl;
	}
	return 0;
}
