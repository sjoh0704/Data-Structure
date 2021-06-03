#pragma once
#include <iostream>
#include "BST.h"
#include<queue>
#include<string>
using namespace std;
enum Color {Red, Black};

template < class btElementType >
class RBT : public BST <int>
{
public:
	// intacteristics : BinaryTree�� BST�� ��ӹ��� ���� ������ ������ ��常�� ������ �����͸� �ִµ�,
	//                              ũ�⸦ ���Ͽ� �ִ� BST ��Ģ�� ��������, RBT���� �� ��尡 ������ ������ RB Tree�� ��Ģ�� 
	//								������� �ʰԲ� insert�ȴ�. ������ ���� ���������� RB Tree�� Ư���� �°� �����ȴ�.
	RBT();
	
	void insert(btElementType& d);
	// Precondition : insert�� �����͸� �޾ƿ�
	// Postcondition : ���� ���� Red Black Tree�� ��ȯ�Ͽ� insert��
	void fixViolation(RBT*& root, RBT*& pt);
	// Postcondition : Case1, Case2, Case3�� ��Ȳ�� ���� �����Ͽ� ������ ��Ģ�� ��ħ
	RBT <btElementType>* BSTInsert(RBT* root, RBT* pt, btElementType& d);
	// Precondition: ���� d�� left child�̸�, �ƹ��� ����� �����ͺ��� �۾ƾ��Ѵ�.
	//							���� d�� right child�̸�, �ƹ��� ����� �����ͺ��� Ŀ���Ѵ�.
	// Postcondition : BSTó�� insert�� �Ͽ� BinaryTree�� �ٸ��� parentTree ���� ����
	// Return : insert�� BST Tree �ּҸ� ��ȯ
	void rotateLeft(RBT*& root, RBT*& pt);
	// Postcondition : RBT�� RotateLeft ��
	void rotateRight(RBT*& root, RBT*& pt);
	// Postcondition : RBT�� RotateRight ��
	void  print_Level_Order(btElementType nullData);
	// Precondition : ��尡 �ϳ� �̻� �־���ϰ�, null�� ���� main���� �����ص� nulldata�� 
	//							nullData��� �μ��� �ѱ�
	// Postconditions : RBT Tree�� ����ϵ�, Ʈ���� ����� ���� ���� ���ο� �������� Null Node�� �����.
	//								���� 3��° �ٱ��� �����ϴ�, ������ �ٺ��ʹ� null�� �����ϱ⿡ ������ 2���� ��� �����Ѵ�.
	//								���������� Ʈ�� ����� ���� �����Ͱ� �ִ� ������ null�� ���
	void Print_Color();
	// Postcondition: ����� color�� '��', '��' �� �� �ϳ��� ���
	bool Search_Line(queue<RBT*> q, btElementType nullData);
	// Precondition : Print_Level_Order �Լ����� ť�� �޾ƿ�
	// Return : ť�� �ִ� ���� �߿� Child�� �ϳ��� ������ True ��ȯ
	string getColor();
	RBT <btElementType>* left();
	RBT <btElementType>* right();

protected:
	RBT(btElementType data, Color color, bool nullTree);
	Color color;
	RBT* root;
};
template<class btElementType>
RBT<btElementType>::RBT() {
	BST<int>::BST();
	color = Red;
	RBT<btElementType> *root;

}


template<class btElementType>
void 
RBT<btElementType>::insert(btElementType& d) {

	if (nullTree) {
		nullTree = false;
		leftTree = new RBT;
		rightTree = new RBT;
		data = d;
		color = Red;
	}
	else if (data == d) {
		data = d;
	}
	else if (d < data) {
		left()->insert(d);
		/*cout << typeid(leftTree).name() << endl;*/
	}
	else
		right()->insert(d);

}

template<class btElementType>
string
RBT<btElementType>::getColor() {
	if (color == Red)
		return "R";
	else if(color==Black)
		return "B";
}
template<class btElementType>
RBT <btElementType>* 
RBT<btElementType>::left() {
	return (RBT <btElementType>*)(BST::left());
}
template<class btElementType>
RBT <btElementType>* 
RBT<btElementType>::right() {
	return (RBT <btElementType>*)(BST::right());
}


template < class btElementType >
void RBT<btElementType>::fixViolation(RBT*& root, RBT*& pt)
{
	RBT* parent_pt = NULL;
	RBT* grand_parent_pt = NULL;

	while ((pt != root) && (pt->color != Black) && (((RBT < btElementType >*)pt->parent())->color == Red))
	{
		parent_pt = ((RBT < btElementType >*)pt->parent());
		grand_parent_pt = ((RBT < btElementType >*)pt->parent()->parent());

		// Case A : pt�� �ƹ����� �Ҿƹ����� ���� child
		if (parent_pt == grand_parent_pt->left())
		{
			RBT* uncle_pt = ((RBT < btElementType >*)grand_parent_pt->right());

			// Case1 : ���� ���� ����, ���� Recoloring ����
			if (!uncle_pt->isEmpty() && ((RBT < btElementType >*)uncle_pt)->color == Red)
			{
				grand_parent_pt->color = Red;
				parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = grand_parent_pt;
			}
			else {
				// Case2 : pt�� �� �ƹ����� ������ Child, Left-Rotate����
				if (pt == parent_pt->right())
				{
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = ((RBT < btElementType >*)pt->parent());
				}
				// Case3 : pt�� �� �ƹ����� ���� Child, Right-Rotate����
				rotateRight(root, grand_parent_pt);
				Color temp = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = temp;
				pt = parent_pt;
			}
		}

		// CaseB : pt�� �ƹ����� �Ҿƹ����� ������ Child
		else {
			RBT* uncle_pt = ((RBT < btElementType >*)grand_parent_pt->left());
			// Case1 : pt�� ������ ���� ������, ������ Recoloring ����
			if ((!uncle_pt->isEmpty()) && (uncle_pt->color == Red)) {
				grand_parent_pt->color = Red;
				parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = grand_parent_pt;
			}
			else {
				// Case2 : pt�� �� �ƹ����� ���� Child, Right-Rotate����
				if (pt == parent_pt->left()) {
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = ((RBT < btElementType >*)pt->parent());
				}
				// Case3 : pt�� �� �ƹ����� ������ Child, Left-Rotate����
				rotateLeft(root, grand_parent_pt);
				Color temp = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = temp;
				pt = parent_pt;
			}
		}
	}
	root->color = Black;
}

template <class btElementType>
void RBT<btElementType>::rotateLeft(RBT*& root, RBT*& pt)
{
	RBT* pt_right = ((RBT < btElementType >*)pt->right());

	((RBT < btElementType >*)pt)->rightTree = pt_right->left();

	if (!pt->right()->isEmpty())
		((RBT < btElementType >*)pt->right())->parentTree = pt;

	pt_right->parentTree = pt->parent();

	if (pt->parentTree == NULL)
		root = pt_right;

	else if (pt == ((RBT < btElementType >*)pt->parent())->leftTree)
		((RBT < btElementType >*)pt->parent())->leftTree = pt_right;

	else
		((RBT < btElementType >*) pt->parent())->rightTree = pt_right;

	pt_right->leftTree = pt;
	pt->parentTree = pt_right;
}



template <class btElementType>
void RBT<btElementType>::rotateRight(RBT*& root, RBT*& pt)
{
	RBT* pt_left = ((RBT < btElementType >*)pt->left());

	((RBT < btElementType >*)pt)->leftTree = pt_left->right();

	if (!pt->left()->isEmpty())
		((RBT < btElementType >*)pt->left())->parentTree = pt;

	pt_left->parentTree = pt->parent();

	if (pt->parentTree == NULL)
		root = pt_left;

	else if (pt == ((RBT < btElementType >*)pt->parent())->leftTree)
		((RBT < btElementType >*)pt->parent())->leftTree = pt_left;

	else
		((RBT < btElementType >*) pt->parent())->rightTree = pt_left;

	pt_left->rightTree = pt;
	pt->parentTree = pt_left;
}

