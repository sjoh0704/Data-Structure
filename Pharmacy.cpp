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
