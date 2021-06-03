#include<iostream>
#include"RBT.h"
#include<queue>
using namespace std; 
typedef RBT<int> intRBT;
typedef intRBT* RBTPtr;
void printTree(RBTPtr start);
int main() {

	RBTPtr a = new intRBT;
	int v[7] = { 3, 2, 4, 1, 7, 5, 8};
	a->insert(v[0]); //3

	a->insert(v[1]);

	a->insert(v[2]);
	//printTree(a);
	a->insert(v[3]);
	//printTree(a);
	a->insert(v[4]);
	//printTree(a);
	//ÀÌºÎºÐ
	a->insert(v[5]);
	//printTree(a);
	a->insert(v[6]);
	//printTree(a);
	a->insert(v[7]);
	//printTree(a);
	return 0;
}

void printTree(RBTPtr start){
	cout << endl;
	cout << "------------------------------------------------------------" << endl;

	if (start->root->isEmpty())
		cout <<"\t\t"<< 0;
	else
		cout << "\t\t" << start->root->getData() << "/" << start->root->getColor() << endl;

	
	if (start->root->left()->isEmpty())
		cout <<"\t"<< 0;
	else
		cout << "\t" << start->root->left()->getData()<< "/" << start->root->left()->getColor();


	if (start->root->right()->isEmpty())
		cout << "\t\t" << 0 << endl;
	else
		cout << "\t\t" << start->root->right()->getData() << "/" << start->root->right()->getColor() << endl;


	if (start->root->left()->left()->isEmpty())
		cout <<0;
	else
		cout <<start->root->left()->left()->getData() << "/" << start->root->left()->left()->getColor();

	if (start->root->left()->right()->isEmpty())
		cout << "\t\t" <<0;
	else
	cout << "\t\t" << start->root->left()->right()->getData() << "/" << start->root->left()->right()->getColor();
	cout << "  ";
	if (start->root->right()->left()->isEmpty())
		cout << "" << 0;
	else
		cout << "" << start->root->right()->left()->getData() << "/" << start->root->right()->left()->getColor();

	
	if (start->root->right()->right()->isEmpty())
		cout << "\t\t" << 0 << endl;
	else
		cout << "\t\t" << start->root->right()->right()->getData() << "/" << start->root->right()->right()->getColor();

	

}