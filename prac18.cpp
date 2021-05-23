// ½Ç½À 18 
// binary serach tree
#include<iostream>
#include"BST.h"
using namespace std;
int main() {

	typedef BST<int> intBST;
	typedef intBST* intBSTPtr;
	intBSTPtr b = new intBST;
	b->insert(17);
	b->insert(10);
	b->insert(26);
	b->insert(6);
	b->insert(14);
	b->insert(20);
	b->insert(28);
	b->insert(11);
	b->insert(31);
	b->insert(37);
	b->insert(12);
	
	intBSTPtr get11((intBSTPtr)b->retreive(11));
	if (get11->isEmpty())
		cout << "11 not found" << endl;
	else
		cout << "11 found" << endl;

	return 0;
}