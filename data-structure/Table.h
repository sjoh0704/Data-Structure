// practice 15
//해쉬테이블
#include<assert.h>
using namespace std;
const int MAX_TABLE = 11;
template<class tableKeyType, class tableDataType>
class Table {
public:
	Table();
	void insert(const tableKeyType& key, const tableDataType& data);
	bool lookup(const tableKeyType& key, tableDataType& data);
	void deleteKey(const tableKeyType& key);
	void dump();
private:
	enum slotType {Empty, Deleted, InUse};
	struct slot {
		slotType slotStatus;
		tableKeyType key;
		tableDataType data;
	};

	slot T[MAX_TABLE];
	int numberOfEntries;
	int hash(const tableKeyType& key);
	int probe(const int pos);
	bool search(int& pos, const tableKeyType& target);

};
template<class tableKeyType, class tableDataType>
int
Table<tableKeyType, tableDataType>::hash(const tableKeyType& key) {
	return key % MAX_TABLE;
}
template<class tableKeyType, class tableDataType>
int
Table<tableKeyType, tableDataType>::probe(const int pos){
	if (pos < MAX_TABLE - 1)
		return pos + 1;
	else
		return 0;
}
template<class tableKeyType, class tableDataType>
bool
Table<tableKeyType, tableDataType>::search(int &pos, const tableKeyType& target) {
	for (;T[pos].slotStatus != Empty;pos = probe(pos))
		if (T[pos].slotStatus == InUse && T[pos].key == target)
			return true;
	return false;

}


template<class tableKeyType, class tableDataType>
Table<tableKeyType, tableDataType>::Table() {
	numberOfEntries = 0;
	for (int i = 0; i < MAX_TABLE; i++)
		T[i].slotStatus = Empty;
}


template<class tableKeyType, class tableDataType>
void
Table<tableKeyType, tableDataType>::insert(const tableKeyType& key, const tableDataType & data) {
	assert(numberOfEntries < MAX_TABLE - 1);
	int pos = hash(key);
	if (!search(pos, key)) {

		pos = hash(key);
		while (T[pos].slotStatus == InUse)
			pos = probe(pos);

		numberOfEntries++;
	

	}
	T[pos].slotStatus = InUse;
	T[pos].key = key;
	T[pos].data = data;
	
}
template<class tableKeyType, class tableDataType>
bool
Table<tableKeyType, tableDataType>::lookup(const tableKeyType& key, tableDataType &data){
	int pos = hash(key);
	if (search(pos, key)) {
		data = T[pos].data;
		return true;
	}
	else {
		return false;
	}
}
template<class tableKeyType, class tableDataType>
void
Table<tableKeyType, tableDataType>::deleteKey(const tableKeyType& key) {
	int pos = hash(key);
	if (search(pos, key)) {
		T[pos].slotStatus = Deleted;
		numberOfEntries --;
	}
}

template<class tableKeyType, class tableDataType>
void
Table<tableKeyType, tableDataType>::dump(){
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
			cout << "Empty\t" <<endl;
			break;
			
		default:
			break;
		}
	}
	cout << "Entries = " << numberOfEntries << endl;
	cout << endl;
}