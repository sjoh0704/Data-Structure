//20160518 ������
//����ũ ���� ���α׷� �����
#include<iostream>
#include<string>
#include"Pharmacy.h"
#include<cstdlib>
#include<ctime>

using namespace std;
void swapElement(Pharmacy[], int, int);
int maxSelect(Pharmacy p[], int n);
void selectionSort(Pharmacy[], int size);
int binary_search(Pharmacy[], int, string);
int partition_descending(Pharmacy[], int, int);
void quick_sort_descending(Pharmacy[], int, int);
int partition_ascending(Pharmacy[], int, int);
void quick_sort_ascending(Pharmacy[], int, int);
void show_array(Pharmacy[], int);
int cnt = 0;

int main() {
	const int size = 10;

	cout << "\n����ũ ���� ���α׷� �����\n \
                                            20160518 ������\n" << endl;

	// ���� 2��
	cout << "\n���� 2 ----------------------------------------------------------\n" << endl;

	Pharmacy ph[size];
	string name[size] = { "Bexar", "Austin", "Folsom", "Juno",
		"Havana", "Icehouse", "Grizzly", "Essex", "Diablo","Cactus" };

	for (int i = 0; i < size; i++)
		ph[i].setName(name[i]);

	show_array(ph, size);
	selectionSort(ph, size);
	show_array(ph, size);

	// ���� 3��
	cout << "\n���� 3 ----------------------------------------------------------\n" << endl;

	string target1 = "Juno";
	string target2 = "Nova";

	cout << target1 << "�� " << binary_search(ph, size, target1) << "�� �ε����� ����\n" << endl;
	cout << target2 << "�� " << binary_search(ph, size, target2) << "�̹Ƿ� �������� ����" << endl;

	//���� 4��
	cout << "\n���� 4 ----------------------------------------------------------\n" << endl;

	int mask_stocks[size] = { 50, 100, 80, 90, 0, 30, 20, 60, 70, 10 };

	for (int i = 0; i < size; i++)
		ph[i].setMask(mask_stocks[i]);
	show_array(ph, size);
	quick_sort_descending(ph, 0, size - 1);
	show_array(ph, size);

	//���� 5�� 
	cout << "\n���� 5 ----------------------------------------------------------\n" << endl;

	cout << "(1)" << endl;
	cnt = 0;
	quick_sort_ascending(ph, 0, size - 1);
	show_array(ph, size);
	cout << "����Ƚ��: " << cnt << endl;

	cout << "\n(2)" << endl;
	//�̸����� ���Ľ�Ű��
	selectionSort(ph, size);
	cnt = 0;
	quick_sort_ascending(ph, 0, size - 1);
	show_array(ph, size);
	cout << "����Ƚ��: " << cnt << endl;
	cout << "\n< �� �� >\n" << endl;
	cout << "ù��° ���� �־��� ����� quick sort�̱� ������ O(n^2)�� �ð����⵵�� ���´�.\n\
�ݸ� �ι�° ���� ������� ��쿡 ���� quick sort�� ������ ���̹Ƿ� O(nlogn)��\n\
�ð����⵵�� ���´�. quick sort�� �ð����⵵�� case�� ���� �ٸ��� ������ ������\n\
���� ���� �ι���� ���̰� ���� ���̴�.\n\n" << endl;
	return 0;
}

void show_array(Pharmacy ph[], int size) {
	//precondition: "ph" is a Pharmacy class's array type sized "size"
	for (int i = 0; i < size; i++)
		cout << i + 1 << "�� �౹��: " << ph[i].getName() << ", ����ũ ���: " << ph[i].getMask() << endl;
	cout << endl;
	//postcondtion: print all pharmacy's name and remaining mask stock  
	//return: None
}

void swapElement(Pharmacy ph[], int a, int b) {
	//precondition: "ph" is a Pharmacy class's array type 
	//a and b are Pharmacy array's indexs

	Pharmacy tmp = ph[a];
	ph[a] = ph[b];
	ph[b] = tmp;

	//postcondition: ph[a] and ph[b] are swapped
	//return: None
}

int maxSelect(Pharmacy p[], int n) {
	//precondition: "p" is a Pharmacy class's array type sized "n"

	int maxPos = 0;
	for (int i = 1; i < n;i++)
		if (p[maxPos].getName().compare(p[i].getName()) == -1)
			maxPos = i;

	//postcondition:maxPos becomes index which has max value from index 0 to index n-1 

	return maxPos;
	//return: returns maxPos index 
}
void selectionSort(Pharmacy p[], int size) {

	//precondition: "p" is a Pharmacy class's array type sized "size"
	int last(size - 1);
	int maxPos;

	while (last > 0) {
		maxPos = maxSelect(p, last + 1);
		swapElement(p, maxPos, last);
		last--;
	}

	//postcondition: "p" is sorted in ascending order 
	//return: None
}
int binary_search(Pharmacy p[], int size, string target_name) {

	//precondition: "p" is a Pharmacy class's array type sized "size"
	// target_name is a target to find 
	int first = 0;
	int last = size - 1;

	while (first <= last) {
		int mid = (first + last) / 2;
		if (p[mid].getName().compare(target_name) == 0) {
			return mid;
			//return: if target_name exist in p, returns the index target_name locates
			//if not, returns -1
		}
		else if (p[mid].getName().compare(target_name) == 1)
			last = mid - 1;
		else
			first = mid + 1;
	}
	//postcondition: None
	return -1;
}

int partition_descending(Pharmacy ph[], int first, int last) {
	//precondition: "ph" is a Pharmacy class's array with first index and last index 
	int lastBig(first);

	for (int i = first + 1; i <= last; i++)
		if (ph[first].getMask() <= ph[i].getMask()) {
			lastBig++;
			swapElement(ph, lastBig, i);
		}

	swapElement(ph, lastBig, first);
	//postcondition: there are bigger values than ph[lastBig]'s masks  in left side of lastBig index
	// and there are smaller values  than ph[lastBig]'s masks  in right side of lastBig index

	return lastBig;
	//return: returns pivot of "ph"
}
void quick_sort_descending(Pharmacy ph[], int first, int last) {
	//precondition: "ph" is a Pharmacy class's array with first index and last index 

	if (first >= last)
		return;
	int pivot(partition_descending(ph, first, last));
	quick_sort_descending(ph, first, pivot - 1);
	quick_sort_descending(ph, pivot + 1, last);

	//postcondition: ph's remaining masks are sorted in ascending order between first index to last inclusive
	//return: None
}
int partition_ascending(Pharmacy ph[], int first, int last) {

	//precondition: "ph" is a Pharmacy class's array with first index and last index 
	int lastSmall(first);

	for (int i = first + 1; i <= last; i++) {
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

	//postcondition: there are smaller values than ph[lastSmall]'s name  in left side of lastSmall
	// and there are bigger values  than ph[lastSmall]'s names  in right side of lastSmall

	return lastSmall;
	//return: returns pivot of "ph"
}
void quick_sort_ascending(Pharmacy ph[], int first, int last) {

	//precondition: "ph" is a Pharmacy class's array with first index and last index 
	cnt++;
	if (first >= last)
		return;
	int pivot(partition_ascending(ph, first, last));
	quick_sort_ascending(ph, first, pivot - 1);
	quick_sort_ascending(ph, pivot + 1, last);

	//postcondition: ph's masks are sorted in ascending order between first index to last inclusive
	//return: None
}