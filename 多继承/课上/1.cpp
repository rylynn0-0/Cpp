#include<iostream>
#include<string>
using namespace std;
//在此处补充Student（学生）、Athlete（运动员）、StudentAthlete（学生运动员）三个类的定义和实现
/********** Write your code here! **********/
class Student{
	protected:
		string name;
		int age;
		char sex;
	public:
		Student(string name,int age,char sex):name(name),age(age),sex(sex){}
		void displayStudent(){
			cout<<"Student Info: "<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"Sex: "<<sex<<endl;
		}
};

class Athlete{
	protected:
		string sport;
		int hour;
	public:
		Athlete(string sport,int hour):sport(sport),hour(hour){}
		void displayAthlete(){
			cout<<"Athlete Info: "<<endl;
			cout<<"Sport: "<<sport<<endl;
			cout<<"Training Hours: "<<hour<<endl;
		}
};

class StudentAthlete:public Student,public Athlete{
	private:
		string school;
	public: 
	StudentAthlete(string name,int age,char sex,string sport,int hour,string school):
		Student(name,age,sex),Athlete(sport,hour),school(school){}
		
	void display(){
		Student::displayStudent() ;
		Athlete::displayAthlete();
		cout<<"School: "<<school<<endl;
	}
};

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
