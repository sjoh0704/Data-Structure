//실습 16 chained hash table
#include<iostream>
#include"Table2.h"
#include"CPhone.h"
using namespace std;
int stringToInt(string value);
int main() {
	Table2<int, int> table;
	table.insert(19960704, 19960704);
	table.insert(19960705, 19960705);
	table.insert(19960706, 19960706);
	table.insert(19960707, 19960707);
	table.insert(19960708, 19960708);
	table.insert(19960709, 19960709);
	table.insert(19960710, 19960710);
	table.insert(19960715, 19960715);
	table.insert(19960716, 19960716);
	table.insert(19960717, 19960717);
	table.insert(19960718, 19960718);

	table.dump();


	Table2<int, CPhone> table2;
	table2.insert(19960704, CPhone("James", 19960704));
	table2.insert(19960705, CPhone("Agile", 19960705));
	table2.insert(19960706, CPhone("Nicky", 19960706));
	table2.insert(19960716, CPhone("Ace", 19960705));
	table2.insert(19960717, CPhone("Seung", 19960706));
	table2.dump();

	Table2<int, CPhone> table3;
	table3.insert(stringToInt("James"), CPhone("James", 19960704));
	table3.insert(stringToInt("Agile"), CPhone("Agile", 19960705));
	table3.insert(stringToInt("Nicky"), CPhone("Nicky", 19960706));
	table3.dump();
	CPhone a;

	if (table3.lookup(stringToInt("Agi4le"), a))
		cout << a << endl;
	else
		cout << "존재하지 않습니다." << endl;
	



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