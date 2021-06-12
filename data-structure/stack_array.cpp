//stack made by array

#include<iostream>
#include<assert.h>
using namespace std;
const int maxStackSize = 1000;

template <class StackElementType>
class Stack {
public:
	Stack();
	void push(StackElementType item);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();
private:
	StackElementType stackArray[maxStackSize];
	int topIndex;

};

template<class StackElementType>
Stack<StackElementType>::Stack() {
	topIndex = -1;
}

template<class StackElementType>
void Stack<StackElementType>::push(StackElementType item) {
	topIndex++;
	assert(topIndex < maxStackSize);
	stackArray[topIndex] = item;
}

template<class StackElementType>
StackElementType Stack<StackElementType>::pop() {

	assert(topIndex >= 0);
	int returnIndex = topIndex;
	topIndex--;
	return stackArray[returnIndex];
}

template<class StackElementType>
StackElementType Stack<StackElementType>::top() {
	assert(topIndex >= 0);
	return stackArray[topIndex];
}

template<class StackElementType>
bool Stack<StackElementType>::isEmpty() {
	return topIndex == -1;
}

int main() {

	Stack<int> stack;
	int s;
	cin >> s;
	while (s) {
		stack.push(s);
		cin >> s;
	}
	
	int tmp;
	
	while (!stack.isEmpty()) {
		tmp = stack.pop();
		cout << tmp << endl;
	}


	return 0;
}


