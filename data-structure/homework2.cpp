// homework2
// 20160518 ©ю╫баж
#include<iostream>
#include"List2.h"
#include"Queue.h"
#include"StackArray.h"
using namespace std;
int main() {
	int a[7] = { 8, 2, 0, 0, 7, 1, 3 };
	//1. linked list
	cout << "Linked List" << endl;
	List2 list;
	for (int i = 0; i < 7; i++)
		list.insert(a[i]);
	int data;
	bool notEmpty = list.first(data);
	while (notEmpty) {
		cout << data<<'\t';
		notEmpty = list.next(data);
	}
	cout << endl;
	//2. stack class
	cout << "Stack" << endl;
	StackArray<int> stack;
	for (int i = 0; i < 7; i++)
		stack.push(a[i]);

	while (!stack.isEmpty())
		cout << stack.pop() <<'\t';
	cout << endl;
	//3. queue class
	cout << "Queue" << endl;
	Queue<int> queue;
	for (int i = 0; i < 7; i++)
		queue.enqueue(a[i]);

	while (!queue.isEmpty())
		cout << queue.dequeue() << '\t';
	cout << endl;
	return 0;
}