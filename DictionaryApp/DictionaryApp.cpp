#include <iostream>
#include <vector>
#include <chrono>

#include "VectorStorage.h"
#include "TrieStorage.h"
#include "HashMapStorage.h"
#include "AVLTreeStorage.h"
#include "BookAnalyser.h"
const std::string PATH_TEST = "texts/test.txt";
const std::string PATH_TEST2 = "texts/test2.txt";
const std::string PATH_DICTIONARY = "texts/Dictionary.txt";
const std::string PATH_ALICE = "texts/alice.txt";
const std::string PATH_TOLSTOY = "texts/tolstoy.txt";
const std::string PATH_DRACULA = "texts/dracula.txt";
const std::string PATH_HOLMES = "texts/holmes.txt";
const std::string PATH_SHERLOCK = "texts/sherlock.txt";

int main()
{
    BookAnalyser b(PATH_DICTIONARY);



    std::cout << "=====================================================" << std::endl;

    for (int code = 0; code < b.dictionaries.size(); code++)
    {
        int words[3] = { 0,0,0 };
        int alltime = 0;
        
        std::cout << typeid(*b.dictionaries[code]).name() << std::endl << std::endl;
        
        auto beg = std::chrono::high_resolution_clock::now();
        
        std::cout << PATH_ALICE << std::endl;
        b.AnalyseBook(PATH_ALICE, code, words);
        
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - beg);
        std::cout << "Time elapsed: " << duration.count() << " ms" << std::endl;
        alltime += duration.count();

        beg = std::chrono::high_resolution_clock::now();
        
        std::cout << std::endl << PATH_TOLSTOY << std::endl;
        b.AnalyseBook(PATH_TOLSTOY, code, words);
        
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - beg);
        std::cout << "Time elapsed: " << duration.count() << " ms" << std::endl;
        alltime += duration.count();

        beg = std::chrono::high_resolution_clock::now();

        std::cout << std::endl << PATH_DRACULA << std::endl;
        b.AnalyseBook(PATH_DRACULA, code, words);

        duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - beg);
        std::cout << "Time elapsed: " << duration.count() << " ms" << std::endl;
        alltime += duration.count();

        beg = std::chrono::high_resolution_clock::now();

        std::cout << std::endl << PATH_HOLMES << std::endl;
        b.AnalyseBook(PATH_HOLMES, code, words);

        duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - beg);
        std::cout << "Time elapsed: " << duration.count() << " ms" << std::endl;
        alltime += duration.count();

        beg = std::chrono::high_resolution_clock::now();

        std::cout << std::endl << PATH_SHERLOCK << std::endl;
        b.AnalyseBook(PATH_SHERLOCK, code, words);

        duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - beg);
        std::cout << "Time elapsed: " << duration.count() << " ms" << std::endl;
        alltime += duration.count();

        std::cout << std::endl << "Total words: " << words[0] << std::endl;
        std::cout << "Correct words: " << words[1] << std::endl;
        std::cout << "Incorrect words: " << words[2] << std::endl;
        std::cout << std::endl << "Overall time: " << alltime << std::endl;
        std::cout << "=====================================================" << std::endl;
    }
}