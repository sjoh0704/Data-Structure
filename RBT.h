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
	// intacteristics : BinaryTree와 BST를 상속받은 노드는 오른쪽 왼쪽의 노드만을 가지며 데이터를 넣는데,
	//                              크기를 비교하여 넣는 BST 규칙을 따르지만, RBT에는 각 노드가 색깔을 가지며 RB Tree의 규칙에 
	//								위배되지 않게끔 insert된다. 삭제할 때도 마찬가지로 RB Tree의 특성에 맞게 삭제된다.
	RBT();
	RBT(btElementType _treeData, Color color, bool _nullTree);
	void insert(btElementType& d);
	// Precondition : insert할 데이터를 받아옴
	// Postcondition : 색깔에 따른 Red Black Tree로 변환하여 insert됨
	void fixViolation(RBT*& root, RBT*& pt);
	// Postcondition : Case1, Case2, Case3의 상황에 따라 실행하여 위반한 규칙을 고침
	RBT <btElementType>* BSTInsert(RBT* root, RBT* pt, btElementType& d);
	// Precondition: 만약 d가 left child이면, 아버지 노드의 데이터보다 작아야한다.
	//							만약 d가 right child이면, 아버지 노드의 데이터보다 커야한다.
	// Postcondition : BST처럼 insert를 하여 BinaryTree와 다르게 parentTree 값도 설정
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
