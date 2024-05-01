#include "VectorStorage.h"

VectorStorage::VectorStorage()
{
	std::vector<std::string> dictionary;
}


void VectorStorage::setup(std::string path)
{
	std::ifstream file;
	file.open(path);

	std::string line;
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			VectorStorage::dictionary.push_back(line);
		}
	}
	file.close();
}



bool VectorStorage::find(std::string word)
{
	int first = 0;
	int last = dictionary.size() - 1;

	while (first <= last)
	{
		int middle = first + (last - first) / 2;

		if (word == dictionary.at(middle))
		{
			return true;
		}
		else if (dictionary.at(middle) < word)
		{
			first = middle + 1;
		}
		else
		{
			last = middle - 1;
		}
	}
	return false;
}