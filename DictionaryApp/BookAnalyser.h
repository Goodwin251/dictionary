#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <memory>
#include <chrono>
#include "Dictionary.h"
#include "VectorStorage.h"
#include "TrieStorage.h"
#include "HashMapStorage.h"
#include "AVLTreeStorage.h"

class BookAnalyser
{
public:
	std::vector<std::shared_ptr<Dictionary>> dictionaries;

	BookAnalyser(std::string path);
	void AnalyseBook(std::string path, int index, int arr[3]);

private:
	bool isWordRight(std::string word, int index);
	std::string toLowCase(std::string str);
};

