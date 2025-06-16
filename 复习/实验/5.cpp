#include<iostream>
#include<cmath>
using namespace std;
#define TRACE(T) cout<<#T<<"="<<T<<endl;
#define GET(type,T) type get_##T(){return T;}



class node{

double x,y;     // 点的平面坐标。

node *next;

public:

GET(double,x);
GET(double,y);

node(double xx=0,double yy=0,node *link=NULL){
	x=xx;
	y=yy;
	next=link;
}

	node*& get_next(){
		return next;
	}

void show(){
	TRACE(x);
	TRACE(y);
}

};

class polygon{

node *head;

public:
	
polygon(){
	head=new node(0,0);
}

polygon(double pt[][2],int n){
	head=new node;
	node *p=head;
	for(int i=0;i<n;i++){
		p->get_next()=new node(pt[i][0],pt[i][1]);
		p=p->get_next();
	}

}

void show(){
	node *p=head;
	while(p->get_next()){
		p->get_next()->show();
		p=p->get_next();
	}
}

 // 构建空表 polygon(double pt[][2],int n);

/* 第一个参数pt，两列的二维数组，按多边形顶点顺序一行存放一个点，第一列存放横坐标x、第二列存放纵坐标y；

第二个参数n，顶点的个数。该构造函数依据参数数据建单链表 */

polygon(polygon &po){
	head=new node;
	node *p=head;
	node *q=po.head ;
	while(q->get_next()){
		p->get_next()=new node(*q->get_next());
		q=q->get_next() ;
		p=p->get_next() ;
	}
	
};

~polygon(){
	node *p=head;
	while(p->get_next()){
		node *q=p->get_next() ;
		p->get_next() =q->get_next() ;
		delete q;
	}delete head;
}

double peri(){
	double sum=0;
	double x,y;
	node* p=head;
	if(p->get_next()){
	x=p->get_next()->get_x();
	y=p->get_next()->get_y();
	p=p->get_next();
	while(p->get_next()){
		node *q=p->get_next() ;
		sum+=sqrt(pow(p->get_x()-q->get_x(),2)+pow(p->get_y()-q->get_y(),2));
		p=p->get_next() ;
	}
	sum+=sqrt(pow(p->get_x()-x,2)+pow(p->get_y()-y,2));
}
	return sum;
	

	
 }

};





int main()

{

const int N = 1024;

double pts[N][2];

int n;

int i;

cin >> n;

for( i=0; i<n ; i++)

cin >> pts[i][0] >> pts[i][1];



polygon  p, q(pts,n);

polygon r(q);


cout << p.peri() << endl;

cout << q.peri() << endl;

cout << r.peri() <<endl;

 

return 0;

}
