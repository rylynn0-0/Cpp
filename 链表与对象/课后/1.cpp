#include<iostream>
using namespace std;

class Bulk{
	public:
	Bulk(int length,int width,int height){
		this->length=length;
		this->width=width;
		this->height=height;
	}
	
	int get_volume(){
		return length*width*height;
	}
	
	int get_areas(){
		return 2*(length*width+width*height+height*length);
	}
	
	private:
		int length;
		int width;
		int height;
		
};

int main(){
	int h,w,l;
	cin>>l>>w>>h;
	Bulk b(l,w,h);
	cout<<b.get_volume()<<endl;
	cout<<b.get_areas()<<endl;
	return 0;
}
