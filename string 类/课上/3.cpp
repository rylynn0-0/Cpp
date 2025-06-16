#include<bits/stdc++.h>
using namespace std;

class Student{
  string name;
  double price;
/********** Write your code here! **********/
	public:
		Student(){}
		
		void Get(){
			std::getchar();
			getline(cin,name,',');
			cin>>price;
		}
		
		double get_price(){
			return price;
		}
		
		void show(){
			cout<<name<<",price="<<price<<endl;
		}
};

/*******************************************/
int main(){
   int n,maxi; //maxi记录最贵的书在数组中的下标
   cin>>n;
   Student *s=new Student[n];
/********** Write your code here! **********/
	double Max=0;
	for(int i=0;i<n;i++){
		s[i].Get();
		if(Max<s[i].get_price()){
			Max=s[i].get_price();
			maxi=i;
		}
	}
    
    s[maxi].show();


/*******************************************/
   delete[] s;
   return 0;
}
