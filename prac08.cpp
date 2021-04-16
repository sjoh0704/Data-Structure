// in-order linked list  
#include<iostream>
#include"List3.h"
using namespace std;
int main() {
	List3 l = List3();
	ListElementType x;
	cin >> x;
	while (x) {
		l.insert(x);
		cin >> x;
	}

	ListElementType tmp;
	bool emptyCheck = l.first(tmp);
	while (emptyCheck) {
		cout << tmp << endl;
		emptyCheck = l.next(tmp);
	}

	return 0;
}