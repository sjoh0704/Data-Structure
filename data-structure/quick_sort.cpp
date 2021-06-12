#include<iostream>
#include"Value.h"
using namespace std;
template <typename T>
void swapElement(T a[], int i, int j);
template <typename T>
int partition(T a[], int first, int last);
template <typename T>
void quickSort(T a[], int first, int last);
template <typename T>
void show_array(T a[], int size);

int main() {
	const int size = 10;


	//1. intÇü
	int a[size] = { 1, 5, 10, 6, 7, 8, 9, 2, 14, 12 };
	show_array(a, size);
	quickSort(a, 0, size - 1);
	show_array(a, size);

	//2. doubleÇü
	double b[size] = { 1.3, 2.5, 10.4, -7.2, 3.9, 1.1, 0.6, -3.2, -1, 10 };
	show_array(b, size);
	quickSort(b, 0, size - 1);
	show_array(b, size);

	//3.charÇü
	char c[size] = { 'a', 'f', 'g', 'k', 'x', 'd', 'b', 'e', 'f', 'h' };
	show_array(c, size);
	quickSort(c, 0, size - 1);
	show_array(c, size);



	return 0;
}
template <typename T>
void show_array(T a[], int size) {
	//precondition: a is an array sized size
	for (int i = 0; i < size; i++)
		cout << a[i] << endl;
	cout << endl;
	//postcondition: display value of a from index 0 to index size-1
}
template <typename T>
void swapElement(T a[], int i, int j) {
	//precondition: a is an array with index i and index j
	T tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
	//postcondition: a[i] and a[j] are swapped
}
template <typename T>
int partition(T a[], int first, int last) {

	//precondition: a is an array gets indexs from first to last at least

	int lastSmall(first);
	for (int i = first + 1; i <= last; i++)
		if (a[first] >= a[i]) {
			//loop invariant: a [first+1] ~ a[lastsmall] < a[first]
			//&& a[lastsmall+1] ~ a[i-1] > a[first] 
			lastSmall++;
			swapElement(a, lastSmall, i);
		}
	swapElement(a, lastSmall, first);

	//loop invariant: a [first] ~ a[lastsmall-1] < a[lastsmall]
	//&& a[lastsmall+1] ~ a[last] > a[lastsmall] 


	return lastSmall;
	//return: this is final position of pivot
}

template <typename T>
void quickSort(T a[], int first, int last) {
	//precondtition: a is an array
	//The portion to be sorted runs from index first to index last



	if (first >= last) //base case: nothing to sort, so just finish
		return;


	int split(partition(a, first, last));
	quickSort(a, first, split - 1);
	quickSort(a, split + 1, last);
	// postcondition: a is sorted in ascending order
	// between first and last inclusive



}