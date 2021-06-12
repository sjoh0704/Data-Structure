// 다이나믹 리니어 리스트
#include<iostream>
#include<assert.h>
using namespace std;
typedef char ListElementType;
class MyList {
public:
	MyList(int lSize);
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
	int getSize();

private:
	int listSize;
	ListElementType* listArray;
	int numberOfElements;
	int currentPosition;

};

MyList::MyList(int lSize) {
	assert(lSize >= 0);
	listSize = lSize;
	listArray = new ListElementType[listSize];
	assert(listArray);
	numberOfElements = 0;
	currentPosition = -1;

}
void MyList::insert(const ListElementType& elem) {
	assert(numberOfElements < listSize);
	listArray[numberOfElements] = elem;
	numberOfElements++;
}

bool MyList::first(ListElementType& elem) {
	if (numberOfElements == 0)
		return false;
	else {
		currentPosition = 0;
		elem = listArray[currentPosition];
		return true;
	}
}

bool MyList::next(ListElementType& elem) {
	assert(currentPosition>=0);
	if (currentPosition >= numberOfElements-1)
		return false;
	else {
		currentPosition++;
		elem = listArray[currentPosition];
		return true;
	}
}
int MyList::getSize() {
	return listSize;
}

int main() {
	MyList l(100);
	char tmp;
	cin >> tmp;
	while (tmp != 'q') {
		l.insert(tmp);
		cin >> tmp;
	}

	bool notEmpty = l.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);

	}


	

	return 0;
}