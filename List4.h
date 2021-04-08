#pragma once
typedef int ListElementType;
class List4
{

public:
	List4();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
	void remove(ListElementType& target);
private:
	struct Node;
	typedef Node* Link;
	struct Node {
		ListElementType elem;
		Link next;
	};
	Link head;
	//Link tail;
	Link current;

};

