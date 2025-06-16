#include<iostream>
using namespace std;

class Num {
	int n, m;
	int** data;

public:

	

	Num(int n=0, int m=0) {
		this->n=n;
		this->m=m;
		data = new int* [n];
		for (int i = 0; i < n; i++) {
			data[i] = new int[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> data[i][j];
			}
		}
	}

//	Num(int n, int m, int** p) {
//		this->n = n;
//		this->m = m;
//		data = new int* [n];
//		for (int i = 0; i < n; i++) {
//			data[i] = new int[m];
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				data[i][j] = p[i][j];
//			}
//		}
//
//		for (int i = 0; i < n; i++) {
//			delete p[i];
//		}delete[]p;
//	}



	~Num() {
		for (int i = 0; i < n; i++) {
			delete data[i];
		}delete[]data;
	}

	Num operator +(Num& y) {
		Num h;
		h.n = n;
		h.m = m;
		int** p = new int* [n];
		for (int i = 0; i < n; i++) {
			p[i] = new int[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				p[i][j] = data[i][j] + y.data[i][j];
			}
		}
		h.data = p;

		return h;
	}

	void display() {
		
		for (int i = 0; i < n; i++) {
			cout << data[i][0];
			for (int j = 1; j < m; j++) {
				cout << " " << data[i][j];
			}cout << endl;
		}
	}
};

int main() {
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int n, m;
		cin >> n >> m;
		Num a(n, m);
	
		Num b(n, m);
		(a + b).display();

	}
	return 0;
}
