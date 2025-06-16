#include<iostream>
using namespace std;

class Institue{
	protected:
		string name;
	public:
		Institue(string name):name(name){}
		void set(string name){
			this->name=name;
		}
		
};

class Student:public Institue{
	protected:
		string id;
		string name;
	public:
		Student(string yuanming="",string id="",string name=""):
		Institue(yuanming),id(id),name(name){}
		
		void set(string yuanming,string id,string name){
			Institue::set(yuanming);
			this->id=id;
			this->name=name;
		}
		
		string get_id(){
			return id;
			
		}
		
		void display(){
			cout<<Institue::name<<","<<Student::name<<",";
		}
		
		string get_yuan()
		{
			return Institue::name;
		}
};

class Course:public Institue{
	protected:
		string id;
		string name;
		int cent;
		string time;
	public:
		Course(string yuanming="",string id="",string name="",int cent=0,string time=""):
		Institue(yuanming),id(id),name(name),cent(cent),time(time){}
		
		void set(string yuanming,string id,string name,int cent,string time){
			Institue::set(yuanming);
			this->id=id;
			this->name=name;
			this->cent=cent;
			this->time=time;
			
		}
		string get_id(){
			return id;
			
		}
		string get_yuan()	
			{
			return Institue::name;
			}
			
		string get_time(){
			return time;
		}

};

class Student_Course:public Student,public Course{
	bool flag;
	public:
		Student_Course(Student& s,Course &c):Student(s),Course(c){
		if(s.get_yuan()!=c.get_yuan())flag=0;
		else flag=1;

		}
		Student_Course(){}
		void display(){
			Student::display();
			cout<<Course::name<<","<<cent<<","<<time<<endl;
		}
		
		bool check(){
			return flag;
		}
		void set_0(){
			flag=0;
		}
	
};

class Administration{
	Student_Course* p;
	int n;
	public:
		Administration(int n,Student *stu,Course* course,int t1,int t2){
			this->n=n;
			p=new Student_Course[n];
			string stu_id,course_id;
			for(int j=0;j<n;j++){
			cin>>stu_id>>course_id;
			Student S;
			Course C;
			for(int i=0;i<t1;i++){
				if(stu_id==stu[i].get_id()){
					S=stu[i];
					break;
				}
			}
			
			for(int i=0;i<t2;i++){
				if(course_id==course[i].get_id()){
					C=course[i];
					break;
				}
			}
			p[j]=Student_Course(S,C);
		}
		}
		
		void check(){
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(p[i].Student::get_id()==p[j].Student::get_id() && 
					p[i].Course::get_time()==p[j].Course::get_time()){
						p[j].set_0();
					}
				}
				
			}
		}
		
		void display(){
			
			for(int i=0;i<n;i++){
				if(p[i].check())p[i].display();
				
			}
		}
};

 int main(){
 	int t1,t2,t3,cent;
 	cin>>t1;
 	string yuanming,id,name,time,id_;
 	Student *stu=new Student[t1];
 	for(int i=0;i<t1;i++){
 		cin>>yuanming>>id>>name;
 		stu[i].set(yuanming,id,name);
	 }
	 
	 cin>>t2;
	 Course *couse=new Course[t2];
	 for(int i=0;i<t2;i++){
	 	cin>>yuanming>>id>>name>>cent>>time;
	 	couse[i].set(yuanming,id,name,cent,time);
	 }
	 cin>>t3;
	 
	 Administration admin(t3,stu,couse,t1,t2);
	 admin.check() ;
 	admin.display() ;
 	return 0;
 }
 
 
