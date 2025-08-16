#include "Dictionary.h"

#include <iostream>
using namespace std;

void Dictionary::addWord(string word, string definition){
    // uses the insert function I wrote in the red black tree file to add a word and its definition
    tree.insert(word, definition);
}

void Dictionary::deleteWord(string word){
    // uses the remove function to delte a word from the dictionary
    tree.remove(word);
}

string Dictionary::findWord(string word){
    // uses search from the red black tree file to find the word given
    return tree.search(word);
}

void Dictionary::displayAll(){
    // calls in order traversal which will print the word and its definition together on a line
    tree.inorderTraversal();
}

void Dictionary::saveToFile(string filename) {
    ofstream outFile(filename);

    //check that the file is open
    if (!outFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    tree.inorderToFile(outFile);

    // close the file
    outFile.close();
}

void Dictionary::loadFromFile(string filename) {
    ifstream inFile(filename);

    // checks if the file is open
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file to read from"<< endl;
        return;
    }

    string line;
    while(getline(inFile, line)){
        // looks for ":" to separate words from definitons
        size_t delimPos = line.find(':');
        if (delimPos == string::npos) {
            std::cerr << "Warning: Skipping malformed line: " << line << "\n";
            continue;
        }

        string word = line.substr(0, delimPos);
        string definition = line.substr(delimPos + 1);

        tree.insert(word, definition);
    }

    inFile.close();
}