#include <iostream>
using namespace std;

// ����
class Shape {
public:
    int getArea() {
        return 0;
    }
};

// ������ Square
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
    square.setSide(a);       // ���ñ߳�
    cout << square.getArea(); // ������
    
    return 0;
}
