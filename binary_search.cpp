#include<iostream>
using namespace std;
int binary_search(int a[], int size, int target);
int main() {


	int target;
	cin >> target;
	int a[5] = { 1, 3, 5, 7, 9};
	int index = binary_search(a, 5, target);

	if (index == -1)
		cout << "���� �������� ����" << endl;
	else
		cout << index << "��° �ε���" << endl;

	return 0;
}

int binary_search(int a[], int size, int target) {

	int first(0);
	int last(size - 1);

	while (first <= last) {
		int mid = (first + last) / 2;

		if (target == a[mid])
			return mid;
		else if (target < a[mid])
			last = mid - 1;
		else
			first = mid + 1;


	}

	return -1;

}