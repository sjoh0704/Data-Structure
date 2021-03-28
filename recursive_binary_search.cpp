#include<iostream>
using namespace std;
int binary_search(int a[], int start, int last, int target);
int main() {

	int a[6] = { 1, 4, 6, 8, 10, 12 };

	int index = binary_search(a, 0, 5, 12);
	cout << index << endl;
	return 0;
}
int binary_search(int a[], int start, int last, int target) {
	

	if (start > last)
		return -1;


	int mid = (start + last) / 2;
	
	


	if (a[mid] == target) {
		return mid;
	}
	else if (a[mid] > target)
		return binary_search(a, start, mid - 1, target);
	else
		return binary_search(a, mid + 1, last, target);

}