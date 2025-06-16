#include<iostream>
using namespace std;

template<class T>
class Data{
	T x[6];
	public:
		Data(){
		for(int i=0;i<6;i++){
			cin>>x[i];
		}
	}
	friend void check(Data<T> d){
	for(int i=0;i<5;i++){
		if(d.x[i+1]<d.x[i]){
			cout<<"Invalid"<<endl;
			return;
		}
	}
		cout<<"Valid"<<endl;
	
}
		
};


int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		cin>>c;
		if(c=='c'){
		Data<char> d;
		check(d);
	}
		else if(c=='i'){
		Data<int> d;
		check(d);}
		else if(c=='f'){
		Data<float> d;
		check(d);}
		
	}
	return 0;
} 
