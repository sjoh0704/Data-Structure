#include<iostream>
using namespace std;
void insertionSort(int a[], int size);
void insertNextItem(int a[], int i);
int main() {

	int a[10] = { 3, 2, 1, 4, 5, 8, 9, 7, 6, 10 };
	insertionSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << '\t';
	return 0;
}

void insertionSort(int a[], int size) {
	for (int i = 1; i < size; i++)
		insertNextItem(a, i);
}
void insertNextItem(int a[], int i) {
	int newItem(a[i]);
	int insertPos(i);
	for (; insertPos && newItem < a[insertPos - 1];insertPos--)
		a[insertPos] = a[insertPos - 1];
	a[insertPos] = newItem;

}