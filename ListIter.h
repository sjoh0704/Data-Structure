#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class ListElementType>
class ListIter;

template<class ListElementType>
class List
{
public:
	List() :head(0) {}
	virtual void insert(const ListElementType& elem);
	friend class ListIter<ListElementType>;

protected:
	struct Node;
	typedef Node* Link;
	struct Node {
		ListElementType elem;
		Link next;
	};
	Link head;
};
template < class ListElementType >
void
List<ListElementType> ::insert(const ListElementType& elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	addedNode->next = head;
	head = addedNode;
}



template<class ListElementType>
class ListIter
{
public:
	virtual ListElementType operator++();
	ListIter(const List<ListElementType>& l, ListElementType endFlag) :
		myList(l), myEndFlag(endFlag), iterPtr(0){}
private:
	const List<ListElementType> & myList;
	typename List<ListElementType>::Link iterPtr;
	ListElementType myEndFlag;
};


template<class ListElementType>
ListElementType
ListIter<ListElementType>::operator++(){
	if (iterPtr == 0)
		iterPtr = myList.head;
	else
		iterPtr = iterPtr->next;
	if (iterPtr)
		return iterPtr->elem;
	else
		return myEndFlag;
}
