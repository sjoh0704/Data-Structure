#include<iostream>
#include<assert.h>
using namespace std;
const int maxStackSize = 1000;
typedef int StackElementType;
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

Stack::Stack() {
	topIndex = -1;
}
void Stack::push(StackElementType item) {
	topIndex++;
	assert(topIndex < maxStackSize);
	stackArray[topIndex] = item;
}
StackElementType Stack::pop() {

	assert(topIndex >= 0);
	int returnIndex = topIndex;
	topIndex--;
	return stackArray[returnIndex];
}
StackElementType Stack::top() {
	assert(topIndex >= 0);
	return stackArray[topIndex];
}
bool Stack::isEmpty() {
	return topIndex == -1;
}

int main() {

	Stack stack;
	StackElementType s;
	cin >> s;
	while (s) {
		stack.push(s);
		cin >> s;
	}

	StackElementType tmp;
	
	while (!stack.isEmpty()) {
		tmp = stack.pop();
		cout << tmp << endl;
	}




	return 0;
}


