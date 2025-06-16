#include<iostream>
using namespace std;

class Document{
	protected:
		string name;
	public:
		Document(string str):name(str){
			cout<<"Create Document Class"<<endl;
		}
		~Document(){
			cout<<"Delete Document Class"<<endl;
		}
		void Print(){
			cout<<"Document Name is "<<name<<endl;
		}
};

class Book:public Document{
	private:
		int pageCount;
	public:
		Book(string str,int count):Document(str),pageCount(count){
			cout<<"Create Book Class"<<endl;
		}
		~Book(){
			cout<<"Delete Book Class"<<endl;
		}
		void Print(){
			Document::Print();
			cout<<"PageCount is "<<pageCount<<endl;
		}
};

int main(){
	string str;
	int n;
	cin>>str>>n;
	Book book(str,n);
	book.Print();
	return 0;

