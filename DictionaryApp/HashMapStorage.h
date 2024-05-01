#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dictionary.h"

static const int TABLE_SIZE = 15000;

struct KeyHash
{
    unsigned int operator()(const std::string& key) const;
};

class HashMapStorage : public Dictionary
{
public:
    HashMapStorage();
    void setup(std::string path) override;
    bool find(std::string key) override;
private:
    void put(const std::string& key);
    std::vector<std::vector<std::string>> table;
};

