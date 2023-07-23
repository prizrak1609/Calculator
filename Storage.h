#pragma once
#include "IStorage.h"

class Storage : public IStorage
{
public:
	static IStorage* getInstance();
};

