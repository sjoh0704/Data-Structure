#include<iostream>
#include"RBT.h"
using namespace std; 
int main() {
	typedef RBT<char> charRBT;
	typedef charRBT* RBTPtr;
	RBTPtr a = new charRBT;
	char v[10] = { 'a', 'b', 'c', 'd',  'e', 'f',  'g', 'h',  'i', 'j' };
	a->insert(v[0]);
	a->insert(v[1]);
	a->insert(v[2]);
	a->insert(v[3]);

	RBTPtr get11((RBTPtr)(a->retreive(v[4])));
	if (get11->isEmpty())
		cout << "not found" << endl;
	else
		cout << "found" << endl;

	return 0;
}