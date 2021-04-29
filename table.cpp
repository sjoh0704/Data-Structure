//table 
#include<iostream>
#include<assert.h>
using namespace std;
const int MAX_TABLE = 100;
template<class tableKeyType, class tableElementType>
class Table {
public:
	Table();
	bool lookup(tableKeyType lookupKey, tableElementType& data);
	void insert(tableKeyType insertKey, tableElementType insertData);
	void deleteKey(tableKeyType deleteKey);
	

private:
	struct item {
		tableKeyType key;
		tableElementType data;
	};
	item T[MAX_TABLE];
	int numberOfEntries;
	int search(tableKeyType key);

};

template<class tableKeyType, class tableElementType>
int
Table<tableKeyType, tableElementType>::search(tableKeyType key) {
	int pos;
	for (pos = 0; pos < numberOfEntries && T[pos].key != key; pos++);

	return pos;
}

template<class tableKeyType, class tableElementType>
Table<tableKeyType, tableElementType>::Table() {
	numberOfEntries = 0;
}

template<class tableKeyType, class tableElementType>
bool
Table<tableKeyType, tableElementType>::lookup(tableKeyType lookupKey, tableElementType& data) {
	int pos = search(lookupKey);
	if (pos == numberOfEntries)
		return false;
	else {

		data = T[pos].data;
		return true;
	}

}
template<class tableKeyType, class tableElementType>
void
Table<tableKeyType, tableElementType>::insert(tableKeyType insertKey, tableElementType insertData) {
	assert(numberOfEntries < MAX_TABLE);
	int pos = search(insertKey);
	if (pos == numberOfEntries) {
		T[numberOfEntries].key = insertKey;
		T[numberOfEntries].data = insertData;
		numberOfEntries++;
	}
	else {
		T[pos].data = insertData;
	}


}
template<class tableKeyType, class tableElementType>
void
Table<tableKeyType, tableElementType>::deleteKey(tableKeyType deleteKey) {
	int pos = search(deleteKey);
	if (pos < numberOfEntries) {
		
		numberOfEntries--;
		T[pos] = T[numberOfEntries];

	}


}
int main() {
	Table<int, char> t;

	t.insert(1, 'a');
	t.insert(2, 'b');
	t.insert(3, 'c');
	t.insert(4, 'd');
	t.insert(5, 'e');
	t.insert(6, 'f');
	t.insert(7, 'g');
	t.deleteKey(3);
	t.deleteKey(5);
	t.deleteKey(10);




	for (int i = 0; i < MAX_TABLE; i++) {
		char data;
		if (t.lookup(i, data)) {
			cout << i<<": "<<data << endl;;
		}
	}


	return 0;
}