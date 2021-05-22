#pragma once
#include"BinaryTree.h"
template<class btElementType>
class BST : public BinaryTree<btElementType> {
public:
	BST();
	virtual void insert(const btElementType& data);
	virtual BinaryTree<btElementType>* retreive(const btElementType& data);

};


template<class btElementType>
void
BST<btElementType>::insert(const btElementType& data) {
	if (this->nullTree) {
		this->nullTree = false;
		this->leftTree = new BST;
		this->rightTree = new BST;
		this->data = data;
	}
	else if (this->data == data) {
		this->data = data;
	}
	else if (data < this->data)
		this->leftTree->insert(data);
	else
		this->rightTree->insert(data);
}

template<class btElementType>
BinaryTree<btElementType>*
BST<btElementType>::retreive(const btElementType& data) {
	if (this->nullTree | data == this->data)
		return this;
	else if (data < this->data)
		return (BST<btElementType>*)(this->leftTree)->retreive(data);
	else
		return (BST<btElementType>*)(this->rightTree)->retreive(data);
}

template<class btElementType>
BST<btElementType>::BST() {

}


