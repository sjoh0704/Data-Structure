// 실습 18 
// binary serach tree
#include<iostream>
#include"BST.h"
using namespace std;
int main() {
	cout << "20160518 오승주" << endl;
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

	cout << "11 찾기 결과: ";
	intBSTPtr get11((intBSTPtr)b->retreive(11));
	if (get11->isEmpty())
		cout << "not found" << endl;
	else
		cout << "found" << endl;
	cout << "\n13 찾기 결과: ";
	intBSTPtr get13((intBSTPtr)b->retreive(13));
	if (get13->isEmpty())
		cout << "not found" << endl;
	else
		cout << "found" << endl;

	return 0;
}