#include<iostream>
using namespace std;
class CRect;
class CPoint {

public:
	CPoint() {}
	CPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
private:
	int x, y;
	friend int check(CRect& cr1, CRect& cr2);
	friend CRect;
};


class CRect {
public:
	CRect() {}
	CRect(CPoint _p1, CPoint _p2) {
		p1 = _p1;
		p2 = _p2;

	}

private:
	CPoint p1, p2;
	friend int check(CRect& cr1, CRect& cr2);

};

int check(CRect& cr1, CRect& cr2) {
	if ((cr1.p2.x > cr2.p1.x && cr1.p2.x < cr2.p2.x) ||
		(cr1.p1.x > cr2.p1.x && cr1.p1.x < cr2.p2.x) ||
		(cr1.p1.y > cr2.p1.y && cr1.p1.y < cr2.p2.y) ||
		(cr1.p2.y > cr2.p1.y && cr1.p2.y < cr2.p2.y) ||
		
		(cr2.p2.x > cr1.p1.x && cr2.p2.x < cr1.p2.x) ||
		(cr2.p1.x > cr1.p1.x && cr2.p1.x < cr1.p2.x) ||
		(cr2.p1.y > cr1.p1.y && cr2.p1.y < cr1.p2.y) ||
		(cr2.p2.y > cr1.p1.y && cr2.p2.y < cr1.p2.y)
		){
		return 1;}
	
	else {
		
	return 0;}
}

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	int n;
	cin >> n;
	CRect cp[2];
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < 2; j++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2) {
				swap(x1, x2);
			}
			if (y1 > y2) {
				swap(y1, y2);
			}
			cp[j] = CRect(CPoint(x1, y1), CPoint(x2, y2));
		}
		if (check(cp[0], cp[1]) == 1)cout << "overlapped" << endl;
		else cout << "not overlapped" << endl;
	}
	return 0;
}
