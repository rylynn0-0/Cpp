#include<iostream>
using namespace std;

class Cset{
	int n;
	int *data;
	public:
	Cset(int n){
		this->n=n;
		data=new int[n];
		for(int i=0;i<n;i++){
			cin>>data[i];
		}
	}
	
	Cset(){}
	
	Cset(Cset &s){
		n=s.n;
		data=new int[n];
		for(int i=0;i<n;i++){
			data[i]=s.data[i];
		}
	}
	
	Cset operator+(Cset& c){
		Cset s;
		s.n=n+c.n;
		s.data=new int [s.n];
		for(int i=0;i<n;i++){
			s.data[i]=data[i];
		}
		int j=n;
		for(int i=n;i<n+c.n;i++){
			int flag=0;
			for(int k=0;k<n;k++){
				if(c.data[i-n]==data[k]){
					s.n--;
				    flag=1;}
			}
			if(flag==0){
				s.data[j]=c.data[i-n];
				j++;
			}
		}
		return s;
	}
	
	Cset operator*(Cset& c){
		Cset s;
		s.n=0;
		s.data=new int [n+c.n];
		int p=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<c.n;j++){
				if(data[i]==c.data[j]){
					s.data[p]=data[i];
					p++;
					s.n++;
				}
			}
		}
		return s;
	}
	
	
	Cset operator-(Cset& c){
		Cset s;
		s.n=n;
		s.data=new int [n+c.n];
		int k=0;
		for(int i=0;i<n;i++){
			int flag=0;
			for(int j=0;j<c.n;j++){
				if(c.data[j]==data[i]){
				flag=1;
				s.n--;
				}
			}
			if(flag!=1){
				s.data[k]=data[i];
				k++;
			}
			
		}
		return s;
	}
	
	const void show(){
		cout<<data[0];
		for(int i=1;i<n;i++){
			cout<<" "<<data[i];
		}cout<<endl;
	}
};



int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		Cset A(n);
		cin>>n;
		Cset B(n);
		Cset C,D;
		cout<<"A:";
		A.show();
		cout<<"B:";
		B.show();
		cout<<"A+B:";
		C=A+B;
		C.show();
		cout<<"A*B:";
		C=(A*B);
		C.show();
		cout<<"(A-B)+(B-A):";
		C=A-B;
		D=B-A;
		(C+D).show();
		cout<<endl;
		
	}
	return 0;
}
