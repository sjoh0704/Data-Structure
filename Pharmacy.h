#pragma once
#include<iostream>
#include<string>
using namespace std;
class Pharmacy
{
	
private:
	
	char name;
	int distance;
	int mask_stock;
	int arrival_time;

public:
	static int count;
	char getName();
	void setName(char);
	Pharmacy();
	

};

