//practice09
// dummy head linked list with remove function 
// 20160518 ������
#include<iostream>
#include"List4.h"
using namespace std;
int main() {
	List4 l = List4();
	ListElementType x;
	cin >> x;
	while (x) {
		l.insert(x);
		cin >> x;
	}
	cout << "\n���� ���� �Է�" << endl;

	ListElementType x2;
	cin >> x2;
	l.remove(x2);
	cout << "\n��� ���" << endl;
	ListElementType tmp;
	bool emptyCheck = l.first(tmp);
	while (emptyCheck) {
		cout << tmp << endl;
		emptyCheck = l.next(tmp);
	}

	return 0;
}