#include<iostream>
#include<assert.h>
using namespace std;
typedef char ListElementType;
class MyList {
public:
	MyList();
	void insert_to_head(const ListElementType& elem);
	void insert_to_tail(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
private:
	struct Node;
	typedef Node* Link;
	struct Node {
		ListElementType elem;
		Link next;
	};
	Link head;
	Link current;
	Link tail;
};

MyList::MyList() {
	head = 0;
	current = 0;
	tail = 0;
}

void MyList::insert_to_head(const ListElementType& elem) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0)
		tail = addedNode;
	addedNode->next = head;
	head = addedNode;
}

void MyList::insert_to_tail(const ListElementType& elem) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0)
		head = addedNode;
	else
		tail->next = addedNode;
	tail = addedNode;
	addedNode->next = 0;
}

bool MyList::first(ListElementType& elem) {
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
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


int main() {
	MyList l;
	char tmp;
	cin >> tmp;
	while (tmp != 'q') {
		l.insert_to_head(tmp);
		cin >> tmp;
	}
	bool notEmpty = l.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;;
		notEmpty = l.next(tmp);
	}
	MyList l2;

	cin >> tmp;
	while (tmp != 'q') {
		l2.insert_to_tail(tmp);
		cin >> tmp;
	}

	notEmpty = l2.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;;
		notEmpty = l2.next(tmp);
	}


	return 0;
}