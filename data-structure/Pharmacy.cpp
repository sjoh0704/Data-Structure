#include "Pharmacy.h"

Pharmacy::Pharmacy() {
	

	name = "";
	mask_stock = 0;
	distance = 0;
	arrival_time = 0;

}

string Pharmacy::getName() {
	return name;
}
void Pharmacy::setName(string name) {
	this->name = name;
}

void Pharmacy::setMask(int mask) {
	this->mask_stock = mask;
}
int Pharmacy::getMask() {
	return this->mask_stock;
}