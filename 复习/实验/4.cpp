#include<iostream>
using namespace std;
#define GET(type,T) type get_##T(){return T;}
#define SET(type,T) void set_##T(type T){this->T=T;}


class Course{
	public:
	Course(){}
	
	Course(string id,string name,int grade,int cent){
		this->id=id;
		this->name=name;
		this->grade=grade;
		this->cent=cent;
	}
	
	GET(int,cent);
		
	bool check_grade(){
		return grade>=60;
	}
	
	private:
		string id;
		string name;
		int grade;
		int cent;
		
		
};

class Student{
	public:
	Student(string id,string name,int age,string zhuanye ,int nianji,int type){
		this->id=id;
		this->name=name;
		this->age=age;
		this->zhuanye=zhuanye;
		this->nianji=nianji;
		this->type=type;
		jige=0;
		sum_cent=0;
	}
	
	GET(int,jige);
	
	Student(Student& st){
		jige=0;
		sum_cent=0;
		string str="2100";
		id=str+st.id;
		name=st.name;
		age=st.age;
		zhuanye=st.zhuanye;
		type=1;
		nianji=1;
		course_num=st.get_jige();
		course=new Course[course_num];
		int f=0;
		for(int i=0;i<st.get_course_num();i++){
			if(st.course[i].check_grade()){
				course[f]=st.course[i];
				sum_cent+=st.course[i].get_cent();
				f++;
			}
		}
	}
	GET(int,course_num);
	GET(int,sum_cent);
	
	void display(char c){
		string s=(type==1)?"postgraduate":"undergraduate";
		cout<<id<<" "<<name<<" "<<age<<" "<<zhuanye<<" "<<s<<" "<<nianji;
		if(c=='D'){
			cout<<" "<<endl;
		}
		else{
			cout<<" "<<course_num<<" "<<get_sum_cent()<<endl;;
		}
	}
	
	void record(){
		cin>>course_num;
		course=new Course[course_num];
		string c_id;
		string c_name;
		int c_grade;
		int c_cent;
		for(int i=0;i<course_num;i++){
			cin>>c_id>>c_name>>c_cent>>c_grade;
			if(c_grade>=60){
				sum_cent+=c_cent;
			jige++;}
			course[i]=Course(c_id,c_name,c_grade,c_cent);
		}
	}
	
	private:
		string id;
		string name;
		int age;
		string zhuanye;
		int nianji;
		int type;
		int course_num;
		int sum_cent;
		int jige;
		Course *course;
		
};

int main(){
	
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		string id;
		string name;
		int age;
		string zhuanye;
		int nianji;
		cin>>id>>name>>age>>zhuanye>>nianji;
		Student stu(id,name,age,zhuanye,nianji,0);
		stu.record();
		char x;
		cin>>x;
		stu.display(x);
		stu=Student(stu);
		cin>>x;
		stu.display(x);
		
	}
	
	return 0;
}
