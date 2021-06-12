#include<assert.h>
#include<iostream>
typedef int ListElementType;
class LinkedList {
public:
	LinkedList() {
		head = 0;
		current = 0;
		tail = 0;
	}
	void insert_to_tail(const ListElementType& elem) {
		Link addedNode = new Node();
		assert(addedNode);
		addedNode->elem = elem;
		if (head == 0) 
			head = addedNode;
			
		else 
			tail->next = addedNode;
		tail = addedNode;
		addedNode->next = 0;

	}

	void insert_to_head(const ListElementType& elem) {
		Link addedNode = new Node();
		assert(addedNode);
		addedNode->elem = elem;
		if (head == 0)
			tail = addedNode;
			
		addedNode->next = head;
		head = addedNode;
		


	}
	bool first(ListElementType& elem) {
		if (head == 0)
			return false;
		else {
			elem = head->elem;
			current = head;
			return true;
		}


	}
	bool next(ListElementType& elem) {
		assert(current);
		if (current->next == 0)
			return false;
		else {
			current = current->next;
			elem = current->elem;
			return true;
		}

	}
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
using namespace std;
int main() {

	LinkedList l = LinkedList();
	ListElementType x;
	cin >> x;
	while (x) {
		l.insert_to_head(x);
		cin >> x;
	}
	ListElementType tmp;
	bool notEmpty = l.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);
	}



	return 0;
}