#include<iostream>
#include<assert.h>
using namespace std;
const int maxQueue = 10;
int nextPos(int p);
template<class QueueElementType>
class queue {
public:
	queue();
	void enqueue(QueueElementType e);
	QueueElementType dequeue();
	QueueElementType front();
	bool isEmpty();

private:
	int f;
	int r;
	QueueElementType queueArray[maxQueue];
};

int nextPos(int p) {
	if (p == maxQueue - 1)
		return 0;
	else
		return p + 1;
}

template<class QueueElementType>
queue<QueueElementType>::queue() {
	f = 0;
	r = 0;
}

template<class QueueElementType>
void
queue<QueueElementType>::enqueue(QueueElementType e) {
	assert(nextPos(r) != f);
	r = nextPos(r);
	queueArray[r] = e;
}

template<class QueueElementType>
QueueElementType
queue<QueueElementType>::dequeue() {
	assert(f != r);
	f = nextPos(f);
	return queueArray[f];

}

template<class QueueElementType>
QueueElementType
queue<QueueElementType>::front() {
	assert(f != r);
	return queueArray[nextPos(f)];
}

template<class QueueElementType>
bool
queue<QueueElementType>::isEmpty(){
	return (f == r);
}


int main() {

	queue<char> q;

	char x;
	cin >> x;
	while (x != 'q') {
		q.enqueue(x);
		cin >> x;
	}

	while (!q.isEmpty()) {
		cout << q.dequeue()<< endl;
	}


	return 0;
}