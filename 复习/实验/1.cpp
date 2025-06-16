#include<iostream>
#include<iomanip>
using namespace std;
#define GET(type,T) type get_##T(){return T;}



		
class RMB{
	public:
		RMB(int y,int j):yuan(y),jiao(j){};
		GET(double,yuan);
		GET(double,jiao);
	
	private:
		
		int yuan;
		int jiao;
};


void compare (RMB &r1 ,RMB &r2){
		double rmb1= r1.get_yuan()+r1.get_jiao()*0.1;
		double rmb2= r2.get_yuan()+r2.get_jiao()*0.1;
		if(rmb1>rmb2){
			cout<<fixed<<setprecision(1)<<rmb1<<"yuan > "<<rmb2<<"yuan"<<endl;
		}
		else if(rmb1<rmb2){
			cout<<fixed<<setprecision(1)<<rmb1<<"yuan < "<<rmb2<<"yuan"<<endl;
		}
		else {
			cout<<fixed<<setprecision(1)<<rmb1<<"yuan = "<<rmb2<<"yuan"<<endl;
		}
		}
		

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int y1,j1,y2,j2;
		cin>>y1>>j1>>y2>>j2;
		RMB r1(y1,j1);
		RMB r2(y2,j2);
		compare(r1,r2);
	}
	return 0;
} 
