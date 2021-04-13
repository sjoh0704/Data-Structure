//dynamic linear list

#include<iostream>
#include<assert.h>
using namespace std;
typedef int ListElementType;
class DynamicList {
public:
	DynamicList(int lSize) {
		assert(lSize>0);
		listSize = lSize;
		listArray = new ListElementType[listSize];
		assert(listArray);
		numberOfElements = 0;
		currentPosition = -1;
		
	}
	void insert(const ListElementType& elem) {
		assert(numberOfElements < listSize);
		listArray[numberOfElements] = elem;
		numberOfElements++;

	}
	bool first(ListElementType& elem) {
		if (numberOfElements == 0)
			return false;
		else {
			currentPosition = 0;
			elem = listArray[currentPosition];
			return true;
		}

	}
	bool next(ListElementType& elem) {
		assert(currentPosition >= 0);
		if (currentPosition >= numberOfElements -1)
			return false;
		else {
			currentPosition++;
			elem = listArray[currentPosition];
			return true;
		}
	}
	int getSize() {
		return listSize;
	}


private:

	int numberOfElements;
	int currentPosition;
	ListElementType* listArray;
	int listSize;




};

int main() {

	cout << "input the list size :" << endl;
	int size;
	cin >> size;
	DynamicList l1(size);
	ListElementType x;
	cin >> x;
	while (x) {
		l1.insert(x);
		cin >> x;
	}

	ListElementType tmp;
	bool notEmpty = l1.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l1.next(tmp);
	}



	return 0;
}
