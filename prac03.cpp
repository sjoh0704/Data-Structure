#include<iostream>
using namespace std;
void swapElement(int& a, int& b);
void selection_sort(int a[], int size);
int min_select(int a[], int n);
int main() {

	cout << "배열의 크기 입력: ";
	int size;
	cin >> size;
	int* a = new int[size];
	for (int i = 0; i < size; i++) {
		
		cout << "값 입력: ";
		cin >> a[i];
		
	}

	
	selection_sort(a, size);

	cout << "--------------결과--------------" << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << endl;

	return 0;
}
void swapElement(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int min_select(int a[], int n) {
	int minPos(0);
	int currentPos(1);

	while (currentPos < n) {
		if (a[currentPos] < a[minPos])
			minPos = currentPos;

		currentPos++;
	}

	return minPos;
}
void selection_sort(int a[], int size) {

	int last(size - 1);
	int minPos;

	while (last > 0) {
		minPos = min_select(a, last + 1);
		swapElement(a[minPos], a[last]);
		last--;
	}


}