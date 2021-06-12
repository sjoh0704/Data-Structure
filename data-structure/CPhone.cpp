#include "CPhone.h"
CPhone::CPhone() {
	name = "";
	birthday = 00000000;
}
CPhone::CPhone(string name, int birhtday) {
	this->name = name;
	this->birthday = birhtday;
}
string CPhone::getName() {
	return name;
}
int CPhone::getBirthday() {
	return birthday;
}
void CPhone::setName(string name) {
	this->name = name;
}
void CPhone::setBirthday(int birthday) {
	this->birthday = birthday;
}
