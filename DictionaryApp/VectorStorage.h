#pragma once
#include "BookAnalyser.h"
#include "Dictionary.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

class VectorStorage : public Dictionary
{
public:
	VectorStorage();
	void setup(std::string path) override;
	bool find(std::string word) override;
private:
	std::vector<std::string> dictionary;
};
