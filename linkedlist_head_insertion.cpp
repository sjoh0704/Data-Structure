//head insertion
#include<iostream>
#include<assert.h>
using namespace std;
typedef int ListElementType;
class MyList {
public:
	MyList();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
	void remove(ListElementType elem);
	struct Node;
	typedef Node* Link;
	struct Node {
		Link next;
		ListElementType elem;
	};
	Link head;
	Link tail;
	Link current;
private:
	
};
MyList::MyList() {
	head = 0;
	tail = 0;
	current = 0;
}

void MyList::insert(const ListElementType& elem) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0) 
		tail = addedNode;

	addedNode->next = head;
	head = addedNode;
	
	
}
bool MyList::first(ListElementType& elem) {
	if (head == 0)
		return false;
	else {
		current = head;
		elem = current->elem;
		return true;
	}


}
bool MyList::next(ListElementType& elem) {
	assert(current);
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}

}
void MyList::remove(ListElementType target) {
	assert(head);
	Link pred, delNode;
	pred = head;
	if (target == pred->elem) {
		delNode = pred;
		if (pred->next) {
			head = pred->next;
		}
		else {
			head = 0;
			tail = 0;
		}
		delete delNode;
		return;

	}
	while (pred&&pred->next) {
		if (pred->next->elem == target) {
			delNode = pred->next;
			if (pred->next->next == 0) {
				tail = pred;
				pred->next = 0;
			}
			else {
				pred->next = delNode->next;
			}
			delete delNode;
			return;
		}
		else
			pred = pred->next;
	}



}
int main() {

	MyList l;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < 10; i++)
		l.insert(a[i]);
	for (int i = 2; i <= 10; i++)
		l.remove(i);
	int tmp;
	bool notEmpty = l.first(tmp);

	MyList l2;

	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);
	}
	return 0;
}