#include <iostream>
using namespace std;

// 基类
class Shape {
public:
    int getArea() {
        return 0;
    }
};

// 派生类 Square
/********** Write your code here! **********/
class Square:public Shape{
	
	public:
	void setSide(int a){
		this->a=a;
	}
	
	int getArea(){
		return a*a;
	}
	private:
		int a;
}; 



/*******************************************/
int main() {
    int a;
    cin >> a;
    
    Square square;
    square.setSide(a);       // 设置边长
    cout << square.getArea(); // 输出面积
    
    return 0;
}
