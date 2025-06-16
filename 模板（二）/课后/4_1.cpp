#include<bits/stdc++.h>
using namespace std;

template<class T>
class CNode{
	public:
		T n;
		CNode *next;
		CNode(T n):n(n){
			next=NULL;
		}
};

template<class T>
class Clist{
	CNode<T> *head;
	public:
	
		Clist(T x,int n){
			head=new CNode<T>(x);
			append(x);
			for(int i=1;i<n;i++){
				T k;
				cin>>k;
				append(k);
			}
		}
		
		void append(T x){
			CNode<T>* p=head;
			while(p->next)p=p->next;
			CNode<T>* q=new CNode<T>(x);
			p->next=q;
		}
		
		void insert(T x,int n){
			CNode<T>* p=head;
			for(int i=0;i<n;i++){
			p=p->next;
			if(!p){
			cout<<"error"<<endl;
			return ;}
			}
			
			CNode<T>* q=new CNode<T>(x);
		
			q->next=p->next;
			p->next=q;
			
		}
		
		void get(int n){
			CNode<T>* p=head;
			for(int i=0;i<n;i++){
			p=p->next;
			if(!p){
			cout<<"error"<<endl;
			return;}
			}
			
				cout<<p->n<<endl;
		
		}
		
		void del(int n){
			CNode<T>* p=head;
			for(int i=0;i<n-1;i++){
			p=p->next;
			if(!p->next){
			return;}
			}
			CNode<T>*q=p->next;
			p->next=q->next;
			delete q;
		}
		
		void show(){
			CNode<T>* p=head;
			p=p->next;
			cout<<p->n;
			p=p->next;
			while(p){
				cout<<" "<<p->n;
				p=p->next;
			}cout<<endl;
		}
		
		void change(int n,T x){
			CNode<T>* p=head;
			for(int i=0;i<n;i++){
			p=p->next;
			if(!p){
			return;}
			}
			p->n=x;
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
			int x;
			cin>>x;
			Clist<int> cl(x,n);
			int p;
			cin>>p>>x;
			cl.insert(x,p); 
			cin>>p;
			cl.get(p);
			cin>>p;
			cl.del(p);
			cin>>p>>x;
			cl.change(p,x);
			cl.show();
		}
		else if(c=='D'){
			double x;
			cin>>x;
			Clist<double> cl(x,n);
			int p;
			cin>>p>>x;
			cl.insert(x,p); 
			cin>>p;
			cl.get(p);
			cin>>p;
			cl.del(p);
			cin>>p>>x;
			cl.change(p,x);
			cl.show();
		}else if(c=='S'){
			string x;
			cin>>x;
			Clist<string> cl(x,n);
			int p;
			cin>>p>>x;
			
			cl.insert(x,p); 
			cin>>p;
			cl.get(p);
			cin>>p;
			cl.del(p);
			cin>>p>>x;
			cl.change(p,x);
			cl.show();
		}
	}
	return 0;
}
