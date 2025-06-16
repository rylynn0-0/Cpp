#include<iostream>
#include<iomanip>
using namespace std;

class Goods{
	public:
		Goods(){
			Next=NULL;
		}
		
		Goods(int id,string name,string color,string size,double money,double num){
			this->id=id;
			this->name=name;
			this->color=color;
			this->size=size;
			this->money=money;
			this->num=num;
			sum=num*money;
			Next=NULL;
		}
		
		Goods * next(){
			return Next;
		}
		
		void setnext(Goods* p){
			Next=p;
		}
		
		int getid(){
			return id;
		}
		
		void addnum(int n){
			num+=n;
		}
		
		double getmoney(){
			return money;
		} 
		
		int getnum(){
			return num;
		}
		
		void show(){
			cout<<name<<","<<color<<","<<size<<","<<fixed<<setprecision(2)<<money<<setprecision(0)<<","<<num<<",";
		}
		
	private:
		int id;
		string name;
		string color;
		string size; 
		double money;
		double num;
		double sum;	
		Goods* Next;
};

class Paycar{
	public:
		Paycar(){
			n=0;
			gz=new Goods;
		}
		void add(int id,string name,string color,string size,double money,double num){
			n+=num;
			Goods *p=gz;
			int f=0;
			while(p->next()){
				if(p->getid()==id){
					p->addnum(num);
					f=1;
					break;
				}
				p=p->next();
				
			}
			if(f==0){
				Goods *q=new Goods(id,name,color,size,money,num);
				q->setnext(gz->next());
				gz->setnext(q);
			}
		}
		void up(int id){
			n++;
			Goods *p=gz;
			while(p->next()){
				if(p->getid()==id){
					p->addnum(1);
					break;
				}
				p=p->next();
			}
			
		}
		
		void down(int id){
			
			Goods *p=gz;
			while(p->next()){
				if(p->getid()==id){
					if(p->getnum()>1){
					
					p->addnum(-1);
					n--;}
					break;
				}
				p=p->next();
			}
			
		}
		
		void delete_(int id){
			Goods *p=gz;
			while(p->next()){
				if(p->next()->getid()==id){
					n-=p->next()->getnum() ;
					Goods*q=p->next();
					p->setnext(q->next());
					delete q;
					break;
				}
				p=p->next();
			}
		}
		
		void show(){
			cout<<"商品清单:"<<endl;
			cout<<"商品,颜色,尺码,单价,数量,小计"<<endl;
			 Goods *p=gz->next();
			 double sum=0;
			while(p){
				p->show();
				cout<<fixed<<setprecision(2)<<p->getnum()*p->getmoney();
				sum+=p->getnum()*p->getmoney();
				cout<<endl;
				p=p->next();
			}
			
			cout<<"----------"<<endl;
			cout<<n<<"件商品,总商品金额"<<fixed<<setprecision(2)<<sum<<endl;
		}
		
	private:
		int n;
		Goods *gz;
};

int main(){
	
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		int n;
		cin>>n;
		Paycar paycar;
		for(int i=0;i<n;i++){
			string str;
			int id;
			string name;
			string color;
			string size; 
			double money;
			double num;
			cin>>str;
			if(str=="ADD"){
				
				cin>>id>>name>>color>>size>>money>>num;
				paycar.add(id,name,color,size,money,num);
			}
			if(str=="UP"){
				cin>>id;
				paycar.up(id);
			}
			
			if(str=="DOWN"){
				cin>>id;
				paycar.down(id);
			} 
			
			if(str=="DELETE"){
				cin>>id;
				paycar.delete_(id);
			}
		}
		paycar.show();
	}
	return 0;
} 
