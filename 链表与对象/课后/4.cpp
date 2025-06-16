#include<iostream>
using namespace std;

class Man{
	public:
		Man(int n,string name,int **m){
			this->n=n;
			this->name=name;
			num=new int*[n];
			for(int i=0;i<n;i++){
				num[i]=new int [7];
			}
			
			for(int i=0;i<n;i++){
				for(int j=0;j<7;j++){
					num[i][j]=m[i][j];
				}
			}
		}
		
		~Man(){
			for(int i=0;i<n;i++){
				delete [] num[i];
			}delete num;
		}
		
		void show(){
			cout<<name<<" "<<n<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<7;j++){
					cout<<num[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
		string get_name(){
			return name;
		}
		
		int *get(int i){
			return num[i];
		}
	
	private:
		string name;
		int n;
		int **num;
};


int cmp(int jiang[],int *num){
	int n=0;
	for(int i=0;i<7;i++){
		if(jiang[i]==num[i]){
		n++;
		}
	}
	if(n==7)return 1;
	else if(n>=5)return 2;
	else if(n>=2)return 3;
	return 0;
}

int main(){
	int n;
	string name;
	cin>>n>>name;
	
	int **num=new int*[n];
	for(int i=0;i<n;i++){
		num[i]=new int [7];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<7;j++){
			cin>>num[i][j];
		}
	}
	Man man(n,name,num);
	for(int i=0;i<n;i++){
		delete [] num[i];
	}delete num;
	
	int jiang[7];
	for(int i=0;i<7;i++){
		cin>>jiang[i];
	}
	
	int s1=0,s2=0,s3=0;
	for(int i=0;i<n;i++){
		int pop=cmp(jiang,man.get(i));
		
		if(pop==1)s1++;
		else if(pop==2)s2++;
		else if(pop==3)s3++;
	}
	
	
	
	
	if(s1)cout<<"��ϲ"<<man.get_name() <<"����"<<s1<<"עһ�Ƚ���"<<endl; 
	if(s2)cout<<"��ϲ"<<man.get_name() <<"����"<<s2<<"ע���Ƚ���"<<endl; 
	if(s3)cout<<"��ϲ"<<man.get_name() <<"����"<<s3<<"ע���Ƚ���"<<endl; 
	
	if(s1==0&&s2==0&&s3==0){
		cout<<"���ͣ�������"<<endl;
	}
	return 0;
}
