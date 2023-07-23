#include "Object.h"

Object::Object(Object::Type type, int number)
{
	this->type = type;
	this->number = number;
}

Object::Type Object::getType()
{
	return Type();
}

int Object::getNumber()
{
	return 0;
}
