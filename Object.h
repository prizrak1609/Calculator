#pragma once
class Object
{
public:
	enum class Type {
		Number,
		OperationPlus,
		OperationMinus,
		OperationMultiply,
		OperationDivide
	};

	Object(Object::Type type, int number);

	Type getType();
	int getNumber();

private:
	Type type;
	int number;
};

