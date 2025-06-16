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
//����������
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
	Point p0(tx, ty, tz); //ԭֵ������p0
	Point p1, p2;	//��ʱ��ֵ������������

	//��1�����
	p1 = p0;
	p1++;;
	p1.print();
	//��2�����
	p1 = p0;
	p2 = p1++;
	p2.print();
	//��3��4�������ǰ��++
	p1 = p0;
	(++p1).print();
	p1.print();
	//��5��6�����������--
	p1 = p0;
	p1--;
	p1.print();
	p0.print();
	//��7��8�������ǰ��--
	p1 = p0;
	(--p1).print();
	p1.print();

	return 0;
}
