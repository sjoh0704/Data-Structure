#include "List.h"
#include<assert.h>

List::List() {

	numberOfElement = 0;
	currentPosition = -1;
}

void List::insert(const ListElementType& elem) {
	assert(numberOfElement < maxListSize);
	listArray[numberOfElement] = elem;
	numberOfElement++;
}
bool List::first(ListElementType& elem) {
	if (numberOfElement == 0)
		return false;
	else {
		currentPosition = 0;
		elem = listArray[currentPosition];
		return true;
	}

}
bool List::next(ListElementType& elem) {
	assert(currentPosition >= 0);
	if (currentPosition >= numberOfElement - 1)
		return false;
	else {
		currentPosition++;
		elem = listArray[currentPosition];
		return true;
	}


}