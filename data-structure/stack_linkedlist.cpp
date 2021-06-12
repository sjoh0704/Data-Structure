//stack made by linked list
#include<iostream>
#include<assert.h>
using namespace std;
template<class StackElementType>
class Stack2 {
public:
	Stack2();
	void push(StackElementType item);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();

private:
	struct Node;
	typedef Node* Link;
	struct Node {
		StackElementType item;
		Link next;
	};
	Link head;
};

template<class StackElementType>
Stack2<StackElementType>::Stack2() {
	head = 0;
}
template<class StackElementType>
void Stack2<StackElementType>::push(StackElementType item) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->item = item;
	addedNode->next = head;
	head = addedNode;

}

template<class StackElementType>
StackElementType Stack2<StackElementType>::pop() {
	assert(head);
	StackElementType item = head->item;
	Link delNode = head;
	head = head->next;
	delete delNode;
	return item;
}

template<class StackElementType>
StackElementType Stack2<StackElementType>::top() {

	return head->item;
}

template<class StackElementType>
bool Stack2<StackElementType>::isEmpty() {
	return head == 0;
}

int main() {
	
	Stack2<int> stack;
	int tmp;
	cin >> tmp;
	while (tmp) {
		
		stack.push(tmp);
		cin >> tmp;
	}

	while (!stack.isEmpty()) {
		cout << stack.pop() << endl;

	}



	return 0;
}