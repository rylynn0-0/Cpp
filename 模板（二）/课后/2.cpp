#include<iostream>
using namespace std;

template <class T>
class Stack{
	T x[1000];
	int p;
	public:
		Stack(){p=0;}
		void push(T i){
			p++;
			x[p]=i;
		}
		
		void pop(){
			if(p!=0){
				cout<<x[p]<<" is popped from stack!"<<endl;
				p--;
			}
			else cout<<"Error!"<<endl;
		}
		
		void show(){
			if(p!=0){
			while(p!=0){
				cout<<x[p]<<" ";
				p--;
			}cout<<endl;
		}
		else cout<<"Empty Stack!"<<endl;
		}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		int n;
		string str;
		cin>>c>>n;
		if(c=='I'){
			Stack<int> s;
			int x;
			for(int i=0;i<n;i++){
				cin>>str;
				if(str=="Push"){
					cin>>x;
					s.push(x);
				}
				else if(str=="Pop"){
					s.pop();
				}
			}
			s.show();
		}else if(c=='F'){
			Stack<float> s;
			float x;
			for(int i=0;i<n;i++){
				cin>>str;
				if(str=="Push"){
					cin>>x;
					s.push(x);
				}
				else if(str=="Pop"){
					s.pop();
				}
			}
			s.show();
		}else if(c=='C'){
			Stack<char> s;
			char x;
			for(int i=0;i<n;i++){
				cin>>str;
				if(str=="Push"){
					cin>>x;
					s.push(x);
				}
				else if(str=="Pop"){
					s.pop();
				}
			}
			s.show();
		}
	}
	return 0;
}
