#include "TrieStorage.h"

TrieStorage::TrieStorage()
{
	root = createNode();
}

struct TrieStorage::TrieNode
{
	std::shared_ptr<TrieNode> children[CHARACTER_RANGE];
	bool isEndOfWord;
};

std::shared_ptr<TrieStorage::TrieNode> TrieStorage::createNode()
{
	std::shared_ptr<TrieNode> pNode = std::make_shared<TrieNode>();

	pNode->isEndOfWord = false;

	for (int i = 0; i < TrieStorage::CHARACTER_RANGE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}

void TrieStorage::insert(std::shared_ptr<TrieNode> root, std::string key)
{

	std::shared_ptr<TrieNode> pCrawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = 0;
		(key[i] != 39) ? index = key[i] - 'a' : index = 26;
		if (pCrawl->children[index] == nullptr)
		{
			std::shared_ptr<TrieNode> ptr = createNode();
			pCrawl->children[index] = ptr;
		}
		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
}

bool TrieStorage::find(std::string key)
{
	std::shared_ptr<TrieNode> pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index;
		(key[i] != 39) ? index = key[i] - 'a' : index = 26;
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}

void TrieStorage::setup(std::string path)
{
	std::ifstream file;
	file.open(path);

	std::string line;
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			TrieStorage::insert(root, line);
		}
	}
}


