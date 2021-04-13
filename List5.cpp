#include<assert.h>
#include "List5.h"
List5::List5() {
	head = 0;
	current = 0;
	
}
void List5::insert(const ListElementType& elem) {
	//head에 insert하는 경우 
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	if (head)
		head->previous = addedNode;

	addedNode->next = head;
	addedNode->previous = 0;
	head = addedNode;
}

bool List5::first(ListElementType& elem){
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;

		return true;
	}

}
bool List5::next(ListElementType& elem) {
	assert(current);
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}


}
bool List5::previous(ListElementType& elem) {

	assert(current);
	if (current->previous == 0)
		return false;
	else {
		current = current->previous;
		elem = current->elem;
		return true;
	}


}