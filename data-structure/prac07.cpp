//practice 7. Linked List
// 20160518 ©ю╫баж
#include<iostream>
#include"List2.h"
using namespace std;
int main() {

	ListElementType num;
	List2 l = List2();
	cin >> num;
	while (num) {
		l.insert(num);
		cin >> num;
	}

	ListElementType tmp;
	bool emptyCheck = l.first(tmp);
	while (emptyCheck) {
		cout << tmp << endl;
		emptyCheck = l.next(tmp);
	}

	return 0;
}