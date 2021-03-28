#include "Pharmacy.h"

Pharmacy::Pharmacy() {
	count += 1;

	name = ' ';
	mask_stock = 0;
	distance = 0;
	arrival_time = 0;

}

char Pharmacy::getName() {
	return name;
}
void Pharmacy::setName(char name) {
	this->name = name;
}
