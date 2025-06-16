#include<iostream>
using namespace std;

class CBigInteger{
	char* num;
	bool is_p;
	int n;
	public:
		friend void show(CBigInteger &s1,CBigInteger&s2,CBigInteger&ans,char c);
	
	void display(){
		if(!is_p){cout<<"(-";}
		for(int i=n-1;i>=0;i--)cout<<num[i];
		if(!is_p)cout<<")";
	}
	
	CBigInteger(){}
	
	CBigInteger(const CBigInteger &c){
		n=c.n;
		is_p=c.is_p;
		num=new char[n+5];
		for(int i=0;i<n;i++){
			num[i]=c.num[i];
		}
	}
	
	CBigInteger(string str){
		is_p=true;
		num=new char[str.length()+5];
		n=0;
		int m=0;
		for(int i=0;i<str.length();i++){
			if(str[i]=='0'||str[i]=='-')m++;
			else break;
		}
		int len=str.length()-m;
		if(str[0]=='-')is_p=false;
		for(int i=0;i<len;i++){
			num[n]=str[str.length()-i-1];
			n++;
		}
	}
	
	~CBigInteger(){
	delete num;
	}
	
	bool operator>(const CBigInteger &c){
		if(n>c.n)return true;
		else if(n<c.n)return false;
		else {
			int i=n-1;
			while(num[i]==c.num[i])i--;
			return num[i]>c.num[i];
		}
	}
	
    CBigInteger operator+(CBigInteger &c){	
    	CBigInteger ans;
		ans.num=new char[max(n,c.n)+5];
		
		for(int i=0;i<=max(n,c.n);i++)ans.num[i]='0';
		ans.n=0;
    	if(is_p^c.is_p==0){
    		ans.is_p =is_p;
    		int minn=max(n,c.n);
    		ans.n=minn;
    		for(int i=0;i<minn;i++){
    			if(i>=n)ans.num[i]+=(int)c.num[i]-'0';
    			else if(i>=c.n)ans.num[i]+=(int)num[i]-'0';
    			else ans.num[i]=(int)ans.num[i]+(int)num[i]-'0'+(int)c.num[i]-'0';
    			
    			if(ans.num[i]>'9'){
    				ans.num[i]-=10;
    				ans.num[i+1]=ans.num[i+1]+1;
    				if(i+2>ans.n)ans.n++;
				}
			}
		}
		
		else{
			int maxx=max(n,c.n);
			ans.n=maxx;
			ans.is_p=(n>c.n)?is_p:c.is_p;
			if(n==c.n)ans.is_p=(num[n-1]>c.num[n-1])?is_p:c.is_p;
			if(*this>c){
				for(int i=0;i<min(n,c.n);i++){
					ans.num[i]=(int)ans.num[i]+(int)num[i]-(int)c.num[i];
					//cout<<ans.num[i]<<endl;
					if(ans.num[i]<'0'){
						ans.num[i]+=10;
						ans.num[i+1]--;
					}
				}
				for(int i=min(n,c.n);i<maxx;i++){
					ans.num[i]=ans.num[i]+num[i]-'0';
				}
			}else{
				for(int i=0;i<min(n,c.n);i++){
					ans.num[i]=(int)ans.num[i]+(int)c.num[i]-(int)num[i];
					//cout<<ans.num[i]<<endl;
					if(ans.num[i]<'0'){
						ans.num[i]+=10;
						ans.num[i+1]--;
					}
				}
				for(int i=min(n,c.n);i<maxx;i++){
					ans.num[i]=ans.num[i]+c.num[i]-'0';
				}
			}
			
		}
		
		return ans;
	}
	
	CBigInteger operator-(CBigInteger &c){
		CBigInteger temp(c);
		
		temp.is_p=!temp.is_p;
		
		return (*this+temp);
	}
	
};


void show(CBigInteger &s1,CBigInteger&s2,CBigInteger&ans,char c){
	s1.display() ;
	cout<<" "<<c<<" ";
	s2.display();
	cout<<" = ";
	ans.display();
	cout<<endl;
}

int main(){
	int n ;
	cin>>n;
	for(int i=0;i<n;i++){
		string s1,s2;
		char c;
		cin>>s1>>c>>s2;
		CBigInteger c1(s1);
		CBigInteger c2(s2);
		//CBigInteger ans;
//		c1.display(); 
//		cout<<endl;
//		c2.display();
//		cout<<endl;
//		CBigInteger ans;
		if(c=='+'){
		CBigInteger	ans=c1+c2;
		show(c1,c2,ans,c);
		}else if(c=='-'){
		CBigInteger	ans=c1-c2;
		show(c1,c2,ans,c);
		}
		
		
		
	}
	return 0;
} 



