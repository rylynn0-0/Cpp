#include<iostream>
using namespace std;
#define SET(type,T) void set_##T(type T){this->T=T;}
#define GET(type,T) type get_##T(){return T;}

class Song{
	public:
		Song(){
			cout<<"constructor"<<endl;
		}
		
		SET(string ,name);
		SET(string,title);
		SET(int ,length);
		GET(int ,length);
		void print(){
			cout<<name<<"'s song-"<<title<<" lasts for "<<length<<" minutes"<<endl;
		}
		~Song(){
			cout<<"destructor"<<endl;
		}
	private:
		string name;
		string title;
		int length;
};

int Select(Song s[],int n){
	int max=0;
	int p=0;
	for(int i=0;i<n;i++){
		if(s[i].get_length()>max){
			max=s[i].get_length();
			p=i;
		}
	}
	return p;
}

int main(){
	int n;
	cin>>n;
	Song song[n];
	string name;
	string title;
	int length;
	for(int i=0;i<n;i++){
		cin>>name>>title>>length;
		song[i].set_name(name);
		song[i].set_title(title);
		song[i].set_length(length);
	}
	song[Select(song,n)].print();
	return 0;
}
