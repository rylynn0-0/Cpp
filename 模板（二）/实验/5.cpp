
#include <bits/stdc++.h>
using namespace std;

class Complex{
	public:
	int real,magin;
	friend istream& operator>>(istream&i,Complex&c){
		i>>c.real>>c.magin;
		return i;
	}
	
	friend ostream& operator<<(ostream&o,const Complex&c){
		string str=(c.magin>0)?"+":"";
		o<<c.real<<str<<c.magin;
		return o;
	}
};

template<class T>

void reverse(T &x){
	ostringstream os;
	string s;
	os << x;
	s = os.str();

	int l=0,r=s.length()-1;
	while(s[r]=='0'){r--;}
	s=string(s,0,r-l+1);
	if(s[0]=='-')l++;
	
	for(int i=l;i<=(r-l)/2;i++){
		char temp=s[i];
		s[i]=s[r-i+l];
		s[r-i+l]=temp;
	}
	cout<<s<<endl;
}

void reverse(Complex& x){
	int temp=x.real ;
	x.real=x.magin;
	x.magin=temp;
	cout<<x<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		cin>>c;
		if(c=='I'){
			int x;
			cin>>x;
			reverse(x);
		}else if(c=='D'){
			double x;
			cin>>x;
			reverse(x);
		}
		else if(c=='S'){
			string x;
			cin>>x;
			reverse(x);
		}else if(c=='C'){
			Complex x;
			cin>>x;
			reverse(x);
		}
	}
	return 0;
}
