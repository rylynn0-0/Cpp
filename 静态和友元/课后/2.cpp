#include<iostream>
using namespace std;
#define GET(type,x) type get_##x(){return x;}
class Student{
	public:	
	Student(){};
	Student(int id,int sc):id(id),score(sc){
		number++;
	}
	
	void show(){
		cout<<id<<" ";
		string str=(score==0)?"Fail":"Pass";
		cout<<str<<endl;
	}
	
	GET(int,id);
	GET(int,score);
	static void show_num(){
		cout<<number<<" Students"<<endl;
	}
	private:
		int id;
		int score;
		static int number;
}; 
int Student::number=0;
int main(){
	int t;
	cin>>t;
	Student **stu=new Student*[t];
	int n[t];
	for(int i=0;i<t;i++){
	
		cin>>n[i];
		stu[i]=new Student[n[i]];
		for(int j=0;j<n[i];j++){
		 int id,sc;
		 cin>>id;
		 if(id!=0){
		 	cin>>sc;
		 	stu[i][j]=Student(id,sc);
		 }
		 else{
		 	id=stu[i][j-1].get_id()+1;
		 	sc=stu[i][j-1].get_score();
		 	stu[i][j]=Student(id,sc);
		 }
	}
	}
	Student::show_num() ;
	for(int i=0;i<t;i++){
		for(int j=0;j<n[i];j++){
			stu[i][j].show();
		}
	}
	return 0;
}
