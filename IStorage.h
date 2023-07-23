#pragma once
#include <vector>
#include "Object.h"

struct IStorage
{
	virtual void store(std::vector<Object> objects) = 0;
	virtual std::vector<Object> getExpression() = 0;
	virtual void replace(std::vector<Object>, Object number) = 0;

	virtual ~IStorage() = default;
};
