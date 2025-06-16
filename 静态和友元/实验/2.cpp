#include<iostream>
#include<iomanip>
using namespace std;

class Customer{
	public:
		Customer(char* name){
			CustName=new char[20];
			int p=0;
			while(name[p]){
				CustName[p]=name[p];
				p++;
			}CustName[p]='\0';
			TotalCustNum++;
			Rent+=150;
		}
		~Customer(){
		delete CustName;	
		}
		
		static void changeYear(int r){
			Year=r;
		}
		void display(){
			cout<<CustName<<" "<<Year*10000+TotalCustNum<<" "<<TotalCustNum<<" "<<Rent<<endl;
		}
	private:
		static int TotalCustNum;
		static int Rent;
		static int Year;
		int CustID;
		char *CustName;
		
};

int Customer::TotalCustNum =0;
int Customer::Rent =0;
int Customer::Year =2014;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int r;
		cin>>r;
		Customer::changeYear(r);
		string name;
		cin>>name;

		while(name!="0"){
			char *custname=new char[20];
			int p=0;
			while(name[p]){
				custname[p]=name[p];
				p++;
			}custname[p]='\0';
			Customer cs(custname);
			delete custname;
			cs.display();
			cin>>name;	
		}
	}
	return 0;
}
