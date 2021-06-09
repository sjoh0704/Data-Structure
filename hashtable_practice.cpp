#include<iostream>
#include<assert.h>
using namespace std;
const int MAX_TABLE = 11;
class HashTable {
public:
	HashTable();
	void insert(int key, int data);
	bool lookup(int key, int& data);
	void deleteKey(int key);

private:
	enum slotType{InUse, Deleted, Empty};
	struct slot {
		int data;
		int key;
		slotType slotStatus;
	};
	int entries;
	slot T[MAX_TABLE];
	bool search(int& pos, int target);
	int hash(int key);
	int probe(int pos);
};
HashTable::HashTable(){
	entries = 0;
	for (int i = 0; i < MAX_TABLE; i++)
		T[i].slotStatus = Empty;
}
void HashTable::insert(int key, int data) {
	assert(entries < MAX_TABLE - 1);
	int pos(hash(key));
	if (!search(pos, key)) {
		pos = hash(key);
		for (; T[pos].slotStatus == InUse; pos = probe(pos));
		T[pos].slotStatus = InUse;
		T[pos].key = key;
		T[pos].data = data;
		entries++;
	}
	else {
		T[pos].data = data;
	}
}
bool HashTable::lookup(int key, int& data) {
	assert(entries > 0);
	int pos(hash(key));
	if (search(pos, key)) {
		data = T[pos].data;
		return true;
	}
	return false;

}
void HashTable::deleteKey(int key) {
	assert(entries > 0);
	int pos(hash(key));
	if (search(pos, key)) {
		T[pos].slotStatus = Deleted;
		entries--;
	}
}
bool HashTable::search(int& pos, int target) {
	for (;T[pos].slotStatus != Empty; pos = probe(pos))
		if (T[pos].slotStatus == InUse)
			return true;

	return false;
}
int HashTable::hash(int key) {
	return key % MAX_TABLE;
}
int HashTable::probe(int pos) {
	if (pos < MAX_TABLE - 1)
		return pos + 1;
	return 0;
}

int main() {

	HashTable h;
	h.insert(1, 10);
	h.insert(2, 32);
	int data;

	if (h.lookup(2, data)){

		cout<<data<<endl;

	}
	else {
		cout<<"¾øÀ½"<<endl;
	}
	return 0;
}