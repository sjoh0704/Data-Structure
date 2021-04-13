#pragma once
// in order linked list 
typedef int ListElementType;
class List3
{

public:
	List3();
	void insert(const ListElementType& elem);
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
	Link tail;
	Link current;

};

