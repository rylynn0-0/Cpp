#include<iostream>
using namespace std;

class CGame{
	public:
	CGame(int n){
		win=0;
		this->n=n;
		num=new int*[n];
		for(int i=0;i<n;i++){
			num[i]=new int[n];
		}
		char x;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				
				cin>>x;
				num[i][j]=x;
			}
		}
	}
	
	void check_win(){
			win=1;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(num[i][j]!='*')win=0;
				}
			}
			
	}
	
	void show(){
		if(wrong>=3&&win==0){
			cout<<"Game Over"<<endl;
		}
		else{
			if(win==1){
				cout<<"Congratulations"<<endl;
				counter++;
			}
		}
	}
	
	void get_counter(){
		cout<<counter<<endl;
	}
	
	void check(int x1,int y1,int x2,int y2){
		
		if(num[x1][y1]=='*'||num[x2][y2]=='*'||num[x1][y1]!=num[x2][y2]){
			wrong++;
			return;
		}
		num[x1][y1]='*';
		num[x2][y2]='*';
		
	}
	
	~CGame(){
		for(int i=0;i<n;i++){
			delete []num[i];
		}delete []num;
	}
	
	private:
		int n;
		int win;
		int **num;
		int wrong;
		static int counter;
};

int CGame::counter=0;
int main(){
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		int n,m;
		cin>>n;
		CGame game(n);
		cin>>m;
		int x1,x2,y1,y2;
		for(int i=0;i<m;i++){
			cin>>x1>>y1>>x2>>y2;
			game.check(x1-1,y1-1,x2-1,y2-1);
			game.check_win() ;
		}
		game.show();
	}
	CGame game(0);
	game.get_counter();
	return 0;
}
