// ½Ç½À 18 
// binary serach tree
#include<iostream>
#include"BST.h"
int main() {

	typedef BST<int> intBST;
	typedef intBST* intBSTPtr;
	intBSTPtr b = new intBST;
	b->insert(17);
	b->insert(10);
	b->insert(26);
	b->insert(6);
	b->insert(14);


	return 0;
}