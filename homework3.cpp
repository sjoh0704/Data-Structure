#include<iostream>
#include"RBT.h"
#include<queue>
using namespace std; 
typedef RBT<int> intRBT;
typedef intRBT* RBTPtr;
void printTree(RBTPtr start);
int main() {

	RBTPtr a = new intRBT;
	int v[7] = { 3, 4, 2, 1, 5, 7, 8};
	a->insert(v[0]);
	a->insert(v[1]);
	a->insert(v[2]);
	a->insert(v[3]);

	printTree(a);
	RBTPtr get11((RBTPtr)(a->retreive(v[3])));
	if (get11->isEmpty())
		cout << "not found" << endl;
	else
		cout << "found" << endl;

	return 0;
}

void printTree(RBTPtr start){

	cout << start->getData() << "/" << start->getColor()<<endl;
	
	if (start->left()->isEmpty())
		cout << 0;
	else
		cout << start->left()->getData()<< "/" << start->left()->getColor();


	if (start->right()->isEmpty())
		cout << "\t" << 0 << endl;
	else
		cout << "\t" << start->right()->getData() << "/" << start->right()->getColor() << endl;


	if (start->left()->left()->isEmpty())
		cout <<0;
	else
		cout <<start->left()->left()->getData() << "/" << start->left()->left()->getColor();

	if (start->left()->right()->isEmpty())
		cout << "\t" <<0;
	else
	cout << "\t" << start->left()->right()->getData() << "/" << start->left()->right()->getColor();

	if (start->right()->left()->isEmpty())
		cout << "\t" << 0;
	else
		cout << "\t" << start->right()->left()->getData() << "/" << start->right()->left()->getColor();

	if (start->right()->right()->isEmpty())
		cout << "\t" << 0 << endl;
	else
		cout << "\t" << start->right()->right()->getData() << endl << "/" << start->right()->right()->getColor();

	

}