//
// 마스크 구매 프로그램 ADT
//
// Characteristics:
//    This program is about imformation of mask.
//    The information of this program includes pharmacy's name, pharmacy' distance,
//    mask's remaining stock and mask's arrival time
//
// Operations:
//  Pharmacy()
//	  Precondition: Pharmacy instance must be created
//    Postcondition: initialize pharmacy's name, distance, remaining mask stock, mask's arrival time 
//    return: None.
//  string getName()
//	  Precondition: Pharmacy instance must be created
//    Postcondition: None
//    return: returns pharmacy's name
//  void setName(string name)
//	  Precondition: Pharmacy instance must be created
//    Postcondition: Pharmacy's name becomes "name" which is parameter 
//    return: None
//  void setMask(int mask)
//	  Precondition: Pharmacy instance must be created
//    Postcondition: set mask's remaining quantity to "mask" which is parameter 
//    return: None
//  int getMask()
//	  Precondition: Pharmacy instance must be created
//    Postcondition: None
//    return: returns mask's remaining quantity 



#pragma once
#include<iostream>
#include<string>
using namespace std;
class Pharmacy
{
private:
	string name;
	int distance;
	int mask_stock;
	int arrival_time;
public:
	Pharmacy();
	string getName();
	void setName(string);
	void setMask(int);
	int getMask();
};

