#ifndef DICTIONARY_H__
#define DICTIONARY_H__

#include <memory>
#include <string>
#include <iostream>
#include <fstream>

#include "RedBlackTree.h" 

using namespace std;

class Dictionary {
public:
    void addWord(string word, string definition);
    void deleteWord(string word);
    string findWord(string word);
    void displayAll();
    void saveToFile(string filename);
    void loadFromFile(string filename);
private:
    RedBlackTree tree;
};


#endif // DICTIONARY_H__