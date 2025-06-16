#include<iostream>
#include<string>
using namespace std;
class Student {
	string name;
	int age;
	char sex;
public:
	Student(string n, int a, char s);
	void display();
};

class Athlete {
	string sport;
	int hours;
public:
	Athlete(string p, int h);
	void display();
};

class StudentAthlete :public Student, public Athlete {
	string school;
public:
	StudentAthlete(string n, int a, char s, string p, int h, string c);
	void display();
};
//在此处补充Student（学生）、Athlete（运动员）、StudentAthlete（学生运动员）三个类的实现
/********** Write your code here! **********/
Student::Student(string n, int a, char s){
	name=n;
	age=a;
	sex=s;
}
void Student::display(){
	cout<<"Student Info: "<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"Sex: "<<sex<<endl;
}

Athlete::Athlete(string p, int h){
	sport=p;
	hours=h;
} 
void Athlete::display(){
	cout<<"Athlete Info: "<<endl;
			cout<<"Sport: "<<sport<<endl;
			cout<<"Training Hours: "<<hours<<endl;
}
StudentAthlete::StudentAthlete(string n, int a, char s, string p, int h, string c):
	Student(n,a,s),Athlete(p,h),school(c){}
	
void StudentAthlete::display(){
	Student::display() ;
	Athlete::display();
	cout<<"School: "<<school<<endl;
}


/*******************************************/
int main() {
	string name, sports,school;
	int age, hours;
	char sex;
	cin >> name >> age >> sex;
	cin >> sports >> hours;
	cin.ignore();
	getline(cin,school, '\n');
	StudentAthlete obj(name, age, sex, sports, hours, school);
	obj.display();
	return 0;
}
