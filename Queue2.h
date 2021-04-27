//linked list queue
#pragma once
#include <assert.h>
template<class queueElementType>
class Queue2
{
public:
	Queue2();
	~Queue2();
	void enqueue(queueElementType elem);
	queueElementType dequeue();
	queueElementType front();
	bool isEmpty();


private:
	struct Node;
	typedef Node* nodePtr;
	struct Node {
		queueElementType data;
		nodePtr next;
	};
	nodePtr f;
	nodePtr r;
};

template<class queueElementType>
Queue2<queueElementType>::Queue2() {
	f = 0;
	r = 0;
}

template<class queueElementType>
Queue2<queueElementType>::~Queue2() {
	while (!isEmpty())
		dequeue();
}

template<class queueElementType>
void
Queue2<queueElementType>::enqueue(queueElementType elem) {
	nodePtr n = new Node;
	assert(n);
	n->data = elem;
	n->next = 0;
	if (f == 0) {
		f = n;
		r = n;
	}
	else {
		r->next = n;
		r = n;
	}
}

template<class queueElementType>
queueElementType
Queue2<queueElementType>::dequeue() {
	assert(f);
	nodePtr delNode = f;
	queueElementType returnValue = delNode->data;
	f = f->next;
	delete delNode;
	return returnValue;
}

template<class queueElementType>
queueElementType
Queue2<queueElementType>::front() {
	assert(f);
	return f->data;
}

template<class queueElementType>
bool
Queue2<queueElementType>::isEmpty() {
	return f == 0;
}
