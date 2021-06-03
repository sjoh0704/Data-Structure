#pragma once
#include <iostream>
#include "BST.h"
#include<queue>
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
	RBT(btElementType _treeData, Color color, bool _nullTree);
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
protected:
	Color color;
};
template<class btElementType>
RBT<btElementType>::RBT() {
	BST<int>::BST();
	color = Black;
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
	else if (d < data)
		leftTree->insert(d);
	else
		rightTree->insert(d);

}
