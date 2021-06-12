//inorder linked list
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
private:
	struct Node;
	typedef Node* Link;
	struct Node {
		Link next;
		ListElementType elem;
	};
	Link head;
	Link current;
	Link tail;
};
MyList::MyList() {
	head = 0;
	current = 0;

}
void MyList::insert(const ListElementType& elem) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0 || addedNode->elem <= head->elem) {
		addedNode->next = head;
		head = addedNode;
	}
	else {
		Link pred = head;
		while (pred->next != 0 && pred->next->elem <= addedNode->elem)
			pred = pred->next;
		addedNode->next = pred->next;
		pred->next = addedNode;
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
int main() {

	MyList l;
	char tmp;
	cin >> tmp;
	while (tmp != 'q') {
		l.insert(tmp);
		cin >> tmp;
	}
	bool notEmpty = l.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);
	}

	return 0;
}