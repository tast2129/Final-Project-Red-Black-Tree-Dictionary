#include <iostream>
#include <string>

#include "../code/RedBlackTree.h"
#include "Dictionary.h"

using namespace std;

int main(){

    Dictionary dict;
    int choice;
    string word, definition, filename;

    // use switch statements to give the user the option to use different functions

    while (true) {
        // display the menu with options for user
        cout << endl << "--- Dictionary Menu ---" << endl;
        cout << "1. Add a word" << endl;
        cout << "2. Delete a word" << endl;
        cout << "3. Find a word" << endl;
        cout << "4. Display all words" << endl;
        cout << "5. Save to file" << endl;
        cout << "6. Load from file" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";

        // take in the users request
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word: ";
                getline(cin, word);
                cout << "Enter definition: ";
                getline(cin, definition);
                dict.addWord(word, definition);
                cout << "Word added." << endl;
                break;
            case 2:
                cout << "Enter word to delete: ";
                getline(cin, word);
                dict.deleteWord(word);
                cout << "Word deleted (if it existed)." << endl;
                break;
            case 3:
                cout << "Enter word to find: ";
                getline(cin, word);
                cout << "Definition: " << dict.findWord(word) << endl;
                break;
            case 4:
                cout << endl << "--- Dictionary Words ---" << endl;
                dict.displayAll();
                break;
            case 5:
                cout << "Enter filename to save to: ";
                getline(cin, filename);
                dict.saveToFile(filename);
                cout << "Dictionary saved." << endl;
                break;
            case 6:
                cout << "Enter filename to load from: ";
                getline(cin, filename);
                dict.loadFromFile(filename);
                cout << "Dictionary loaded." << endl;
                break;
            case 0:
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid choice, try again" << endl;
        }
    }

    return 0;
}
