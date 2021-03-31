#include<iostream>
#include<string>
#include"Pharmacy.h"
#include<cstdlib>
#include<ctime>
using namespace std;

void swapElement(Pharmacy[],int, int);
int maxSelect(Pharmacy p[], int n);
void selectionSort(Pharmacy[], int size);
int binary_search(Pharmacy[], int, string);
int partition1(Pharmacy[], int, int);
void quick_sort1(Pharmacy[], int, int);
int partition2(Pharmacy[], int, int);
void quick_sort2(Pharmacy[], int, int);
void show_array(Pharmacy[], int);
int cnt = 0;
int main() {
	const int size = 10;
	
	cout << "문제 2 ----------------------------------------------------------" << endl;

	Pharmacy ph[size];
	string name[size] = { "Bexar", "Austin", "Folsom", "Juno", 
		"Havana", "Icehouse", "Grizzly", "Essex", "Diablo","Cactus" };
	

	
	for (int i = 0; i < size; i++) {
		
		ph[i].setName(name[i]);
		
	}
	show_array(ph, size);
	

	selectionSort(ph, size);

	show_array(ph, size);
	cout << "문제 3 ----------------------------------------------------------" << endl;


	string target1 = "Juno";
	string target2 = "Nova";
	cout << binary_search(ph, size, target1) << endl;
	cout << binary_search(ph, size, target2) << endl;



	cout << "문제 4 ----------------------------------------------------------" << endl;

	//4 
	cnt = 0;
	int mask_stocks[size] = { 50, 100, 80, 90, 0, 30, 20, 60, 70, 10 };
	
	for (int i = 0; i < size; i++)
		ph[i].setMask(mask_stocks[i]);
	show_array(ph, size);

	

	quick_sort1(ph, 0, size - 1);

	show_array(ph, size);

	

	cout << "문제 5 ----------------------------------------------------------" << endl;

	//5 
	

	quick_sort2(ph, 0, size - 1);

	show_array(ph, size);

	cout << "연산횟수: " << cnt << endl;

	return 0;
}
void show_array(Pharmacy ph[], int size) {
	for (int i = 0; i < size; i++)
		cout << "약국 이름: " << ph[i].getName() <<", 마스크 재고: " << ph[i].getMask() << endl;
	cout << endl;
}

void swapElement(Pharmacy ph[], int a, int b) {
	Pharmacy tmp = ph[a];
	ph[a] = ph[b];
	ph[b] = tmp;

}

int maxSelect(Pharmacy p[], int n) {

	int maxPos = 0;
	for (int i = 1; i < n;i++) 
		if (p[maxPos].getName().compare(p[i].getName()) == -1)
			maxPos = i;

	return maxPos;
}
void selectionSort(Pharmacy p[], int size) {
	int last(size-1);
	int maxPos;

	while (last > 0) {
		maxPos = maxSelect(p, last+1);
		swapElement(p, maxPos, last);
		last--;
	}

}
int binary_search(Pharmacy p[], int size, string target_name) {
	int first = 0;
	int last = size-1;
	
	while (first <= last) {
		int mid = (first + last) / 2;
		if (p[mid].getName().compare(target_name) == 0) {
			return mid;
		}
		else if (p[mid].getName().compare(target_name) == 1)
			last = mid - 1;
		else
			first = mid + 1;
		
	}
	return -1;

}

int partition1(Pharmacy ph[], int first , int last) {
	int lastSmall(first);

	for (int i= first + 1; i <= last; i++) 
	{
		cnt++;
		if (ph[first].getMask() >= ph[i].getMask()) {

			lastSmall++;
			cnt++;
			swapElement(ph, lastSmall, i);
			cnt++;
		}
	}
	swapElement(ph, lastSmall, first);
	cnt++;
	return lastSmall;
}
void quick_sort1(Pharmacy ph[], int first, int last) {

	cnt++;
	if (first >= last)
		return;
	int pivot(partition1(ph, first, last));
	quick_sort1(ph, first, pivot - 1);
	quick_sort1(ph, pivot + 1, last);


}
int partition2(Pharmacy ph[], int first, int last) {
	int lastSmall(first);

	for (int i = first + 1; i <= last; i++)
		if (ph[first].getName().compare(ph[i].getName()) == 1) {
			lastSmall++;
			swapElement(ph, lastSmall, i);
		}
	swapElement(ph, lastSmall, first);

	return lastSmall;
}
void quick_sort2(Pharmacy ph[], int first, int last) {

	if (first >= last)
		return;
	int pivot(partition2(ph, first, last));
	quick_sort2(ph, first, pivot - 1);
	quick_sort2(ph, pivot + 1, last);


}
