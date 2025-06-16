#include<iostream>
using namespace std;

class polygon
{ 
protected:
   int number;//边数，最多不超过100条边
private:
   int side_length[100];//边长数组
public:
	polygon(){}
   polygon(int falg);
   polygon(int n,int height,int width);
   polygon(int n,int length);//构造函数根据需要重载
   void set(int n,int height,int width){
   	number=n;
	side_length[0]=height;
	side_length[2]=height;
	side_length[1]=width;
	side_length[3]=width;
   }
   void set(int n,int length){
   	number=n;
	for(int i=0;i<n;i++){
		side_length[i]=length;
	}
   }
   int perimeter();//计算多边形边长
   void display();//输出多边形边数和周长
};

polygon::polygon(int n,int length){
	number=n;
	for(int i=0;i<n;i++){
		side_length[i]=length;
	}
}

polygon::polygon(int n,int height,int width){
	number=n;
	side_length[0]=height;
	side_length[2]=height;
	side_length[1]=width;
	side_length[3]=width;
}

polygon::polygon(int flag){
	number=0;
	int n;
	cin>>n;
	while(n!=-1){
		side_length[number]=n;
		number++;
		cin>>n;
	}
}

int polygon::perimeter(){
	int sum=0;
	for(int i=0;i<number;i++){
		sum+=side_length[i];
	}
	return sum;
}

void polygon::display(){
	cout<<number<<" "<<perimeter()<<endl;
}

class rectangle:public polygon{
		private:
			int height;
			int width;
		public:
			rectangle(){
			  cin>>height>>width;
			  set(4,height,width);
			}
			rectangle(int h,int w):polygon(4,h,w){
				height=h;
				width=w;
			}
			
			int perimeter(){
				return 2*(height+width); 
			}
			
			void display(){
				polygon::display();
			}
};
class equal_polygon:public polygon{
	int side_len;
	int n;
	public:
		equal_polygon(){
		cin>>n>>side_len;
		set(n,side_len);
		}
		equal_polygon(int n,int length):polygon(n,length){
		 side_len=length;
		 this->n=n;
		}
		
		int perimeter(){
				return n*side_len; 
			}
			
			void display(){
				polygon::display();
			}
};


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int flag;
		cin>>flag;
		if(flag==0){
		
				polygon p(0);
				p.display();
		}else if(flag==1){
		
				rectangle r;
				r.display();
		}else if(flag==2)
		{
		
				equal_polygon e;
				e.display() ;
		}
	}
	return 0;
} 
