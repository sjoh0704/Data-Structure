#include<iostream>
#include<assert.h>
using namespace std;
template<class btElementType>
class BinaryTree {
public:
	BinaryTree();
	bool isEmpty();
	btElementType getData();
	void insert(const btElementType& d);
	BinaryTree<btElementType>* left(); // btElementType없이도 선언가능 
	BinaryTree<btElementType>* right();
	void makeLeft(BinaryTree<btElementType>* T1);  // const가 없어야 된다. 
	void makeRight(BinaryTree<btElementType>* T2);

private:
	bool nullTree;
	btElementType treeData;
	BinaryTree<btElementType>* leftTree;
	BinaryTree<btElementType>* rightTree;

};
template<class btElementType>
BinaryTree<btElementType>::BinaryTree() {
	nullTree = true;
	leftTree = 0;
	rightTree = 0;
}

template<class btElementType>
bool
BinaryTree<btElementType>::isEmpty() {
	return nullTree;
}

template<class btElementType>
btElementType
BinaryTree<btElementType>::getData() {
	assert(!isEmpty());
	return treeData;
}
 
template<class btElementType>
void
BinaryTree<btElementType>::insert(const btElementType& d) {
	treeData = d;
	if (nullTree) {
		nullTree = false;
		leftTree = new BinaryTree<btElementType>;
		rightTree = new BinaryTree<btElementType>;
	}
}
template<class btElementType>
BinaryTree<btElementType>*
BinaryTree<btElementType>::left() {
	assert(!isEmpty());
	return leftTree;
}
template<class btElementType>
BinaryTree<btElementType>*
BinaryTree<btElementType>::right() {
	assert(!isEmpty());
	return rightTree;
}

template<class btElementType>
void
BinaryTree<btElementType>::makeLeft(BinaryTree<btElementType>* T1) {
	assert(!isEmpty());
	assert(leftTree->isEmpty());
	delete leftTree;
	leftTree = T1;
}
template<class btElementType>
void
BinaryTree<btElementType>::makeRight(BinaryTree<btElementType>* T2) {
	assert(!isEmpty());
	assert(rightTree->isEmpty());
	delete rightTree;
	rightTree = T2;
}


int main() {
	typedef BinaryTree<int> intBT;
	typedef intBT* intBTPtr;
	intBTPtr b1 = new intBT;
	b1->insert(10);

	intBTPtr b2 = new intBT;
	b2->insert(15);

	intBTPtr b3 = new intBT;
	b3->insert(20);

	intBTPtr b4 = new intBT;
	b4->insert(17);

	intBTPtr b5 = new intBT;
	b5->insert(4);

	b1->makeLeft(b2);
	b1->makeRight(b3);

	b2->makeLeft(b4);
	b2->makeRight(b5);

	cout << b1->getData() << endl;;
	cout << b1->left()->getData() << '\t';
	cout << b1->right()->getData() << endl;
	cout << b1->left()->left()->getData() << ' ';
	cout << b1->left()->right()->getData() << endl;
	
	return 0;
}