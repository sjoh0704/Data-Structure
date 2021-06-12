//practice 16
// chained hash table
#pragma once
using namespace std;
const int MAX_TABLE = 11;
template<class tableKeyType, class tableDataType>
class Table2
{

public:
	Table2();
	void insert(const tableKeyType& key, const tableDataType& data);
	bool lookup(const tableKeyType& key, tableDataType& data);
	void deleteKey(const tableKeyType& key);
	void dump();
private:
	struct slot;
	typedef slot* Link;
	struct slot
	{
		tableKeyType key;
		tableDataType data;
		Link next;
	};

	Link T[MAX_TABLE];
	int hash(const tableKeyType& key);
	bool search(Link & slotPointer, const tableKeyType& key);
};

template<class tableKeyType, class tableDataType>
Table2<tableKeyType, tableDataType>::Table2() {
	for (int i = 0; i < MAX_TABLE; i++)
		T[i] = 0;
}

template<class tableKeyType, class tableDataType>
int
Table2<tableKeyType, tableDataType>::hash(const tableKeyType& key) {
	return key % MAX_TABLE;
}

template<class tableKeyType, class tableDataType>
bool
Table2<tableKeyType, tableDataType>::search(Link& slotPointer, const tableKeyType& key) {
	for (; slotPointer; slotPointer = slotPointer->next)
		if (slotPointer->key == key)
			return true;
	return false;
}

template<class tableKeyType, class tableDataType>
void
Table2<tableKeyType, tableDataType>::insert(const tableKeyType& key, const tableDataType& data) {
	int pos = hash(key);
	Link sp = T[pos];
	if (!search(sp, key)) {
		Link insertSlot = new slot;
		insertSlot->data = data;
		insertSlot->key = key;
		insertSlot->next = T[pos];
		T[pos] = insertSlot;
	}
	else {
		sp->data = data;
	}

}

template<class tableKeyType, class tableDataType>
bool
Table2<tableKeyType, tableDataType>::lookup(const tableKeyType& key, tableDataType& data) {
	int pos = hash(key);
	Link sp = T[pos];
	if (!search(sp, key))
		return false;
	else {
		data = sp->data;
		return true;
	}

}

template<class tableKeyType, class tableDataType>
void
Table2<tableKeyType, tableDataType>::deleteKey(const tableKeyType& key) {
	int pos = hash(key);
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
				Link deleteSlot = p->next;
				p->next = deleteSlot->next;
				delete deleteSlot;
				return;
			}


	}
}


template<class tableKeyType, class tableDataType>
void
Table2<tableKeyType, tableDataType>::dump() {
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