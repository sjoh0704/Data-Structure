#pragma once
typedef int ListElementType;
class List2
{
public:
	List2();
	~List2();
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

