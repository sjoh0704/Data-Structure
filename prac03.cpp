//practice03 
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
	//precondition: two int type data a, b
	int tmp = a;
	a = b;
	b = tmp;
	//postcondition: a and b is swaped
	//return: nothing
}
int min_select(int a[], int n) {
	//precondition: a is an array with n size


	int minPos(0);
	int currentPos(1);

	while (currentPos < n) {
		if (a[currentPos] < a[minPos])
			//invariant: minPos is minimum value from a[0] to a[currentPos]
			minPos = currentPos;

		currentPos++;
	}
	//postcondition: minPos is the index that has minimum value from a[0] to a[n]

	return minPos;
	//return: return index which has minimum value
}
void selection_sort(int a[], int size) {
	//precondition: a is an array with indexed from 0 to size-1 

	int last(size - 1);
	int minPos;

	while (last > 0) {
		//invariant: a is sorted from a[last] to a[size-1] 
		minPos = min_select(a, last + 1);
		swapElement(a[minPos], a[last]);
		last--;
	}
	//postcondition: a is an sorted array
	//return: nothing

}