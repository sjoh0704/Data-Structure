// practice 17
// binary tree
#pragma once
#include<assert.h>
template<class btElementType>
class BinaryTree
{
public:
	BinaryTree();
	bool isEmpty();
	virtual void insert(const btElementType& data);
	btElementType getData();
	BinaryTree* left();
	BinaryTree* right();
	void makeLeft(BinaryTree* T1);
	void makeRight(BinaryTree* T2);


protected:
	bool nullTree;
	BinaryTree* leftTree;
	BinaryTree* rightTree;
	btElementType data;

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
void
BinaryTree<btElementType>::insert(const btElementType& data) {
	assert(isEmpty());
	if (nullTree) {
		nullTree = false;
		leftTree = new BinaryTree();
		rightTree = new BinaryTree();
		this->data = data;
	}
}
template<class btElementType>
btElementType
BinaryTree<btElementType>::getData() {
	assert(!isEmpty());
	return data;
}

template<class btElementType>
BinaryTree<btElementType>*
BinaryTree<btElementType>::left(){
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
BinaryTree<btElementType>::makeLeft(BinaryTree* T1) {
	assert(!isEmpty());
	assert(left()->isEmpty());
	delete left();
	leftTree = T1;
}

template<class btElementType>
void
BinaryTree<btElementType>::makeRight(BinaryTree* T2) {
	assert(!isEmpty());
	assert(right()->isEmpty());
	delete rightTree;
	rightTree = T2;
}