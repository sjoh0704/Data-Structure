#include<iostream>
#include<assert.h>
using namespace std;
template<class StackeElementType>
class MyStack {
public:
	MyStack();
	void push(StackeElementType item);
	StackeElementType pop();
	StackeElementType top();
	bool isEmpty();
private:
	struct Node;
	typedef Node* Link;
	struct Node {
		StackeElementType data;
		Link next;
	};
	Link head;
};


template<class StackElementType>
MyStack<StackElementType>::MyStack() {
	head = 0;
}

template<class StackElementType>
void
MyStack<StackElementType>::push(StackElementType data) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->data = data;
	addedNode->next = head;
	head = addedNode;

}
template<class StackElementType>
StackElementType
MyStack<StackElementType>::pop() {
	assert(head);
	StackElementType returnItem = head->data;
	Link delNode = head;
	head = head->next;
	delete delNode;
	return returnItem;

}
template<class StackElementType>
StackElementType
MyStack<StackElementType>::top() {
	assert(head);
	return head->data;

}
template<class StackElementType>
bool
MyStack<StackElementType>::isEmpty() {
	return head == 0;
}


int main() {

	char charArray[6] = {'H', 'e', 'l', 'l', 'o', '!'};
	MyStack<char> s;
	for (int i = 0; i < 6; i++)
		s.push(charArray[i]);

	while (!s.isEmpty())
		cout << s.pop() << endl;




	return 0;
}