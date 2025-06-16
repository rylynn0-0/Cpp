#include<iostream>
using namespace std;


class CCow{
	public:
		CCow(){
			year=0;
			alive=0;
			for(int i=0;i<7;i++){
				son[i]=NULL;
			}
		}
		
		~CCow(){
			for(int i=0;i<7;i++){
				delete son[i];
			}delete []son;
		} 
		
		void born(){
			num++;
			year=0;
			alive=1;
		}
		
		void die(){
			num--;
			alive=0;
		}
		
		void set_num_0(){
			num=0;
		}
		void update(){
			year++;
			
			if(year==11){
				die();
			}
			
			if(year>=4 && alive==1){
				son[year-4]=new CCow;
				son[year-4]->born();
			}
			
			
			for(int i=0;i<7;i++){
				if(son[i])son[i]->update();
			}
		}
		void show(){
			cout<<num<<endl;
		}
	private:
		int year;
		int alive;
		static int num;
		
		CCow **son=new CCow*[7];
		
};

int CCow::num=0;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		CCow cow;
		cow.born();
		for(int i=0;i<n;i++){
			cow.update();
//			cow.show();
		}
		cow.show();
		cow.set_num_0() ;
	}
	return 0;
}
