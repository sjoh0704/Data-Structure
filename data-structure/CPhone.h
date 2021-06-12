#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class CPhone
{
private:
	string name;
	int birthday;

public:
	CPhone();
	CPhone(string, int);
	string getName();
	int getBirthday();
	void setName(string);
	void setBirthday(int);
	friend ostream& operator <<(ostream& outstream, const CPhone& aPhone);
};

