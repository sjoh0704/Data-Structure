//practice 14
// 20160518 ������
//linked list queue
#include <iostream>
#include "Queue2.h"
using namespace std;
int main() {
	Queue2<char> q;
	q.enqueue('a');
	q.enqueue('b');
	q.enqueue('c');
	q.enqueue('d');


	while (!q.isEmpty()) {
		cout << q.dequeue() << endl;
	}
	return 0;
}