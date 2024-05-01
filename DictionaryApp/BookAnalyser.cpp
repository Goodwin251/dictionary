#include "BookAnalyser.h"
BookAnalyser::BookAnalyser(std::string path)
{
	AVLTreeStorage* ptra = new AVLTreeStorage;
	HashMapStorage* ptrh = new HashMapStorage;
	TrieStorage* ptrt = new TrieStorage;
	VectorStorage* ptrv = new VectorStorage;

	std::shared_ptr<Dictionary> sp1(ptra);;
	std::shared_ptr<Dictionary> sp2(ptrh);;
	std::shared_ptr<Dictionary> sp3(ptrt);;
	std::shared_ptr<Dictionary> sp4(ptrv);;

	dictionaries.push_back(sp1);
	dictionaries.push_back(sp2);
	dictionaries.push_back(sp3);
	dictionaries.push_back(sp4);

	//2MB

	//dictionaries.at(0)->setup(path); //40MB AVLTreeStorage
	//dictionaries.at(1)->setup(path); //25MB HashMapStorage
	//dictionaries.at(2)->setup(path); //223MB TrieStorage
	//dictionaries.at(3)->setup(path); //33MB VectorStorage
	for (std::shared_ptr<Dictionary> d : dictionaries)
	{
		auto beg = std::chrono::high_resolution_clock::now();
		d->setup(path);
		std::cout << typeid(*d).name() << " is ready." << std::endl;
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - beg);
		std::cout << "Time elapsed: " << duration.count() << " ms" << std::endl;
	}
}


std::string BookAnalyser::toLowCase(std::string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
	}
	return str;
}
bool BookAnalyser::isWordRight(std::string word, int index)
{
	word = toLowCase(word);
	return dictionaries.at(index)->find(word);
}


void BookAnalyser::AnalyseBook(std::string path, int index, int arr[3])
{
	std::ifstream myfile;
	myfile.open(path);
	int total = 0;
	int correctWords = 0;
	int inCorrectWords = 0;

	std::string word = "";
	char c;
	while (myfile.get(c))
	{
		if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		{
			word.push_back(c);
		}
		else if (c == 39 && word.size() > 0)
		{
			word.push_back(c);
		}
		else
		{
			if (word != "")
			{
				if (word.back() == 39)
					word.pop_back();
				total++;
				isWordRight(word, index) ? correctWords++ : inCorrectWords++;
			}
			word = "";
		}
	}
	if (word != "")
	{
		total++;
		isWordRight(word, index) ? correctWords++ : inCorrectWords++;
	}
	std::cout << "Total words : " << total << std::endl;
	std::cout << "Correct words : " << correctWords << std::endl;
	std::cout << "Incorrect words : " << inCorrectWords << std::endl;
	arr[0] += total;
	arr[1] += correctWords;
	arr[2] += inCorrectWords;
}
