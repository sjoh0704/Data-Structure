#pragma once
#include"BinaryTree.h"
template<class btElementType>
class BST : public BinaryTree<int> { //���ø��� �̸� �μ��� �����ν� this�� ���� �ʰ� ���������� ����
public:
	BST();
	virtual void insert(const btElementType& data);
	virtual BinaryTree<btElementType>* retreive(const btElementType& data);

};


template<class btElementType>
void
BST<btElementType>::insert(const btElementType& d) {
	if (nullTree) {
		nullTree = false;
		leftTree = new BST;
		rightTree = new BST;
		data = d;
	}
	else if (data == d) {
		data = d;
	}
	else if (d < data)
		leftTree->insert(d);
	else
		rightTree->insert(d);
}

template<class btElementType>
BinaryTree<btElementType>*
BST<btElementType>::retreive(const btElementType& d) {
	if (nullTree || d == data)
		return this;
	else if (d < data)
		return ((BST<btElementType>*)leftTree)->retreive(d);
	else
		return ((BST<btElementType>*)rightTree)->retreive(d);
}

template<class btElementType>
BST<btElementType>::BST() {

}


