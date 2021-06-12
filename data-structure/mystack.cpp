#include<iostream>
#include<assert.h>
using namespace std;
const int maxStackSize = 1000;
template<class StackElementType>
class MyStack {
public:
	MyStack();
	void push(StackElementType item);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();
	bool isFull();
private:
	StackElementType stackArray[maxStackSize];
	int topIndex;
};

template<class StackElementType>
MyStack<StackElementType>::MyStack() {
	topIndex = 0;
}

template<class StackElementType>
void
MyStack<StackElementType>::push(StackElementType item) {
	topIndex++;
	assert(topIndex < maxStackSize);
	stackArray[topIndex] = item;
}

template<class StackElementType>
StackElementType
MyStack<StackElementType>::pop() {

	assert(topIndex >= 0);
	int returnIndex(topIndex);
	topIndex--;
	return stackArray[returnIndex];
}
template<class StackElementType>
StackElementType
MyStack<StackElementType>::top() {
	assert(topIndex >= 0);
	return stackArray[topIndex];
}

template<class StackElementType>
bool
MyStack<StackElementType>::isEmpty(){

	return topIndex == -1;
}

template<class StackElementType>
bool
MyStack<StackElementType>::isFull() {
	return topIndex == maxStackSize - 1;
}

int main() {

	char charArray[6] = { 'H', 'e', 'l', 'l', 'o', '!'};
	MyStack<char> s;
	for (int i = 0; i < 6; i++) {
		s.push(charArray[i]);
	}


	while (!s.isEmpty()) {
		cout << s.pop() << endl;
	}



	return 0;
}