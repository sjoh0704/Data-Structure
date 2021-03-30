#pragma once
using namespace std;
class Value
{
private:
	int v;
public:
	Value();
	Value(int);
	void setValue(int);
	int getValue();
	bool operator>=(const Value& v);

};

