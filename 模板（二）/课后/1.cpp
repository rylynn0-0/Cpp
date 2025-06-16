#include<iostream>
using namespace std;

class CClock{
	int hour;
	int min;
	int sec;
	public:
		CClock(int h=0,int m=0,int s=0):hour(h),min(m),sec(s){}
		friend ostream& operator<<(ostream& o,const CClock& c){
			o<<c.hour<<" "<<c.min<<" "<<c.sec;
			return o;
		}
		
		CClock operator+(CClock &c){
			sec+=c.sec;
			min+=c.min;
			hour+=c.hour;
			while(sec>=60){
				sec-=60;
				min++;
			}
			while(min>=60){
				min-=60;
				hour++;
			}
			while(hour>=24){
				hour-=24;
			}
			return (*this);
		}
};

class CRmb{
	int yuan;
	int jiao;
	int fen;
	public:
		CRmb(int y=0,int j=0,int f=0):yuan(y),jiao(j),fen(f){}
		friend ostream& operator<<(ostream& o,const CRmb& c){
			o<<c.yuan<<" "<<c.jiao<<" "<<c.fen;
			return o;
		}
		CRmb operator+(CRmb &c){
			yuan+=c.yuan;
			jiao+=c.jiao;
			fen+=c.fen;
			while(fen>=10){
				fen-=10;
				jiao++;
			}while(jiao>=10){
				jiao-=10;
				yuan++;
			}
			return (*this);
		}
};

template<class T>
T add(T &t1,T &t2,int key){
	return t1+t2;
}


int main(){
	int h,m,s;
	cin>>h>>m>>s;
	CClock c1(h,m,s);
	cin>>h>>m>>s;
	CClock c2(h,m,s),c;
	c = add(c1, c2, 60);
	cout << c << endl;

 
	int y,j,f;
	cin>>y>>j>>f;
	CRmb r1(y,j,f);
	cin>>y>>j>>f;
	CRmb r2(y,j,f), r;
	r = add(r1, r2, 10);
	cout << r << endl;
	return 0;
}
