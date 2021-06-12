#pragma once
#include <iostream>
#include "BST.h"
#include<queue>

enum Color { RedTree, BlackTree };

template < class btElementType >
class RBTree : public BST <int>
{
public:
	// intacteristics : BinaryTree와 BST를 상속받은 노드는 오른쪽 왼쪽의 노드만을 가지며 데이터를 넣는데,
	//                              크기를 비교하여 넣는 BST 규칙을 따르지만, RBTree에는 각 노드가 색깔을 가지며 RB Tree의 규칙에 
	//								위배되지 않게끔 insert된다. 삭제할 때도 마찬가지로 RB Tree의 특성에 맞게 삭제된다.
	RBTree();
	RBTree(btElementType _treeData, Color color, bool _nullTree);
	void insert(btElementType& d);
	// Precondition : insert할 데이터를 받아옴
	// Postcondition : 색깔에 따른 Red Black Tree로 변환하여 insert됨
	void fixViolation(RBTree*& root, RBTree*& pt);
	// Postcondition : Case1, Case2, Case3의 상황에 따라 실행하여 위반한 규칙을 고침
	RBTree <btElementType>* BSTInsert(RBTree* root, RBTree* pt, btElementType& d);
	// Precondition: 만약 d가 left child이면, 아버지 노드의 데이터보다 작아야한다.
	//							만약 d가 right child이면, 아버지 노드의 데이터보다 커야한다.
	// Postcondition : BST처럼 insert를 하여 BinaryTree와 다르게 parentTree 값도 설정
	// Return : insert된 BST Tree 주소를 반환
	void rotateLeft(RBTree*& root, RBTree*& pt);
	// Postcondition : RBTree가 RotateLeft 됨
	void rotateRight(RBTree*& root, RBTree*& pt);
	// Postcondition : RBTree가 RotateRight 됨
	void  print_Level_Order(btElementType nullData);
	// Precondition : 노드가 하나 이상 있어야하고, null일 때는 main에서 지정해둔 nulldata를 
	//							nullData라는 인수로 넘김
	// Postconditions : RBT Tree를 출력하되, 트리의 모양을 위해 같은 라인에 왼쪽편의 Null Node를 출력함.
	//								탭은 3번째 줄까지 정렬하니, 나머지 줄부터는 null로 나열하기에 개수를 2개씩 세어서 구분한다.
	//								마지막줄은 트리 모양을 위해 데이터가 있는 노드까지 null을 출력
	void Print_Color();
	// Postcondition: 노드의 color를 '검', '빨' 둘 중 하나로 출력
	bool Search_Line(queue<RBTree*> q, btElementType nullData);
	// Precondition : Print_Level_Order 함수에서 큐를 받아옴
	// Return : 큐에 있는 노드들 중에 Child가 하나라도 있으면 True 반환
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
		if (node->left() != 0 && !(node->left()->isEmpty()))		// 왼쪽이 비어있지 않으면 왼쪽을 push
			q.push(((RBTree <btElementType>*)node->left()));
		if (node->left() != 0 && node->right() != 0 && (node->left()->isEmpty() && !(node->right()->isEmpty())))	// 왼쪽이 비었으며 오른쪽은 안 비었을 때 Null 노드 push
			q.push(bin);
		if (node->right() != 0 && !(node->right()->isEmpty())) // 오른쪽이 비어있지 않으면 오른쪽을 push
			q.push(((RBTree <btElementType>*)node->right()));
		if (node->right() != 0 && node->left() != 0 && (!(node->left()->isEmpty()) && (node->right()->isEmpty())))	// 오른쪽이 비었으며 왼쪽은 안 비었을 때 Null노드 push
			q.push(bin);
		if (Search_Line(q, nullData) && q.size() != 0 && node->right() != 0 && node->left() != 0 && (node->left()->isEmpty() && node->right()->isEmpty())) {
			q.push(bin);										// 같은 높이의 라인에 노드가 하나 이상 있고. 오른쪽 왼쪽 둘 다 비었을 때 Null 노드 두번 push
			q.push(bin);
		}
		else if (Search_Line(q, nullData) && q.size() != 0 && (node->left() == 0 && node->right() == 0)) {
			q.push(bin);										// 같은 높이의 라인에 노드가 하나 이상 있고. 오른쪽 왼쪽 둘 다 비었는데, 자기 자신도 NULL일 때 Null 노드 두번 push
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

		// Case A : pt의 아버지는 할아버지의 왼쪽 child
		if (parent_pt == grand_parent_pt->left())
		{
			RBTree* uncle_pt = ((RBTree < btElementType >*)grand_parent_pt->right());

			// Case1 : 삼촌 또한 빨강, 오직 Recoloring 실행
			if (!uncle_pt->isEmpty() && ((RBTree < btElementType >*)uncle_pt)->color == RedTree)
			{
				grand_parent_pt->color = RedTree;
				parent_pt->color = BlackTree;
				uncle_pt->color = BlackTree;
				pt = grand_parent_pt;
			}
			else {
				// Case2 : pt는 그 아버지의 오른쪽 Child, Left-Rotate실행
				if (pt == parent_pt->right())
				{
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = ((RBTree < btElementType >*)pt->parent());
				}
				// Case3 : pt는 그 아버지의 왼쪽 Child, Right-Rotate실행
				rotateRight(root, grand_parent_pt);
				Color temp = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = temp;
				pt = parent_pt;
			}
		}

		// CaseB : pt의 아버지는 할아버지의 오른쪽 Child
		else {
			RBTree* uncle_pt = ((RBTree < btElementType >*)grand_parent_pt->left());
			// Case1 : pt의 삼촌은 또한 빨간색, 오로지 Recoloring 실행
			if ((!uncle_pt->isEmpty()) && (uncle_pt->color == RedTree)) {
				grand_parent_pt->color = RedTree;
				parent_pt->color = BlackTree;
				uncle_pt->color = BlackTree;
				pt = grand_parent_pt;
			}
			else {
				// Case2 : pt는 그 아버지의 왼쪽 Child, Right-Rotate실행
				if (pt == parent_pt->left()) {
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = ((RBTree < btElementType >*)pt->parent());
				}
				// Case3 : pt는 그 아버지의 오른쪽 Child, Left-Rotate실행
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
		cout << "빨";
	else if (color == 1)
		cout << "검";
}