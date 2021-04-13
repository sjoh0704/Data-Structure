#pragma once
//list array
//Characteristics:
//A List L stores items of some type, called 	ListElementType.

//Operations :
//
//	void L.insert(ListElementType elem)
//	Precondition : None.
//	Postcondition : Lpost = Lpre with an instance of elem 		added to Lpost.

//	bool L.first(ListElementType & elem)
//	Precondition : None
//	Postcondition : If the list is empty, none.Otherwise, the variable elem contains the first item in L; the ¡°next¡± 		item to be returned is the second in L.
//	Return:	true ifand only if there is at least one element 		in L.

//	bool L.next(ListElementType & elem)
//	Precondition : The ¡°first¡± operation has been called 		at least once.
//	Postcondition : Variable elem contains the next item 		in L, if there is one, and the next counter advances by 		one; if there is no next element, none.
//	Return:	true ifand only if there is a next item.

typedef int ListElementType;
const int maxListSize = 100;
class List
{
public:
	List();
	void insert(const ListElementType&);
	bool first(ListElementType&);
	bool next(ListElementType&);
private:
	ListElementType listArray[maxListSize];
	int numberOfElement;
	int currentPosition;

};

