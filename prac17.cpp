//practice 17
//binary tree
#include<iostream>
#include"BinaryTree.h"
using namespace std;
int main() {
	cout << "20160518 ©ю╫баж" << endl;
	BinaryTree<char> bt1;
	bt1.insert('G');
	bt1.left()->insert('E');
	bt1.right()->insert('F');
	bt1.left()->left()->insert('A');
	bt1.left()->right()->insert('B');
	bt1.right()->left()->insert('C');
	bt1.right()->right()->insert('D');
	
	cout << bt1.getData() << endl;
	cout << bt1.left()->getData() << "\t";
	cout << bt1.right()->getData() << endl;
	cout << bt1.left()->left()->getData() << "\t";
	cout << bt1.left()->right()->getData() << "\t";
	cout << bt1.right()->left()->getData() << "\t";
	cout << bt1.right()->right()->getData() << endl;

	return 0;
}
