#pragma once
#include <string>
#include <fstream>
#include <memory>
#include "Dictionary.h"

class AVLTreeStorage : public Dictionary
{
public:
	struct Node
	{
	public:
		std::string key;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
		int height;
	};
	std::shared_ptr<Node> root;

	AVLTreeStorage();
	void setup(std::string path) override;
	bool find(std::string key) override;
private:
	bool findInTree(std::shared_ptr<Node> node, std::string key);
	int height(std::shared_ptr<Node> N);
	int max(int a, int b);
	int getBalance(std::shared_ptr<Node> N);
	std::shared_ptr<Node> newNode(std::string key);
	std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> y);
	std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> x);
	std::shared_ptr<Node> insert(std::shared_ptr<Node> node, std::string key);
};

