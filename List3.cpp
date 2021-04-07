#include "List3.h"
#include<assert.h>
List3::List3() {
	head = 0;
	current = 0;
	tail = 0;
}
void List3::insert(const ListElementType& elem) {
	Link addedNode = new Node();
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0 || addedNode->elem < head->elem) {
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

bool List3::first(ListElementType& elem) {
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}


}
bool List3::next(ListElementType& elem) {
	
	assert(current);
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;

	}

}