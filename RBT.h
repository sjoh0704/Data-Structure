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
	// intacteristics : BinaryTree와 BST를 상속받은 노드는 오른쪽 왼쪽의 노드만을 가지며 데이터를 넣는데,
	//                              크기를 비교하여 넣는 BST 규칙을 따르지만, RBT에는 각 노드가 색깔을 가지며 RB Tree의 규칙에 
	//								위배되지 않게끔 insert된다. 삭제할 때도 마찬가지로 RB Tree의 특성에 맞게 삭제된다.
	RBT();
	
	void insert(btElementType& d);
	// Precondition : insert할 데이터를 받아옴
	// Postcondition : 색깔에 따른 Red Black Tree로 변환하여 insert됨
	void fixViolation(RBT*& root, RBT*& pt);
	// Postcondition : Case1, Case2, Case3의 상황에 따라 실행하여 위반한 규칙을 고침
	RBT <btElementType>* getRoot(RBT* root, RBT* pt, btElementType& d);
	// Precondition: 만약 d가 left child이면, 아버지 노드의 데이터보다 작아야한다.
	//							만약 d가 right child이면, 아버지 노드의 데이터보다 커야한다.
	// Postcondition : BST처럼 insert를 하여 BinaryTree와 다르게 parent 값도 설정
	// Return : insert된 BST Tree 주소를 반환
	void rotateLeft(RBT*& root, RBT*& pt);
	// Postcondition : RBT가 RotateLeft 됨
	void rotateRight(RBT*& root, RBT*& pt);
	// Postcondition : RBT가 RotateRight 됨
	void  print_Level_Order(btElementType nullData);
	// Precondition : 노드가 하나 이상 있어야하고, null일 때는 main에서 지정해둔 nulldata를 
	//							nullData라는 인수로 넘김
	// Postconditions : RBT Tree를 출력하되, 트리의 모양을 위해 같은 라인에 왼쪽편의 Null Node를 출력함.
	//								탭은 3번째 줄까지 정렬하니, 나머지 줄부터는 null로 나열하기에 개수를 2개씩 세어서 구분한다.
	//								마지막줄은 트리 모양을 위해 데이터가 있는 노드까지 null을 출력
	void Print_Color();
	// Postcondition: 노드의 color를 '검', '빨' 둘 중 하나로 출력
	bool Search_Line(queue<RBT*> q, btElementType nullData);
	// Precondition : Print_Level_Order 함수에서 큐를 받아옴
	// Return : 큐에 있는 노드들 중에 Child가 하나라도 있으면 True 반환
	string getColor();
	RBT <btElementType>* left();
	RBT <btElementType>* right();

	friend void printTree(RBT* start);
	void printCase();
protected:
	RBT(btElementType data, Color color, bool nullTree);
	Color color;
	RBT* root;
	RBT* parent;
};


template<class btElementType>
RBT<btElementType>::RBT() : BST(){

	color = Red;
	root = 0;

}


template<class btElementType>
RBT<btElementType>::RBT(btElementType data, Color color, bool nullTree){
	this->data = data;
	this->color = color;
	this->nullTree = nullTree;

}

//template<class btElementType>
//void 
//RBT<btElementType>::insert(btElementType& d) {
//
//	if (nullTree) {
//		nullTree = false;
//		leftTree = new RBT;
//		rightTree = new RBT;
//		data = d;
//		color = Red;
//	}
//	else if (data == d) {
//		data = d;
//	}
//	else if (d < data) {
//		left()->insert(d);
//		/*cout << typeid(leftTree).name() << endl;*/
//	}
//	else
//		right()->insert(d);
//
//}

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
	cout << endl;
	cout << "fix steps" << endl;

	RBT* parent_pt = NULL;
	RBT* grand_parent_pt = NULL;

	while ((pt != root) && (pt->color != Black) && (pt->parent->color == Red))
	{
		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		// Case A : pt의 아버지는 할아버지의 왼쪽 child
		if (parent_pt == grand_parent_pt->left())
		{
			RBT* uncle_pt = grand_parent_pt->right();

			// Case1 : 삼촌 또한 빨강, 오직 Recoloring 실행
			if (!uncle_pt->isEmpty() && uncle_pt->color == Red){
				grand_parent_pt->color = Red;
				parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = grand_parent_pt;
				
			}
			else {
				// Case2 : pt는 그 아버지의 오른쪽 Child, Left-Rotate실행
				if (pt == parent_pt->right())
				{
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
					
				}
				// Case3 : pt는 그 아버지의 왼쪽 Child, Right-Rotate실행
				rotateRight(root, grand_parent_pt);
				Color tmp = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = tmp;
				pt = parent_pt;
				
			}
		}

		// CaseB : pt의 아버지는 할아버지의 오른쪽 Child
		else {
			printCase();
			RBT* uncle_pt = grand_parent_pt->left();
			// Case1 : pt의 삼촌은 또한 빨간색, 오로지 Recoloring 실행
			if ((!uncle_pt->isEmpty()) && (uncle_pt->color == Red)) {
				grand_parent_pt->color = Red;
				parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = grand_parent_pt;
				printCase();
			
			
			}
			else {
		
				// Case2 : pt는 그 아버지의 왼쪽 Child, Right-Rotate실행
				if (pt == parent_pt->left()) {
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
					printCase();
					
				}
				// Case3 : pt는 그 아버지의 오른쪽 Child, Left-Rotate실행
				rotateLeft(root, grand_parent_pt);
				Color tmp = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = tmp;
				pt = parent_pt;
				printCase();
			}
		}
	}
	root->color = Black;
}

template <class btElementType>
void RBT<btElementType>::rotateLeft(RBT*& root, RBT*& pt)
{
	RBT* pt_right = pt->right();

	pt->rightTree = pt_right->left();

	if (!pt->right()->isEmpty())
		pt->right()->parent = pt;

	pt_right->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_right;

	else if (pt == pt->parent->leftTree)
	pt->parent->leftTree = pt_right;

	else
		pt->parent->rightTree = pt_right;

	pt_right->leftTree = pt;
	pt->parent = pt_right;
}



template <class btElementType>
void RBT<btElementType>::rotateRight(RBT*& root, RBT*& pt)
{
	RBT* pt_left = pt->left();

	pt->leftTree = pt_left->right();

	if (!pt->left()->isEmpty())
		pt->left()->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_left;

	else if (pt == pt->parent->leftTree)
		pt->parent->leftTree = pt_left;

	else
		pt->parent->rightTree = pt_left;

	pt_left->rightTree = pt;
	pt->parent = pt_left;
}

template < class btElementType >
void RBT <btElementType>::insert(btElementType& d)
{
	RBT<btElementType>* pt = new RBT(d, Red, false);
	//cout << pt->root << endl;
	root = getRoot(root, pt, d);

	fixViolation(root, pt);
}

template < class btElementType >
RBT <btElementType>* RBT <btElementType>::getRoot(RBT* root, RBT* pt, btElementType& d)
{
	if (root == NULL || root->isEmpty()) {
		pt->leftTree = new RBT(d, Black, true);
		pt->rightTree = new RBT(d, Black, true);
		
		return pt;
	}
	if (pt->getData() < root->getData())
	{
		root->leftTree = getRoot(root->left(), pt, d);
		root->left()->parent = root;
	}
	else if (pt->getData() > root->getData())
	{
		root->rightTree = getRoot(root->right(), pt, d);
		root->right()->parent = root;
	}
	return root;
}
template < class btElementType >
void
RBT <btElementType>::printCase() {
	cout << endl;
	cout << "---------------------------case--------------------------" << endl;

	if (root->isEmpty())
		cout << "\t\t" << 0;
	else {
		cout << "\t\t" << root->getData() << "/" << root->getColor() << endl;


		if (root->left()->isEmpty())
			cout << "\t" << 0;
		else {
			cout << "\t" << root->left()->getData() << "/" << root->left()->getColor();
		}

		if (root->right()->isEmpty())
			cout << "\t\t" << 0 << endl;
		else {
			cout << "\t\t" << root->right()->getData() << "/" << root->right()->getColor() << endl;
		}

		if (root->left()->isEmpty()||root->left()->left()->isEmpty())
			cout << 0;
		else
			cout << root->left()->left()->getData() << "/" << root->left()->left()->getColor();

		if (root->left()->isEmpty() || root->left()->right()->isEmpty())
			cout << "\t\t" << 0;
		else
			cout << "\t\t" << root->left()->right()->getData() << "/" << root->left()->right()->getColor();
		cout << "  ";
		if (root->right()->isEmpty() || root->right()->left()->isEmpty())
			cout << "" << 0;
		else
			cout << "" << root->right()->left()->getData() << "/" << root->right()->left()->getColor();


		if (root->right()->isEmpty() || root->right()->right()->isEmpty())
			cout << "\t\t" << 0 << endl;
		else
			cout << "\t\t" << root->right()->right()->getData() << "/" << root->right()->right()->getColor() << endl;;


		if (root->right()->isEmpty() || root->right()->right()->isEmpty() || root->right()->right()->left()->isEmpty())
			cout << "\t\t\t";
		else
			cout << "\t\t\t" << root->right()->right()->left()->getData() << "/" << root->right()->right()->left()->getColor();
		if (root->right()->isEmpty() || root->right()->right()->isEmpty() || root->right()->right()->right()->isEmpty())
			cout << endl;
		else
			cout << "\t\t" << root->right()->right()->right()->getData() << "/" << root->right()->right()->right()->getColor();


	}
}