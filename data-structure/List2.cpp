
#include "List2.h"
#include<assert.h>
List2::List2() {
	head = 0;
	tail = 0;
	current = 0;
}
List2::~List2() {
	while (head!= 0) {
		Link delNode = head;
		head = head->next;
		delete(delNode);
	}
}


//1. tail에 추가하는 insert
//
//void List2::insert(const ListElementType& elem) {
//	// tail로 insert하는 경우
//	Link addedNode = new Node();
//	assert(addedNode);
//	addedNode->elem = elem;
//	/*if (head == 0) {
//		head = addedNode;
//		tail = addedNode;
//		addedNode->next = 0;
//	}
//	else {
//		tail->next = addedNode;
//		tail = addedNode;
//		addedNode->next = 0;
//	}*/
//
//	if (head == 0) 
//		head = addedNode;
//
//	else 
//		tail->next = addedNode;
//	
//	tail = addedNode;
//	addedNode->next = 0;
//}

//2. head에 추가하는 insert


void List2::insert(const ListElementType& elem) {
	Link addedNode = new Node();
	assert(addedNode);
	addedNode->elem = elem;
	/*if (head == 0) {
		tail = addedNode;
		head = addedNode;
		addedNode->next = 0;
	}
	else {
		addedNode->next = head;
		head = addedNode;
	}*/
	if (head == 0)
		tail = addedNode;

	addedNode->next = head;
	head = addedNode;


}


bool List2::first(ListElementType& elem) {
	
	if (head == 0) {

		return false;
	}
	else {
		elem = head->elem;
		current = head;
		return true;
	}

}

bool List2::next(ListElementType& elem) {

	assert(current);
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}


}