#include <iostream>
using namespace std;

// 补齐CObject类定义和实现

/********** Write your code here! **********/
class CObject{
	public:
	CObject(){
		value=0;
		cout<<"Constructed by default, value = 0"<<endl;
	}
	CObject(int a){
		value=a;
		cout<<"Constructed using one argument constructor, value = "<<value<<endl;
	}
	CObject(const CObject& x){
		value=x.value;
		cout<<"Constructed using copy constructor, value = "<<value<<endl;
	}
	private:
		int value;
};



/*******************************************/
int main()
{
    int t,n,val;

    cin >> t;
    while(t--)
    {
        cin >> n;
        if(!n)
        {
            CObject obj;
        }
        else if(n==1)
        {
            cin >> val;
            CObject obj(val);
        }
        else if(n==2)
        {   
            cin >> val;
            CObject obj(val);
            CObject newobj(obj);
        }
    }
  	return 0;
}

