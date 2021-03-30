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
int main() {
	
	Pharmacy ph[10];
	string name[10] = { "Bexar", "Austin", "Folsom", "Juno", 
		"Havana", "Icehouse", "Grizzly", "Essex", "Diablo","Cactus" };
	
	for (int i = 0; i < 10; i++) {
		
		ph[i].setName(name[i]);
		
	}
	for (int i = 0; i < 10; i++) {

	
		cout << ph[i].getName() << endl;
	}
	selectionSort(ph, 10);
	for (int i = 0; i < 10; i++) {

	
		cout << ph[i].getName() << endl;
	}
	string target1 = "Juno";
	string target2 = "Nova";
	cout << binary_search(ph, 10, target1) << endl;
	cout << binary_search(ph, 10, target2) << endl;


	return 0;
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
		cout << maxPos << "," << last << endl;
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

