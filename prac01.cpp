#include<iostream>
using namespace std;

//practice example insertion sort
void insertionSort(int a[], int n);
void insertNextItem(int a[], int i);

int main() {
	int array_num;
	cin >> array_num;
	int* a = new int[array_num];
	for (int i = 0; i < array_num; i++)
		cin >> a[i];

	insertionSort(a, array_num);

	for (int i = 0; i < array_num; i++) {
		cout << a[i] << endl;
	}

}

void insertionSort(int a[], int n) {
	//precondition: a is array that has index raning from 0 to n-1

	for (int i = 1; i < n; i++) {
		//loopinvariant: value of array ranging from 0 to i-1 is sorted 
		insertNextItem(a, i);

	}
	//postcondition: all values of array are sorted
}
void insertNextItem(int a[], int i) {
	//precondition: a is array that has index ranging from 0 to i-1

	int newItem(a[i]), insertPos(i);

	for (; insertPos && newItem < a[insertPos-1]; insertPos--) {
		//loopinvariant: value of array raning from a[insertPos+1] to a[i] is sorted
		a[insertPos] = a[insertPos-1];
		a[insertPos-1] = newItem;
	}
	//postcondition: from index 0 to index i, values is sorted 

}
