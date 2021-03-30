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

	cout << "1. int형을 이용한 quick sort-----------------------------------------------------------------------------------------" << endl;
	int a[size] = { 1, 5, 10, 6, 7, 8, 9, 2, 14, 12 };
	show_array(a, size);
	quickSort(a, 0, size - 1);
	show_array(a, size);
	
	cout << "\n2. double형을 이용한 quick sort-----------------------------------------------------------------------------------------" << endl;
	double b[size] = { 1.3, 2.5, 10.4, -7.2, 3.9, 1.1, 0.6, -3.2, -1, 10 };
	show_array(b, size);
	quickSort(b, 0, size - 1);
	show_array(b, size);
	
	cout << "\n3. char형을 이용한 quick sort-----------------------------------------------------------------------------------------" << endl;
	char c[size] = { 'a', 'f', 'g', 'k', 'x', 'd', 'b', 'e', 'f', 'h' };
	show_array(c, size);
	quickSort(c, 0, size - 1);
	show_array(c, size);
	

	cout << "\n4. class를 이용한 quick sort-----------------------------------------------------------------------------------------" << endl;
	Value d[size] = { 1, 5, 10, 6, 7, 8, 9, 2, 14, 12 };
	for (int i = 0; i < size; i++)
		cout << d[i].getValue() << endl;
	cout << endl;
	quickSort(d, 0, size - 1);
	for (int i = 0; i < size; i++)
		cout << d[i].getValue() << endl;



	


	return 0;
}
template <typename T>
void show_array(T a[], int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << endl;
	cout << endl;
}
template <typename T>
void swapElement(T a[], int i, int j) {
	T tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
template <typename T>
int partition(T a[], int first, int last) {

	int lastSmall(first);
	for (int i = first + 1; i <= last; i++)
		if (a[first] >= a[i]) {
			lastSmall++;
			swapElement(a, lastSmall, i);
		}
	swapElement(a, lastSmall, first);
	


	return lastSmall;
}
template <typename T>
void quickSort(T a[], int first, int last) {

	if (first >= last)
		return;

	int split(partition(a, first, last));
	quickSort(a, first, split - 1);
	quickSort(a, split + 1, last);


}