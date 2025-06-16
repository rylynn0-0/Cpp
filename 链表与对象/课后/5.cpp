#include<iostream>
using namespace std;

struct SNode{
	int e;
	struct SNode* next;
};

void createList(SNode *&head, int *value, int n){
	struct SNode*p=head;
	for(int i=0;i<n;i++){
		struct SNode* q=new struct SNode;
		int x=value[i];
		p->next=q;
		q->e=x;
		q->next=NULL;
		p=q;
	}
}

void printList(SNode *head){
	struct SNode*p=head->next;
	if(p){
	while(p->next){
		cout<<p->e<<" ";
		p=p->next;
		}
	cout<<p->e<<endl;
	}
	else {
		cout<<"error"<<endl;
	}
}

int insertNode(SNode *head, int pos, int value){
	int n=head->e;
	if(pos<1||pos>n+1){
		cout<<"error"<<endl;
		return 0;
	}
	struct SNode *q=new struct SNode;
	struct SNode *p=head;
	q->e=value;
	q->next=NULL;
	for(int i=0;i<pos-1;i++){
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
	head->e++;
	return 1;
}


int removeNode(SNode *head, int pos){
	int n=head->e;
	if(pos<1||pos>n){
		cout<<"error"<<endl;
		return 0;
	}
	struct SNode *q=new struct SNode;
	struct SNode *p=head;
	for(int i=0;i<pos-1;i++){
		p=p->next;
	}
	q=p;
	p=p->next;
	q->next=p->next;
	delete p;
	head->e--;
	return 1;
}

void deleteList(SNode *head){
	while(head->next){
		struct SNode *p=head;
		head=head->next;
		delete p;
	}
	delete head;
}

int main(){
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		struct SNode* head=new struct SNode;
		head->e=n;
		head->next =NULL; 
		int *value=new int [n];
		for(int j=0;j<n;j++){
			cin>>value[j];
		}
		
		
		createList(head,value,n);
		printList(head);
		
		int n1,n2;
		cin>>n1;
		for(int j=0;j<n1;j++){
			int k,num;
			cin>>k>>num;
			if(insertNode(head,k,num)==1)
			printList(head);
		}
		cin>>n2;
		for(int j=0;j<n2;j++){
			int k;
			cin>>k;
			 if(removeNode(head,k)==1)
			 printList(head);
		}
		
		deleteList(head);
		
	}
	
	
	return 0;
} 
