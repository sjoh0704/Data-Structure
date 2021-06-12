#pragma once
#include <iostream>
#include "BST.h"
#include<queue>

enum Color { RedTree, BlackTree };

template < class btElementType >
class RBTree : public BST <int>
{
public:
	// intacteristics : BinaryTree�� BST�� ��ӹ��� ���� ������ ������ ��常�� ������ �����͸� �ִµ�,
	//                              ũ�⸦ ���Ͽ� �ִ� BST ��Ģ�� ��������, RBTree���� �� ��尡 ������ ������ RB Tree�� ��Ģ�� 
	//								������� �ʰԲ� insert�ȴ�. ������ ���� ���������� RB Tree�� Ư���� �°� �����ȴ�.
	RBTree();
	RBTree(btElementType _treeData, Color color, bool _nullTree);
	void insert(btElementType& d);
	// Precondition : insert�� �����͸� �޾ƿ�
	// Postcondition : ���� ���� Red Black Tree�� ��ȯ�Ͽ� insert��
	void fixViolation(RBTree*& root, RBTree*& pt);
	// Postcondition : Case1, Case2, Case3�� ��Ȳ�� ���� �����Ͽ� ������ ��Ģ�� ��ħ
	RBTree <btElementType>* BSTInsert(RBTree* root, RBTree* pt, btElementType& d);
	// Precondition: ���� d�� left child�̸�, �ƹ��� ����� �����ͺ��� �۾ƾ��Ѵ�.
	//							���� d�� right child�̸�, �ƹ��� ����� �����ͺ��� Ŀ���Ѵ�.
	// Postcondition : BSTó�� insert�� �Ͽ� BinaryTree�� �ٸ��� parentTree ���� ����
	// Return : insert�� BST Tree �ּҸ� ��ȯ
	void rotateLeft(RBTree*& root, RBTree*& pt);
	// Postcondition : RBTree�� RotateLeft ��
	void rotateRight(RBTree*& root, RBTree*& pt);
	// Postcondition : RBTree�� RotateRight ��
	void  print_Level_Order(btElementType nullData);
	// Precondition : ��尡 �ϳ� �̻� �־���ϰ�, null�� ���� main���� �����ص� nulldata�� 
	//							nullData��� �μ��� �ѱ�
	// Postconditions : RBT Tree�� ����ϵ�, Ʈ���� ����� ���� ���� ���ο� �������� Null Node�� �����.
	//								���� 3��° �ٱ��� �����ϴ�, ������ �ٺ��ʹ� null�� �����ϱ⿡ ������ 2���� ��� �����Ѵ�.
	//								���������� Ʈ�� ����� ���� �����Ͱ� �ִ� ������ null�� ���
	void Print_Color();
	// Postcondition: ����� color�� '��', '��' �� �� �ϳ��� ���
	bool Search_Line(queue<RBTree*> q, btElementType nullData);
	// Precondition : Print_Level_Order �Լ����� ť�� �޾ƿ�
	// Return : ť�� �ִ� ���� �߿� Child�� �ϳ��� ������ True ��ȯ
protected:
private:
	RBTree* root;
	Color color;
};

template < class btElementType >
RBTree <btElementType> ::RBTree() : BST() {
	root = 0;
	color = RedTree;
}
template < class btElementType >
RBTree <btElementType> ::RBTree(btElementType _treeData, Color _color, bool _nullTree) : BST(_treeData, _nullTree) {
	root = 0;
	color = _color;
}
template < class btElementType >
void  RBTree <btElementType> ::print_Level_Order(btElementType nullData)
{
	if (root == NULL)  return;
	queue<RBTree*> q;
	q.push(root);
	int enter(0), store(0), pre_store(0);
	cout << endl << "\t\t\t\t";
	while (!q.empty())
	{
		RBTree* node = q.front();
		RBTree* bin = new RBTree(nullData, BlackTree, false);
		if (node->getData() == nullData) {
			cout << " [null"; ((RBTree <btElementType>*) node)->Print_Color(); cout << "]";
		}
		else {
			cout << node->getData(); ((RBTree <btElementType>*)node)->Print_Color(); cout << "]";
		}
		q.pop();
		if (enter == 0 || enter == 2 || enter == store + 2 * (store - pre_store)) {
			cout << endl;
			pre_store = store;
			store = enter;
		}
		if (enter == 0 || enter == 1) cout << "\t\t";
		if (enter >= 2 && enter <= 5) cout << "\t";
		if (enter >= 6 && enter <= 13) cout << " ";
		enter++;
		if (node->left() != 0 && !(node->left()->isEmpty()))		// ������ ������� ������ ������ push
			q.push(((RBTree <btElementType>*)node->left()));
		if (node->left() != 0 && node->right() != 0 && (node->left()->isEmpty() && !(node->right()->isEmpty())))	// ������ ������� �������� �� ����� �� Null ��� push
			q.push(bin);
		if (node->right() != 0 && !(node->right()->isEmpty())) // �������� ������� ������ �������� push
			q.push(((RBTree <btElementType>*)node->right()));
		if (node->right() != 0 && node->left() != 0 && (!(node->left()->isEmpty()) && (node->right()->isEmpty())))	// �������� ������� ������ �� ����� �� Null��� push
			q.push(bin);
		if (Search_Line(q, nullData) && q.size() != 0 && node->right() != 0 && node->left() != 0 && (node->left()->isEmpty() && node->right()->isEmpty())) {
			q.push(bin);										// ���� ������ ���ο� ��尡 �ϳ� �̻� �ְ�. ������ ���� �� �� ����� �� Null ��� �ι� push
			q.push(bin);
		}
		else if (Search_Line(q, nullData) && q.size() != 0 && (node->left() == 0 && node->right() == 0)) {
			q.push(bin);										// ���� ������ ���ο� ��尡 �ϳ� �̻� �ְ�. ������ ���� �� �� ����µ�, �ڱ� �ڽŵ� NULL�� �� Null ��� �ι� push
			q.push(bin);
		}
	}
	cout << endl;
}
template < class btElementType >
bool RBTree < btElementType > ::Search_Line(queue<RBTree*> q, btElementType nullData)
{
	for (; !q.empty(); q.pop())
		if (!(q.front()->getData() == nullData) && !(((RBTree < btElementType >*)q.front())->leftTree == 0) && !(((RBTree < btElementType >*)q.front())->rightTree == 0) && (!(((RBTree < btElementType >*)q.front())->rightTree->isEmpty()) || !(((RBTree < btElementType >*)q.front())->leftTree->isEmpty())))
			return true;
	return false;
}

template < class btElementType >
void RBTree <btElementType>::insert(btElementType& d)
{
	
	RBTree* pt = new RBTree(d, RedTree, false);
	root = BSTInsert(root, pt, d);
	fixViolation(root, pt);
}

template < class btElementType >
RBTree <btElementType>* RBTree <btElementType>::BSTInsert(RBTree* root, RBTree* pt, btElementType& d)
{
	if (root == NULL || root->isEmpty()) {
		pt->leftTree = new RBTree(d, BlackTree, true);
		pt->rightTree = new RBTree(d, BlackTree, true);
		return pt;
	}
	if (pt->getData() < root->getData())
	{
		root->leftTree = BSTInsert(((RBTree < btElementType >*)root->left()), pt, d);
		((RBTree < btElementType >*)root->left())->parentTree = root;
	}
	else if (pt->getData() > root->getData())
	{
		root->rightTree = BSTInsert(((RBTree < btElementType >*)root->right()), pt, d);
		((RBTree < btElementType >*)root->right())->parentTree = root;
	}
	return root;
}

template < class btElementType >
void RBTree<btElementType>::fixViolation(RBTree*& root, RBTree*& pt)
{
	RBTree* parent_pt = NULL;
	RBTree* grand_parent_pt = NULL;

	while ((pt != root) && (pt->color != BlackTree) && (((RBTree < btElementType >*)pt->parent())->color == RedTree))
	{
		parent_pt = ((RBTree < btElementType >*)pt->parent());
		grand_parent_pt = ((RBTree < btElementType >*)pt->parent()->parent());

		// Case A : pt�� �ƹ����� �Ҿƹ����� ���� child
		if (parent_pt == grand_parent_pt->left())
		{
			RBTree* uncle_pt = ((RBTree < btElementType >*)grand_parent_pt->right());

			// Case1 : ���� ���� ����, ���� Recoloring ����
			if (!uncle_pt->isEmpty() && ((RBTree < btElementType >*)uncle_pt)->color == RedTree)
			{
				grand_parent_pt->color = RedTree;
				parent_pt->color = BlackTree;
				uncle_pt->color = BlackTree;
				pt = grand_parent_pt;
			}
			else {
				// Case2 : pt�� �� �ƹ����� ������ Child, Left-Rotate����
				if (pt == parent_pt->right())
				{
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = ((RBTree < btElementType >*)pt->parent());
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
			RBTree* uncle_pt = ((RBTree < btElementType >*)grand_parent_pt->left());
			// Case1 : pt�� ������ ���� ������, ������ Recoloring ����
			if ((!uncle_pt->isEmpty()) && (uncle_pt->color == RedTree)) {
				grand_parent_pt->color = RedTree;
				parent_pt->color = BlackTree;
				uncle_pt->color = BlackTree;
				pt = grand_parent_pt;
			}
			else {
				// Case2 : pt�� �� �ƹ����� ���� Child, Right-Rotate����
				if (pt == parent_pt->left()) {
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = ((RBTree < btElementType >*)pt->parent());
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
	root->color = BlackTree;
}

template <class btElementType>
void RBTree<btElementType>::rotateLeft(RBTree*& root, RBTree*& pt)
{
	RBTree* pt_right = ((RBTree < btElementType >*)pt->right());

	((RBTree < btElementType >*)pt)->rightTree = pt_right->left();

	if (!pt->right()->isEmpty())
		((RBTree < btElementType >*)pt->right())->parentTree = pt;

	pt_right->parentTree = pt->parent();

	if (pt->parentTree == NULL)
		root = pt_right;

	else if (pt == ((RBTree < btElementType >*)pt->parent())->leftTree)
		((RBTree < btElementType >*)pt->parent())->leftTree = pt_right;

	else
		((RBTree < btElementType >*) pt->parent())->rightTree = pt_right;

	pt_right->leftTree = pt;
	pt->parentTree = pt_right;
}



template <class btElementType>
void RBTree<btElementType>::rotateRight(RBTree*& root, RBTree*& pt)
{
	RBTree* pt_left = ((RBTree < btElementType >*)pt->left());

	((RBTree < btElementType >*)pt)->leftTree = pt_left->right();

	if (!pt->left()->isEmpty())
		((RBTree < btElementType >*)pt->left())->parentTree = pt;

	pt_left->parentTree = pt->parent();

	if (pt->parentTree == NULL)
		root = pt_left;

	else if (pt == ((RBTree < btElementType >*)pt->parent())->leftTree)
		((RBTree < btElementType >*)pt->parent())->leftTree = pt_left;

	else
		((RBTree < btElementType >*) pt->parent())->rightTree = pt_left;

	pt_left->rightTree = pt;
	pt->parentTree = pt_left;
}

template < class btElementType >
void RBTree < btElementType > ::Print_Color()
{
	if (color == 0)
		cout << "��";
	else if (color == 1)
		cout << "��";
}