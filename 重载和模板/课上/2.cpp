#include <iostream>
using namespace std;

class CDate {
	int year, month, day;
public:
	CDate(int a = 0);
	operator int();
	void Print();
};

/********** Write your code here! **********/
CDate::CDate(int a){
	year =a/10000;
	month =a%10000/100;
	day=a%100;	
}

CDate::operator int(){
	int x=year*10000+month*100+day;
	return x;
}

void CDate::Print(){
	cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl; 
}

/*******************************************/

//������
int main() {
	int t, t1, t2;
	CDate C1, C2;
	cin >> t;
	while (t--) {
		cin >> t1 >> t2;
		C1 = t1;
		C2 = t2;
		((C1 > C2) ? C1 : C2).Print(); //���ڴ��������ڴ���C1>C2�У����Զ���C1��C2ת��Ϊ�������бȽ�
	}
	return 0;
}
