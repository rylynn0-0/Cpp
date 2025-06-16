// 请补充头文件、polyitem类、友元函数split和poly类实现。注意poly类的析构函数已经实现，无需再写

/********** Write your code here! **********/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define TRACE(T) cout<<#T<<"="<<T<<endl;
#define GET(type,T) type get_##T(){return T;}
class poly;
class polyitem{
	public:
		polyitem(){}
		polyitem(int a,int b,int c){
			this->a=a;
			this->b=b;
			this->c=c;
		}
		int get_b(){
			return b;
		}
		
		void display(int type){
			if(type==1&&a==0)return;
			if(a<0)cout<<"-";
			if(type==1){
				if(a>0)cout<<"+";
			}
			if(fabs(a)==1&&b==0&&c==0){
				cout<<"1";
			}
			if(fabs(a)!=1)cout<<fabs(a);
			if(b!=0){
				cout<<"x";
				if(b>1){
					cout<<"^"<<b;
				}
			}
			if(c!=0){
				cout<<"y";
				if(c>1){
					cout<<"^"<<c;
				}
			}
			
		}
		
		int get_c(){
			return c;
		}
		friend polyitem split(string item);
		friend class poly;
		friend  bool cmp(const polyitem &it1,const polyitem &it2);
	private:
		int a,b,c;
};

polyitem split(string item){
	int a=1,b=1,c=1;
	int f=0;
	int p=0;
	if (item[0]=='-'||item[0]=='+')p++;
	while(item[p]>='0'&&item[p]<='9'){
		a=(f==0)?item[p]-'0':a*10+item[p]-'0';
		f=1;
		p++;
	}
	f=0;
	if(item[0]=='-')a=0-a;
	
	p=item.find('x');
	
	if(p>item.length())b=0;
	else{
		p+=2;
		while(item[p]>='0'&&item[p]<='9'&&p<item.length()){
		b=(f==0)?item[p]-'0':b*10+item[p]-'0';
		p++;
		f=1;
	}
}
	f=0;
	p=item.find('y');
	
	if(p>item.length())c=0;
	else{
		p+=2;
		while(item[p]>='0'&&item[p]<='9'&&p<item.length()){
		c=(f==0)?item[p]-'0':c*10+item[p]-'0';
		p++;
		f=1;
	}
}
//TRACE(a);
//TRACE(b);
//TRACE(c);
	return polyitem(a,b,c);
}

bool cmp(const polyitem &it1,const polyitem &it2){
			if(it1.b==it2.b)return it1.c>it2.c;
			else return it1.b>it2.b;
		}

class poly{
	public:
		friend  bool cmp(const polyitem &it1,const polyitem &it2);
		poly(){
			 n=0;
			items=new polyitem[1];
			items[0]=polyitem(0,0,0);
		}
		poly(string str){
			n=0;
			int len=str.length();
			int num[len+1];
			num[0]=1;
			num[len]=1;
			for(int i=1;i<len;i++){
				num[i]=0;
				if(str[i]=='-'||str[i]=='+'){
				n++;
				num[i]=1;
				}
			}
			n++;
			items =new polyitem[n];
			int p=0;
			int r=0,l=0;
			for(int i=1;i<=len;i++){
				if(num[i]==1){
					l=r;
					r=i;
					items[p]=split(string(str,l,r-l));
					p++;
				}
			}
		}
		
		int get_n()const{
			return n;
		}
		polyitem* get_item()const{
			return items;
		}
		
		void display(){
			items[0].display(0);
			for(int i=1;i<n;i++){
				items[i].display(1);
			}cout<<endl;
			
		}
		void polysort(){
			sort(items,items+n,cmp);
		}
		
		void addpoly(const poly& rhs){
			int len=n+rhs.get_n();
			polyitem*  item_new= new polyitem[len];
			int p=0;
			int q=0;
			int x=0;
			 for(int i=0;i<len;i++){
			 	if(p>=n){
			 		item_new[i]=rhs.get_item()[q];
					 	q++;
				 }
				 else if(q>=rhs.get_n()){
				 	item_new[i]=items[p];
					 	p++;
				 }
				 else
			 	if(items[p].b==rhs.get_item()[q].b){
			 		if(items[p].c==rhs.get_item()[q].c){
			 			if(items[p].a+rhs.get_item()[q].a==0){
			 				p++;
			 				q++;
			 				i--;
			 				x+=2;
						 }
						 else{
						 
			 			item_new[i]=polyitem(items[p].a+rhs.get_item()[q].a,items[p].b,items[p].c);
			 			p++;
			 			q++;
			 			x++;}
					 }
					 else if(items[p].c<rhs.get_item()[q].c){
					 	item_new[i]=rhs.get_item()[q];
					 	q++;
					 }
					 else {
					 	item_new[i]=items[p];
					 	p++;
					 }
				 }
				 else if(items[p].b<rhs.get_item()[q].b){
					 	item_new[i]=rhs.get_item()[q];
					 	q++;
					 }
					 else {
					 	item_new[i]=items[p];
					 	p++;
					 }
			 }
			 delete items;
			 items=item_new;
			 //TRACE(len);
			 n=len-x;
			 
		} 
		
		
	~poly();
	
	private:
		
		polyitem *items;
		int n;
	
};




/*******************************************/
//poly类的析构函数
poly::~poly()
{	
    if (items)
        delete[] items;
}

// 主函数
int main()
{
    string polystr;
    int t, m;
    string op;

    cin >> t; // 输入测试次数t

    while (t--)
    {
        cin >> m; // 输入m, 表示m个多项式

        poly polyres; // 初始结果多项式，项数0

        for (int i = 0; i < m; i++)
        {
            cin >> polystr;         // 输入多项式串
            poly polya(polystr);    // 解析polystr串构造多项式
            polya.polysort();       // 按指数降序排序
			  polya.display();        // 输出解析构造的多项式
            polyres.addpoly(polya); // polyres+=polya
        }
        polyres.display(); // 按指数降序排序输出
    }

    return 0;
}

