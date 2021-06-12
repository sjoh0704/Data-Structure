//practice06
//20160518 ©ю╫баж
//list array
#include<iostream>
#include"List.h"
using namespace std;
int main() {
	List l;
	int x;
	cin >> x;
	while (x != 0) {
		l.insert(x);
		cin >> x;
	}
	ListElementType elem;
	bool notEmpty = l.first(elem);
	while (notEmpty) {
		cout << elem << endl;
		notEmpty = l.next(elem);
	}

	return 0;
}