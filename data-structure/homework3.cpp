#include<iostream>
#include"RBT.h"
#include<queue>
using namespace std; 
typedef RBT<int> intRBT;
typedef intRBT* RBTPtr;
int main() {

	RBTPtr a = new intRBT;
	int v[7] = { 3, 2, 4, 1, 7, 5, 8};
	a->insert(v[0]); //3

	a->insert(v[1]);

	a->insert(v[2]);

	a->insert(v[3]);

	a->insert(v[4]);
	cout << "20160518 ������" << endl;

	cout << "=======================================================================" << endl;
	cout << "���� Red Black Tree�� 5 insert�ϱ�" << endl;
	a->insert(v[5]);
	cout << "=======================================================================" << endl;


	cout << "20160518 ������" << endl;

	cout << "=======================================================================" << endl;
	cout << "���� Red Black Tree�� 8 insert�ϱ�" << endl;
	a->insert(v[6]);
	cout << "=======================================================================" << endl;



	return 0;
}
