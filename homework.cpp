#include<iostream>
#include<string>
#include"Pharmacy.h"
#include<cstdlib>
#include<ctime>
using namespace std;
int Pharmacy::count = 0;
void swapElement(Pharmacy[],int, int);
int maxSelect(Pharmacy p[], int n);
void selectionSort(Pharmacy[], int size);
int main() {
	srand((unsigned int)time(NULL));
	Pharmacy ph[10];

	cout << Pharmacy::count << endl;
	
	for (int i = 0; i < 10; i++) {
		
		ph[i].setName(rand() % 26 + 65);
		
	}
	for (int i = 0; i < 10; i++) {

	
		cout << ph[i].getName() << endl;
	}
	selectionSort(ph, 10);
	for (int i = 0; i < 10; i++) {

	
		cout << ph[i].getName() << endl;
	}


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
		if (int(p[maxPos].getName()) <= int(p[i].getName())) 
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

