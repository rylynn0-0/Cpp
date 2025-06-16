#include<iostream>
using namespace std;

class Student {

private:

int id;

int score; 

static int  maxscore;

static int maxid;

public:

Student(int ti=0,int ts=0):id(ti), score(ts){}
void set(int ti=0,int ts=0){
	id=ti;
	score=ts;
	
	
}
static void findMax(Student & st){
	if(maxscore<st.score){
		maxscore=st.score;
		maxid=st.id;
	}
}

void show(){
	cout<<maxid<<"--"<<maxscore<<endl;
}

static int getMaxScore(){
	return maxscore;
}

static int getMaxID(){
	return maxid;
}

};

int Student::maxid=0;
int Student::maxscore=0;

int main(){
	
	int n;
	cin>>n;
	Student s[n];
	for(int i=0;i<n;i++){
		int id;
		int score;
		cin>>id>>score;
		s[i].set(id,score);
		s[i].findMax(s[i]); 
	}
	s[0].show();
	return 0;
} 
