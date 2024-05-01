#include "AVLTreeStorage.h"



AVLTreeStorage::AVLTreeStorage()
{
	root = nullptr;
}

inline int AVLTreeStorage::height(std::shared_ptr<Node> N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

inline int AVLTreeStorage::max(int a, int b)
{
	return (a > b) ? a : b;
}

inline std::shared_ptr<AVLTreeStorage::Node> AVLTreeStorage::newNode(std::string key)
{
	std::shared_ptr<Node> node = std::make_shared<Node>();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;

	return(node);
}

inline std::shared_ptr<AVLTreeStorage::Node> AVLTreeStorage::rightRotate(std::shared_ptr<Node> y)
{
	std::shared_ptr<Node> x = y.get()->left;
	std::shared_ptr<Node> T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	return x;
}

inline std::shared_ptr<AVLTreeStorage::Node> AVLTreeStorage::leftRotate(std::shared_ptr<Node> x)
{
	std::shared_ptr<Node> y = x->right;
	std::shared_ptr<Node> T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	return y;
}

inline int AVLTreeStorage::getBalance(std::shared_ptr<Node> N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

inline std::shared_ptr<AVLTreeStorage::Node> AVLTreeStorage::insert(std::shared_ptr<Node> node, std::string key)
{
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + max(height(node->left),
		height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}
bool AVLTreeStorage::find(std::string key)
{
	return findInTree(root, key);
}
bool AVLTreeStorage::findInTree(std::shared_ptr<Node> node, std::string key)
{
	if (node != NULL)
	{
		if (node->key == key)
			return true;
		else
			return key < node->key ? findInTree(node->left, key) : findInTree(node->right, key);
	}
	else
		return false;
}

void AVLTreeStorage::setup(std::string path)
{
	std::fstream file;
	file.open(path);

	std::string line;
	if (file.is_open())
		while (std::getline(file, line))
			root = insert(root, line);
}
