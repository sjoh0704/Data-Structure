#include "List4.h"
#include<assert.h>
List4::List4() {
	head = new Node();
	assert(head);
	head->next = 0;
	current = 0;

}
void List4::insert(const ListElementType& elem) {
	Link addedNode = new Node();
	assert(addedNode);
	addedNode->elem = elem;
	Link pred = head;
	while (head->next != 0 && pred->next->elem <= addedNode->elem)
		pred = pred->next;

	addedNode->next = pred->next;
	pred->next = addedNode;


}
bool List4::first(ListElementType& elem) {
	assert(head);
	if (head->next == 0)
		return false;
	else {
		elem = head->next->elem;
		current = head->next;
		return true;
	}
}
bool List4::next(ListElementType& elem) {

	assert(current);
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}

}
bool List4::remove(ListElementType& elem) {
	return true;
}