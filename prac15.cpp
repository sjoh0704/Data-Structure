//practice 15 
// array hashtable
#include<iostream>
#include"Table.h"
#include"CPhone.h"
int stringToInt(string value);
int main()
{


	Table<int, int> table1;

	// 1번 dump
	table1.insert(19960704, 19960704);
	table1.insert(19960705, 19960705);
	table1.insert(19960706, 19960706);
	table1.insert(19960707, 19960707);
	table1.insert(19960708, 19960708);
	table1.insert(19960709, 19960709);
	table1.insert(19960710, 19960710);
	table1.dump();
	
	
	// 2번 dump
	table1.deleteKey(19960707);
	table1.deleteKey(19960705);
	table1.insert(19960718, 19960718);
	table1.dump();


	//3번 dump
	Table<int, CPhone> table2;
	table2.insert(19960704, CPhone("James", 19960704));
	table2.insert(19960705, CPhone("Agile", 19960705));
	table2.insert(19960706, CPhone("Nicky", 19960706));
	table2.dump();


	//4번 dump
	Table<int, CPhone> table3;
	table3.insert(stringToInt("James"), CPhone("James", 19960704));
	table3.insert(stringToInt("Agile"), CPhone("Agile", 19960705));
	table3.insert(stringToInt("Nicky"), CPhone("Nicky", 19960706));
	table3.dump();
	CPhone a;
	table3.lookup(stringToInt("Agile"), a);
	cout << a << endl;

	return 0;
}

int stringToInt(string value) {

	int sum = 0;
	for (int i = 0; i < value.size(); i++)
		sum += value.at(i);

	return sum;
}
ostream& operator <<(ostream& outStream, const CPhone& aphone) {

	outStream << "Name: " << aphone.name << " BirthDay: " << aphone.birthday << endl;
	return outStream;
}