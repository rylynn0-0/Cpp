#include<iostream>
using namespace std;

class CRectangle{
	int x1,x2,y1,y2;
	public:
		CRectangle(int x1,int y1,int x2,int y2):x1(x1),y1(y2),x2(x2),y2(y1){}
		friend ostream & operator<<(ostream& Out,CRectangle& cr){
			Out<<cr.x1<<" "<<cr.y2<<" "<<cr.x2<<" "<<cr.y1;
			return Out;
		}
		operator int(){
			int num =(x2-x1)*(y2-y1);
			return num;
		}
		
		friend bool operator==(CRectangle& c1,CRectangle &c2){
			if(c1.x1==c2.x1&&c1.x2==c2.x2&&c1.y1==c2.y1&&c1.y2==c2.y2)return 1;
			else return 0;
		}
		
		friend bool operator>(CRectangle& c1,CRectangle &c2){
			if(c1.x1>c2.x1)return 0;
			if(c1.x2<c2.x2)return 0;
			if(c1.y1>c2.y1)return 0;
			if(c1.y2<c2.y2)return 0;
			return 1;
		}
		
		friend bool operator*(CRectangle& c1,CRectangle &c2){
			if(c1.x2<c2.x1)return 0;
			if(c1.x1>c2.x2)return 0;
			if(c1.y2<c2.y1)return 0;
			if(c1.y1>c2.y2)return 0;
			return 1;
		}
		
};


int main(){
	int t,x1,x2,y1,y2;
	cin>>t;
	while(t--){
		cin>>x1>>y1>>x2>>y2;
		CRectangle rect1(x1,y1,x2,y2);
		
		cin>>x1>>y1>>x2>>y2;
		CRectangle rect2(x1,y1,x2,y2);
		
		cout<<"矩形1:"<<rect1<<" "<<(int)rect1<<endl;
		cout<<"矩形2:"<<rect2<<" "<<(int)rect2<<endl;
		
		if(rect1==rect2)cout<<"矩形1和矩形2相等"<<endl;
		else if(rect2>rect1)cout<<"矩形2包含矩形1"<<endl;
		else if(rect1>rect2)cout<<"矩形1包含矩形2"<<endl;
		else if(rect1*rect2)cout<<"矩形1和矩形2相交"<<endl;
		else cout<<"矩形1和矩形2不相交"<<endl;
		cout<<endl;
	}
}
