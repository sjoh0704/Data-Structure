#include<iostream>
using namespace std;
const int MAX_TABLE = 11;
template<class tableKeyType, class tableDataType>
class MyTable {
public:
	MyTable();
	void insert(const tableKeyType& key, const tableDataType& data);
	bool lookup(const tableKeyType & key, tableDataType& data);
	void deleteKey(const tableKeyType& key);
	void dump();
private:
	struct Slot;
	typedef Slot* Link;
	struct Slot {
		tableKeyType key;
		tableDataType data;
		Link next;
	};
	Link T[MAX_TABLE];
	int hash(const tableKeyType& key);
	bool search(Link& slotPointer, const tableKeyType& target);
};
template<class tableKeyType, class tableDataType>
int
MyTable<tableKeyType, tableDataType>::hash(const tableKeyType& key) {
	return key % MAX_TABLE;
}
template<class tableKeyType, class tableDataType>
bool
MyTable<tableKeyType, tableDataType>::search(Link& slotPointer, const tableKeyType& target) {
	for (;slotPointer; slotPointer = slotPointer->next)
		if (slotPointer->key == target)
			return true;
	return false;
}
template<class tableKeyType, class tableDataType>
MyTable<tableKeyType, tableDataType>::MyTable() {
	for (int i = 0; i < MAX_TABLE; i++) {
		T[i] = 0;
	}
}
template<class tableKeyType, class tableDataType>
void 
MyTable<tableKeyType, tableDataType>::insert(const tableKeyType& key, const tableDataType& data) {
	int pos(hash(key));
	Link np = T[pos];

	if (!search(np, key)) {
		Link inserted = new Slot;
		inserted->data = data;
		inserted->key = key;
		inserted->next = T[pos];
		T[pos] = inserted;
	}
	else {
		np->data = data;

	}

}

template<class tableKeyType, class tableDataType>
bool
MyTable<tableKeyType, tableDataType>::lookup(const tableKeyType& key, tableDataType& data) {
	int pos(hash(key));
	Link np(T[pos]);
	if (search(np, key)) {
		data = np->data;
		return true;
	}
	return false;
}


template<class tableKeyType, class tableDataType>
void
MyTable<tableKeyType, tableDataType>::deleteKey(const tableKeyType& key) {
	int pos(hash(key));
	if (T[pos] == 0)
		return;
	if (T[pos]->key == key) {
		Link deleteSlot = T[pos];
		T[pos] = T[pos]->next;
		delete deleteSlot;
	}
	else {
		for (Link p = T[pos]; p->next; p = p->next) 
			if (p->next->key == key) {
				Link deletSlot = p->next;
				p->next = p->next->next;
				delete deletSlot;
				break;
			}
	}
}

template<class tableKeyType, class tableDataType>
void
MyTable< tableKeyType, tableDataType >::dump()
{
	int i;
	for (i = 0; i < MAX_TABLE; i++) {
		cout << i << '\t';
		Link p;
		for (p = T[i]; p; p = p->next)
			cout << p->key << '\t';
		cout << '\n';
	}
	cout << '\n';
}

int main() {

	MyTable<int, int> table;
	table.insert(19960704, 19960704);
	table.insert(19960705, 19960705);
	table.insert(19960706, 19960706);
	table.insert(19960707, 19960707);
	table.insert(19960708, 19960708);
	table.insert(19960709, 19960709);
	table.insert(19960710, 19960710);
	table.insert(19960715, 19960715);
	table.insert(19960716, 19960716);
	table.insert(19960717, 19960717);
	table.insert(19960718, 19960718);

	table.deleteKey(19960704);

	table.dump();
	int target;
	
	if (table.lookup(19960708, target))
		cout << target << endl;
	else
		cout << "값이 존재하지 않음" << endl;


	return 0;
}