#include<iostream>
using namespace std;
void swapElement(int& a, int& b);
void selection_sort(int a[], int size);
void selection_sort2(int a[], int size);
int min_select(int a[], int n);
int main() {


	int a[5] = { 1, 5, 2, 3, 4 };

	selection_sort2(a, 5);

	for (int i = 0; i < 5; i++)
		cout << a[i] << endl;

	return 0;
}
void swapElement(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void selection_sort(int a[], int size) {

	
	for (int i = 0; i < size - 1; i++) {
		int max = a[i];
		for (int j = i + 1; j < size; j++)
			if (max < a[j]) {
				max = a[j];
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;

			}
	}
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
void selection_sort2(int a[], int size) {

	int last(size - 1);
	int minPos;

	while (last > 0) {
		minPos = min_select(a, last + 1);
		swapElement(a[minPos], a[last]);
		last--;
	}


}