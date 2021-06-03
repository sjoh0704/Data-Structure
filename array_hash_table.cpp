//array hash table
#include<iostream>
#include<assert.h>
using namespace std;
const int MAX_TABLE = 11;
template<class tableKeyType, class tableDataType>
class HashTable {
public:
	HashTable();
	void insert(const tableKeyType& key, const tableDataType& data);
	bool lookup(const tableKeyType& key, tableDataType& data);
	void deleteKey(const tableKeyType& key);
	void dump();
private:
	enum slotType{Empty, Deleted, InUse};
	struct slot {
		slotType slotStatus;
		tableKeyType key;
		tableDataType data;
	};
	int numberOfEntries;
	slot T[MAX_TABLE];
	
	int hash(const tableKeyType& key);
	int probe(const int pos);
	bool search(int& pos, const tableKeyType key);

};
template<class tableKeyType, class tableDataType>
HashTable<tableKeyType, tableDataType>::HashTable() {
	numberOfEntries = 0;
	for (int i = 0; i < MAX_TABLE; i++)
		T[i].slotStatus = Empty;
}
template<class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::insert(const tableKeyType& key, const tableDataType& data) {
	assert(numberOfEntries < MAX_TABLE - 1);
	int pos = hash(key);
	if (!search(pos, key)) {
		pos = hash(key);
		while (T[pos].slotStatus == InUse)
			pos = probe(pos);
		T[pos].key = key;
		T[pos].data = data;
		T[pos].slotStatus = InUse;
		numberOfEntries++;
	}

	T[pos].data = data;


}
template<class tableKeyType, class tableDataType>
bool
HashTable<tableKeyType, tableDataType>::lookup(const tableKeyType& key, tableDataType& data) {
	int pos = hash(key);
	if (search(pos, key)) {
		data = T[pos].data;
		return true;
	}
		
	return false;

}
template<class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::deleteKey(const tableKeyType& key) {
	int pos = hash(key);
	if (search(pos, key)) {
		T[pos].slotStatus = Deleted;
		numberOfEntries--;
	}


}
template<class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::dump() {
	for (int i = 0; i < MAX_TABLE; i++) {
		cout << i << '\t';
		switch (T[i].slotStatus)
		{
		case InUse:
			cout << "In Use\t" << T[i].key << endl;
			break;
		case Deleted:
			cout << "Deleted\t" << T[i].key << endl;
			break;
		case Empty:
			cout << "Empty\t" << endl;
			break;

		default:
			break;
		}
	}
	cout << "Entries = " << numberOfEntries << endl;
	cout << endl;
}
template<class tableKeyType, class tableDataType>
int
HashTable<tableKeyType, tableDataType>::hash(const tableKeyType& key) {
	return key % MAX_TABLE;
}
template<class tableKeyType, class tableDataType>
int
HashTable<tableKeyType, tableDataType>::probe(const int pos) {
	if (pos < MAX_TABLE - 1)
		return pos + 1;
	return 0;
}
template<class tableKeyType, class tableDataType>
bool 
HashTable<tableKeyType, tableDataType>::search(int& pos, const tableKeyType key) {
	
	for (; T[pos].slotStatus != Empty; pos = probe(pos))
		if (T[pos].slotStatus == InUse && T[pos].key == key) {
			return true;
		}
	return false;
}

int main() {


	HashTable<int, string> table;
	table.insert(19960101, "James");
	table.insert(19960102, "panda");
	table.insert(19960103, "Agile");
	table.insert(19960104, "Lick");
	table.insert(19960105, "Alice");
	table.insert(19960108, "Bob");
	table.insert(19960109, "Seung");
	table.dump();

	table.deleteKey(19960104);
	table.deleteKey(19960105);
	table.insert(19960115, "Ace");
	table.dump();


	string data;
	if (table.lookup(19960115, data))
		cout << data << endl;
	else
		cout << "not exist" << endl;


	return 0;
}