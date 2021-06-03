// 20160518 오승주 RBT implementation homework
#pragma once
#include <iostream>
#include "BST.h"
#include<string>
using namespace std;
enum Color {Red, Black};
template < class btElementType >
class RBT : public BST <int>
{
public:
	RBT();
	void insert(btElementType& d);
	string getColor();
	RBT <btElementType>* left();
	RBT <btElementType>* right();
	
protected:
	void printCase();
	void rotateLeft(RBT*& root, RBT*& pt);
	void rotateRight(RBT*& root, RBT*& pt);
	void resolve(RBT*& root, RBT*& pt);
	RBT(btElementType data, Color color, bool nullTree);
	RBT <btElementType>* getRoot(RBT* root, RBT* pt, btElementType& d);
	Color color;
	RBT* root;
	RBT* parent;
};


template<class btElementType>
RBT<btElementType>::RBT() : BST(){
	color = Red;
	root = 0;
}


template<class btElementType>
RBT<btElementType>::RBT(btElementType data, Color color, bool nullTree){
	this->data = data;
	this->color = color;
	this->nullTree = nullTree;
}

template<class btElementType>
string
RBT<btElementType>::getColor() {
	if (color == Red)
		return "R";
	else if(color==Black)
		return "B";
}
template<class btElementType>
RBT <btElementType>* 
RBT<btElementType>::left() {
	return (RBT <btElementType>*)(BST::left());
}
template<class btElementType>
RBT <btElementType>* 
RBT<btElementType>::right() {
	return (RBT <btElementType>*)(BST::right());
}

//20160518 오승주 
template < class btElementType >
void RBT<btElementType>::resolve(RBT*& root, RBT*& pt){	
	cout << endl;
	RBT* parent_pt = NULL;
	RBT* grand_parent_pt = NULL;
	while ((pt != root) && (pt->color != Black) && (pt->parent->color == Red)){
		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;
		if (parent_pt == grand_parent_pt->left()){
			RBT* uncle_pt = grand_parent_pt->right();
			if (!uncle_pt->isEmpty() && uncle_pt->color == Red){
				grand_parent_pt->color = Red;
				parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = grand_parent_pt;
			}
			else {
				if (pt == parent_pt->right()){
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}
				rotateRight(root, grand_parent_pt);
				Color tmp = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = tmp;
				pt = parent_pt;
			}
		}
		else {
			cout << "실행 전" << endl;
			printCase();
			RBT* uncle_pt = grand_parent_pt->left();
			if ((!uncle_pt->isEmpty()) && (uncle_pt->color == Red)) {
				grand_parent_pt->color = Red;
				parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = grand_parent_pt;
				cout << "실행 후" << endl;
				printCase();
			}
			else {
				if (pt == parent_pt->left()) {
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				
					cout << "실행 후" << endl;
					printCase();
					
				}
				cout << "실행 전" << endl;
				printCase();
				rotateLeft(root, grand_parent_pt);
				Color tmp = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = tmp;
				pt = parent_pt;
				cout << "실행 후" << endl;
				printCase();
			}
		}
	}
	root->color = Black;
}

template <class btElementType>
void RBT<btElementType>::rotateLeft(RBT*& root, RBT*& pt)
{
	RBT* pt_right = pt->right();
	pt->rightTree = pt_right->left();

	if (!pt->right()->isEmpty())
		pt->right()->parent = pt;

	pt_right->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_right;

	else if (pt == pt->parent->leftTree)
	pt->parent->leftTree = pt_right;

	else
		pt->parent->rightTree = pt_right;

	pt_right->leftTree = pt;
	pt->parent = pt_right;
}



template <class btElementType>
void RBT<btElementType>::rotateRight(RBT*& root, RBT*& pt)
{
	RBT* pt_left = pt->left();

	pt->leftTree = pt_left->right();

	if (!pt->left()->isEmpty())
		pt->left()->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_left;

	else if (pt == pt->parent->leftTree)
		pt->parent->leftTree = pt_left;

	else
		pt->parent->rightTree = pt_left;

	pt_left->rightTree = pt;
	pt->parent = pt_left;
}
//20160518 오승주 
template < class btElementType >
void RBT <btElementType>::insert(btElementType& d)
{
	RBT<btElementType>* pt = new RBT(d, Red, false);
	root = getRoot(root, pt, d);
	resolve(root, pt);
}

template < class btElementType >
RBT <btElementType>* RBT <btElementType>::getRoot(RBT* root, RBT* pt, btElementType& d)
{
	if (root == NULL || root->isEmpty()) {
		pt->leftTree = new RBT(d, Black, true);
		pt->rightTree = new RBT(d, Black, true);
		return pt;
	}
	if (pt->getData() < root->getData())
	{
		root->leftTree = getRoot(root->left(), pt, d);
		root->left()->parent = root;
	}
	else if (pt->getData() > root->getData())
	{
		root->rightTree = getRoot(root->right(), pt, d);
		root->right()->parent = root;
	}
	return root;
}
template < class btElementType >
void
RBT <btElementType>::printCase() {
	cout << endl;
	cout << "-------------------------< case >------------------------" << endl;

	if (root->isEmpty())
		cout << "\t\t" << 0;
	else {
		cout << "\t\t" << root->getData() << "/" << root->getColor() << endl;


		if (root->left()->isEmpty())
			cout << "\t" << 0;
		else {
			cout << "\t" << root->left()->getData() << "/" << root->left()->getColor();
		}

		if (root->right()->isEmpty())
			cout << "\t\t" << 0 << endl;
		else {
			cout << "\t\t" << root->right()->getData() << "/" << root->right()->getColor() << endl;
		}

		if (root->left()->isEmpty()||root->left()->left()->isEmpty())
			cout << 0;
		else
			cout << root->left()->left()->getData() << "/" << root->left()->left()->getColor();

		if (root->left()->isEmpty() || root->left()->right()->isEmpty())
			cout << "\t\t" << 0;
		else
			cout << "\t\t" << root->left()->right()->getData() << "/" << root->left()->right()->getColor();
		cout << "  ";
		if (root->right()->isEmpty() || root->right()->left()->isEmpty())
			cout << "" << 0;
		else
			cout << "" << root->right()->left()->getData() << "/" << root->right()->left()->getColor();


		if (root->right()->isEmpty() || root->right()->right()->isEmpty())
			cout << "\t\t" << 0 << endl;
		else
			cout << "\t\t" << root->right()->right()->getData() << "/" << root->right()->right()->getColor() << endl;;


		if (root->right()->isEmpty() || root->right()->right()->isEmpty() || root->right()->right()->left()->isEmpty())
			cout << "\t\t\t";
		else
			cout << "\t\t\t" << root->right()->right()->left()->getData() << "/" << root->right()->right()->left()->getColor();
		if (root->right()->isEmpty() || root->right()->right()->isEmpty() || root->right()->right()->right()->isEmpty())
			cout << endl;
		else
			cout << "\t\t" << root->right()->right()->right()->getData() << "/" << root->right()->right()->right()->getColor();

		cout << endl;
	}
}