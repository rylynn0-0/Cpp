#include<iostream>
using namespace std;

class CVector {
	int** v;
	int m;
	int n;
public:
	CVector() { n = 0; m = 0; v = NULL; }
	CVector(int** a, int b, int c) {
		int i, j;
		m = b; n = c;
		v = new int*[m];
		for (i = 0; i < m; i++) v[i] = new int[n];
		for (i = 0; i<m; i++)
			for (j = 0; j < n; j++)
				v[i][j] = a[i][j];
	}
/********** Write your code here! **********/
	CVector(CVector &c){
		m=c.m;
		n=c.n;
		v = new int*[m];
		for (int i = 0; i < m; i++) v[i] = new int[n];
		for (int i = 0; i<m; i++)
			for (int j = 0; j < n; j++)
				v[i][j] = c.v[i][j];
	}
	CVector & operator=(const CVector &c){
		m=c.m;
		n=c.n;
		if (v != NULL) {
			for (int i = 0; i < m; i++) delete[] v[i];
			delete[]v;
		}
		v = new int*[m];
		for (int i = 0; i < m; i++) v[i] = new int[n];
		for (int i = 0; i<m; i++)
			for (int j = 0; j < n; j++)
				v[i][j] = c.v[i][j];
				
		return *this;
	}


/*******************************************/
	void display() {
		cout << "Matrix:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cout << v[i][j] << " ";
			cout << endl;
		}
	}
	~CVector() {
		if (v != NULL) {
			for (int i = 0; i < m; i++) delete[] v[i];
			delete[]v;
		}
	}
};
int main() {
	int t,m, n;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		int** a;
		a = new int*[m];
		for (int i = 0; i < m; i++)
			a[i] = new int[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		CVector obj1(a, m, n);
		CVector obj2 = obj1;
		CVector obj3;
		obj3 = obj2;
		obj3.display();
		if (a != NULL) {
			for (int i = 0; i < m; i++) delete[] a[i];
			delete[]a;
		}
	}
	return 0;
}

