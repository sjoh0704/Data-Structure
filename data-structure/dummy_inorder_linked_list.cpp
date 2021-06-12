//dummy inorder linked list
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
	void remove(const ListElementType& target);
private:
	struct Node;
	typedef Node* Link;
	struct Node {
		ListElementType elem;
		Link next;
	};
	Link head;
	Link current;
};

MyList::MyList(){
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->next = 0;
	head = addedNode;
	current = 0;
}
void MyList::insert(const ListElementType& elem) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	Link pred = head;
	while (pred->next != 0 && pred->next->elem <= addedNode->elem)
		pred = pred->next;
	addedNode->next = pred->next;
	pred->next = addedNode;
}

bool MyList::first(ListElementType& elem) {
	assert(head);
	if (head->next == 0)
		return false;
	else {
		current = head->next;
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

void MyList::remove(const ListElementType& target) {
	assert(head);
	Link pred = head;
	while (pred->next != 0 && pred->next->elem < target)
		pred = pred->next;

	if (pred && pred->next && pred->next->elem == target) {
		Link delNode = pred->next;
		pred->next = delNode->next;
		delete delNode;
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
	while(notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);
	}


	//remove  
	l.remove('d');

	notEmpty = l.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);
	}


	return 0;
}