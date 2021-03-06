#pragma once
#include"BinaryTree.h"
template<class btElementType>
class BST : public BinaryTree<int> { //템플릿에 미리 인수를 줌으로써 this를 쓰지 않고 변수참조가 가능
//class BST : public BinaryTree<char>{
public:
	BST();
	virtual void insert(const btElementType& data);
	virtual BST<btElementType>* retreive(const btElementType& data);

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
		((BST < btElementType >*) leftTree)->insert(d);

	else
		((BST < btElementType >*) rightTree)->insert(d);
}

template<class btElementType>
BST<btElementType>*
BST<btElementType>::retreive(const btElementType& d) {
	if (nullTree || d == data)
		return (BST<btElementType>*)this;
	else if (d < data)
		return ((BST<btElementType>*)leftTree)->retreive(d);
	else
		return ((BST<btElementType>*)rightTree)->retreive(d);
}

template<class btElementType>
BST<btElementType>::BST() {

}


