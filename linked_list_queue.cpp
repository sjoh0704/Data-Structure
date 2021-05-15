#include<iostream>
#include<assert.h>
using namespace std;
template<class queueElementType>
class MyQueue {
public:
	MyQueue();
	void enqueue(queueElementType elem);
	queueElementType dequeue();
	bool isEmpty();
	
private:
	struct Node;
	typedef Node* nodePtr;
	struct Node {
		queueElementType elem;
		nodePtr next;
	};
	nodePtr f;
	nodePtr r;
};
template<class queueElementType>
MyQueue<queueElementType>::MyQueue() {
	f = 0;
	r = 0;
}

template<class queueElementType>
void
MyQueue<queueElementType>::enqueue(queueElementType elem) {
	nodePtr addedNode = new Node;
	addedNode->elem = elem;
	addedNode->next = 0;
	if (f == 0) {
		f = addedNode;
		r = addedNode;
	}
	else {
		r->next = addedNode;
		r = addedNode;
	}

}

template<class queueElementType>
queueElementType
MyQueue<queueElementType>::dequeue() {
	assert(f);
	nodePtr deleteNode = f;
	queueElementType elem = f->elem;
	f = f->next;
	delete deleteNode;
	if (f == 0)
		r = 0;
	return elem;
}

template<class queueElementType>
bool
MyQueue<queueElementType>::isEmpty() {
	return bool(f == 0);
}
int main() {
	MyQueue<int> queue;
	queue.enqueue(10);
	queue.enqueue(5);
	queue.enqueue(4);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(1);

	while (!queue.isEmpty()) {
		cout << queue.dequeue() << endl;
	}


	return 0;
}