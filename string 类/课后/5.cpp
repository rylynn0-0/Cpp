#include<bits/stdc++.h>
using namespace std;

struct node{
	string str;
	node* next;
	int n;
};

void insert(node* head){
	string str;
	cin>>str;
	node *p=head;
	while(p->next)p=p->next;
	node *q=new node;
	q->next =NULL;
	q->str=str;
	p->next =q; 
}

void swap(node *k){
	node*p=k->next ;
	node *q=p->next ;
	p->next =q->next ;
	q->next =p;
	k->next =q;
}

void show(node*head){
	node *p=head->next;
	while(p){
		cout<<p->str<<endl;
		p=p->next ;
	}
}

void destory(node *head){
	while(head->next){
		node *p=head->next ;
		head->next =p->next ;
		delete p;
	}delete head;
}

void Sort(node* head){
	node *p=head;
	for(int i=0;i<head->n;i++){
		node *q=p;
		
		while(q->next->next){
			node*l=q->next ;
			node*r=l->next ;
			
			if(l->str < r->str){
			swap(q);
			node*mid=l;
			l=r;
			r=mid;
			}
					
			q=q->next ;
			
		}
		
	}
}

int main(){
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		int n;
		cin>>n;
		node *head=new node;
		head->next =NULL;
		head->n=n;
		for(int i=0;i<n;i++){
			insert(head);
		}
		Sort(head);
		
		show(head);
		destory(head);
		if(o!=t-1)cout<<endl;
	}
	return 0;
}
