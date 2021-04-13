//list made by array

#include<assert.h>
#include<iostream>
typedef int ListElementType;
const int maxListSize = 100;
class ListPrac01 {

public:
	ListPrac01() {
		numberOfElement = 0;
		currentPosition = -1;
	}
	void insert(const ListElementType& elem) {
		assert(numberOfElement<maxListSize);
		listArray[numberOfElement] = elem;
		numberOfElement++;
	}
	bool first(ListElementType& elem) {
		if (numberOfElement == 0)
			return false;
		else
		{
			currentPosition = 0;
			elem = listArray[currentPosition];
			return true;
		}
	}
	bool next(ListElementType& elem) {
		assert(currentPosition >= 0);
		if (currentPosition >= numberOfElement - 1)
			return false;
		else {
			currentPosition++;
			elem = listArray[currentPosition];
			return true;
		}

	}
private:
	ListElementType listArray[maxListSize];
	int numberOfElement;
	int currentPosition;
};

using namespace std;
int main() {

	ListPrac01 l = ListPrac01();
	ListElementType x;
	cin >> x;
	while (x) {
		l.insert(x);
		cin >> x;
	}

	ListElementType tmp;
	bool notEmpty = l.first(tmp);
	while (notEmpty) {
		cout << tmp << endl;
		notEmpty = l.next(tmp);
	}


	return 0;
}
