#pragma once
#include<assert.h>
const int maxQueue = 3;
template<class queueElementType>
class Queue
{
public:
	Queue();
	~Queue();
	void enqueue(queueElementType elem);
	queueElementType dequeue();
	queueElementType front();
	bool isEmpty();
	bool isFull();
private:
	int f;
	int r;
	queueElementType elements[maxQueue];
	int numberOfElements;
};

int nextPos(int x) {
	if (x == maxQueue - 1)
		return 0;
	else
		return x + 1;
}

template<class queueElementType>
Queue<queueElementType>::Queue() {
	f = 0;
	r = 0;
	numberOfElements = 0;
}

template<class queueElementType>
Queue<queueElementType>::~Queue() {
	//공간이 할당되어 있지 않음
}

template<class queueElementType>
void
Queue<queueElementType>::enqueue(queueElementType elem) {
	//assert(nextPos(r) != f);
	assert(!isFull());
	r = nextPos(r);
	elements[r] = elem;
	numberOfElements++;
}

template<class queueElementType>
queueElementType
Queue<queueElementType>::dequeue() {
	//assert(f != r);
	assert(!isEmpty());
	f = nextPos(f);
	numberOfElements--;
	return elements[f];
}

template<class queueElementType>
queueElementType
Queue<queueElementType>::front() {
	assert(!isEmpty());
	return elements[nextPos[f]];
}

template<class queueElementType>
bool
Queue<queueElementType>::isEmpty() {
	
	//return r == f;
	return numberOfElements == 0;

}

template<class queueElementType>
bool
Queue<queueElementType>::isFull() {
	//return nextPos(r) == f;
	return numberOfElements == maxQueue;
}

