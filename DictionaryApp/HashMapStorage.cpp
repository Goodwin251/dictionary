#include "HashmapStorage.h"
HashMapStorage::HashMapStorage()
{
    HashMapStorage::table = std::vector<std::vector<std::string>>(TABLE_SIZE);
    for (std::vector<std::string> v : table)
        v = std::vector<std::string>();
}

unsigned int KeyHash::operator()(const std::string& key) const
{
    unsigned long hash = 5381;
    int c;
    const char* ptr = key.c_str();

    while (c = *ptr++)
        hash = ((hash << 5) + hash) + c;

    return (unsigned int)(hash % TABLE_SIZE);
}


void HashMapStorage::put(const std::string& key)
{
    KeyHash hashFunc;
    unsigned int hashValue = hashFunc(key);
    table.at(hashValue).push_back(key);
}

bool HashMapStorage::find(std::string key)
{
    KeyHash hashFunc;
    unsigned int hashValue = hashFunc(key);
    if (table.at(hashValue).empty())
        return false;
    if (table.at(hashValue).at(0) == key)
        return true;
    for (std::string s : table.at(hashValue))
        if (key == s)
            return true;
    return false;
}
void HashMapStorage::setup(std::string path)
{
    std::fstream file;
    file.open(path);

    std::string line;
    if (file.is_open())
        while (std::getline(file, line))
            put(line);
}
