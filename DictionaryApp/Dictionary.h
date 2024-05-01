#pragma once

#include <string>
class Dictionary
{
public:
	virtual void setup(std::string path) = 0;
	virtual bool find(std::string word) = 0;
};