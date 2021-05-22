//실습 13
// 20160518 오승주
//circular queue구현하기 
#include<iostream>
#include"Queue.h"
using namespace std;
int main() {

	Queue<char> q;
	q.enqueue('a');
	q.enqueue('b');
	q.enqueue('c');

	while (!q.isEmpty()) {
		cout << q.dequeue() << endl;
	}

	return 0;
}