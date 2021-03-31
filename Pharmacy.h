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
	
	string getName();
	void setName(string);
	void setMask(int);
	int getMask();
	Pharmacy();
	

};

