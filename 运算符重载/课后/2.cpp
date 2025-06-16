#include<iostream>
using namespace std;

class box{

private: 

string num;
 int length;
 int width;
 int height;

public:
	
	void set(){
	cin>>num>>length>>width>>height;
	}
	
	int operator-(box &b){
		int h=min(height,b.height);
		if(length>=b.length&&width>=b.width){
			return h*b.length *b.width;
		}
		else if(length<=b.length&&width<=b.width){
			return h*length *width;
		}
		else return -1;
	}
	
	friend void display(box&b1,box&b2,int maxx);

};

void display(box&b1,box&b2,int maxx){
	if(b1.width>b2.width)cout<<b2.num<<"盒子放入"<<b1.num<<"盒子溢出的水最多，为"<<maxx<<"。"<<endl;
	else cout<<b1.num<<"盒子放入"<<b2.num<<"盒子溢出的水最多，为"<<maxx<<"。"<<endl;
}


int main(){
	int n;
	cin>>n;
	box *b=new box[n];
	for(int i=0;i<n;i++){
		b[i].set();
	}
	int maxx=0;
	int pi=0,pj=0;
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(b[i]-b[j]>maxx){
				pi=i;
				pj=j;
				maxx=b[i]-b[j];
			}
		}
	}
	
	display(b[pi],b[pj],maxx);
	
	return 0;
}
