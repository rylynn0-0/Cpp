#include <iostream>
using namespace std;

class Point;
Point operator -- (Point & );
Point operator -- (Point &, int);

class Point {
private:
	int x, y, z;
public:
	Point(int tx=0, int ty=0, int tz=0 )
	{	x = tx, y = ty, z = tz;	}
	Point operator ++ ();
	Point operator ++ (int);
	friend Point operator -- (Point & );
	friend Point operator -- (Point &, int);
	void print();
};
//完成以下填空
/********** Write your code here! **********/
Point Point::operator ++(){
	x++;
	y++;
	z++;
	return *this;
} 

Point Point::operator ++(int){
	Point temp(*this);
	x++;
	y++;
	z++;
	return temp;
} 

Point operator--(Point& p){
	p.x--;
	p.y--;
	p.z--;
	return p;
}

Point operator --(Point &p,int){
	Point temp(p);
	p.x--;
	p.y--;
	p.z--;
	return temp;
} 

void Point::print(){
	cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
}

/*******************************************/
int main()
{	int tx, ty, tz;
	cin>>tx>>ty>>tz;
	Point p0(tx, ty, tz); //原值保存在p0
	Point p1, p2;	//临时赋值进行增量运算

	//第1行输出
	p1 = p0;
	p1++;;
	p1.print();
	//第2行输出
	p1 = p0;
	p2 = p1++;
	p2.print();
	//第3、4行输出，前置++
	p1 = p0;
	(++p1).print();
	p1.print();
	//第5、6行输出，后置--
	p1 = p0;
	p1--;
	p1.print();
	p0.print();
	//第7、8行输出，前置--
	p1 = p0;
	(--p1).print();
	p1.print();

	return 0;
}
