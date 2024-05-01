#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "Dictionary.h"
class TrieStorage : public Dictionary
{
public:
	struct TrieNode;

	static const int CHARACTER_RANGE = 27;
	std::shared_ptr<TrieNode> root;

	TrieStorage();
	void setup(std::string path) override;
	bool find(std::string key) override;


private:
	void insert(std::shared_ptr<TrieNode> root, std::string key);
	std::shared_ptr<TrieNode> createNode();
};

