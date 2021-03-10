#include<iostream>
using namespace std;
void insertNextItem(int a[], int i);
void insertionSort(int a[], int n);

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
void insertNextItem(int a[], int i) {


	int newItem(a[i]), insertPos(i);

	for (; insertPos && newItem < a[insertPos-1]; insertPos--) {
		
		a[insertPos] = a[insertPos-1];
		a[insertPos-1] = newItem;
	}


	/*for (int j = i - 1; j >= 0; j--) {
		if (a[j] > a[i]) {
			cout << a[j] << ", " << a[i] << endl;
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			i--;
		}
		else {
			
			break;
		}
			
	}*/


}
void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		insertNextItem(a, i);

	}
}