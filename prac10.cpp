#include"List5.h"
#include<iostream>
//practice- doubly linked list 
using namespace std;
int main() {

	List5 l = List5();
	ListElementType x;
	cin >> x;
	while (x) {
		l.insert(x);
		cin >> x;
	}

	ListElementType tmp;
	bool notEmpty = l.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);
	}

	notEmpty = l.previous(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.previous(tmp);
	}

	

	return 0;
}