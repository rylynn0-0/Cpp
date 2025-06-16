#include<iostream>

using namespace std;


class Vector{

int vec[5];

public:

Vector(int v[]){
	for(int i=0;i<5;i++){
		vec[i]=v[i];
	}
}

Vector(){}

Vector(const Vector& obj){}

Vector operator +(const Vector& obj){
	int num[5];
	for(int i=0;i<5;i++){
		num[i]=vec[i]+obj.vec[i];
	}
	return Vector(num);
}

Vector operator -(const Vector& obj){
	int num[5];
	for(int i=0;i<5;i++){
		num[i]=vec[i]-obj.vec[i];
	}
	return Vector(num);
}

void print(){
	
	for(int i=0;i<5;i++){
		cout<<vec[i]<<" ";
	}cout<<endl;
}

};


int main(){
	int num[5];
	for(int i=0;i<5;i++){
		cin>>num[i];
	}	
	
	Vector v1(num);
	for(int i=0;i<5;i++){
		cin>>num[i];
	}
	Vector v2(num);
	
	Vector v3=v1+v2;
	v3.print();
	v3=v1-v2;
	v3.print();
	
	return 0;
} 
