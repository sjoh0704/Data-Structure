#include<iostream>
#include"List2.h"
using namespace std;
int main() {

	cout << "���� �Է����ּ���" << endl;
	int x;
	List2 l = List2();
	cin >> x;
	while (x) {
		l.insert(x);
		cin >> x;
	}

	ListElementType elem; 
	bool emptyCheck = l.first(elem);
	while (emptyCheck) {
		cout << elem << endl;
		emptyCheck = l.next(elem);
	}


	return 0;
}