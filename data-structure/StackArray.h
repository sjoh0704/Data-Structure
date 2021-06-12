#pragma once
#include<assert.h>
const int maxStackSize = 1000;
template<class StackElementType>
class StackArray
{
public:
	StackArray();
	void push(StackElementType item);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();
private:
	StackElementType stackArray[maxStackSize];
	int topIndex;
};


template<class StackElementType>
StackArray<StackElementType>:: StackArray() {
	topIndex = -1;
}

template<class StackElementType>
void StackArray<StackElementType>::push(StackElementType item) {
	topIndex++;
	assert(topIndex < maxStackSize);
	stackArray[topIndex] = item;

}

template<class StackElementType>
StackElementType
StackArray<StackElementType>::pop() {
	assert(topIndex >= 0);
	StackElementType returnItem = stackArray[topIndex];
	topIndex--;
	return returnItem;
}

template<class StackElementType>
StackElementType
StackArray<StackElementType>::top() {
	assert(topIndex >= 0);
	return stackArray[topIndex];
}

template<class StackElementType>
bool
StackArray<StackElementType>::isEmpty() {
	return topIndex == -1;
}

