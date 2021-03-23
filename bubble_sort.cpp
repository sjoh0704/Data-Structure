#include<iostream>
using namespace std;
void swapElement(int& a, int& b);
void bubbleSortPhase(int a[], int last);
void bubbleSort(int a[], int size);
int main() {

	int a[6] = { 1, 3, 2, 4, 7, 5 };
	bubbleSort(a, 6);

	for (int i = 0; i < 6; i++)
		cout << a[i] << " ";
	

	return 0;
}

void swapElement(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void bubbleSortPhase(int a[], int last) {
	for (int pos = 0; pos < last; pos++) 
		if (a[pos] < a[pos + 1])
			swapElement(a[pos], a[pos + 1]);
	
}

void bubbleSort(int a[], int size) {
	for (int i = size - 1; i > 0; i--)
		bubbleSortPhase(a, i);


}