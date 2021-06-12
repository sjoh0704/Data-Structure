#include "Value.h"
#include<iostream>

Value::Value() {
	this->v = 0;
}

 Value::Value(int v) {
	this->v = v;
}

int Value::getValue() {
	return this->v;
}
void Value::setValue(int v) {
	this->v = v;
}

bool Value::operator>=(const Value& value) {
	if (this->v >= value.v)
		return true;
	
	return false;
}
