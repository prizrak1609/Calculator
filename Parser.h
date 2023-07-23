#pragma once
#include <string>
#include <vector>

class Parser
{
public:
	int eval(std::string text);

private:
	std::vector<std::string> split(std::string text);
};

