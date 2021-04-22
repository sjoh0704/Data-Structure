#include<iostream>
#include<assert.h>
using namespace std;
typedef char ListElementType;
class MyList {
public:
	MyList();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
	void remove(ListElementType& elem);

private:
	struct Node;
	typedef Node* Link;
	struct Node {
		ListElementType elem;
		Link next;
	};
	Link head;
	Link tail;
	Link current;
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
	if (head == 0) {
		head = addedNode;
		tail = addedNode;
		addedNode->next = 0;
	}
	else {
		tail->next = addedNode;
		tail = addedNode;
		addedNode->next = 0;
	}
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
void MyList::remove(ListElementType& elem) {
	assert(head);
	Link pred, delNode;
	pred = head;
	if (pred->elem == elem) {
		delNode = pred;
		if (pred->next == 0) {
			head = 0;
			tail = 0;
		}
		else {
			head = pred->next;
		}
		delete delNode;
		return;
	}

	while (pred&&pred->next) {
		if (pred->next->elem == elem) {
			delNode = pred->next;
			if (pred->next->next == 0)
				tail = pred;
			
			pred->next = delNode->next;
			delete delNode;
		}
		pred = pred->next;
	}

}


int main() {
	MyList l;
	char charArray[1] = { 'c'};
	for (int i = 0; i < 1; i++)
		l.insert(charArray[i]);
	char tmp;
	char rmItem = 'c';
	l.remove(rmItem);
	bool notEmpty = l.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);
	}

	return 0;
}