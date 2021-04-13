#pragma once
// doubly linked list
typedef int ListElementType;
class List5
{
public:
	List5();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
	bool previous(ListElementType& elem);
private:
	struct Node;
	typedef Node* Link;
	struct Node
	{
		ListElementType elem;
		Link next;
		Link previous;
	};

	Link head;
	Link current;
	Link tail;
};

