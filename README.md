# Final-Project-Red-Black-Tree-Dictionary
In this project, I implements a dictionary data structure using a Red-Black Tree in C++. The dictionary supports insertion, deletion, search, and traversal of words and their definitions while maintaining balanced tree properties for efficient operations.

The features include:

Add Word: Insert a word with its definition.
Delete Word: Remove a word from the dictionary.
Find Word: Search for a word and retrieve its definition.
Display All: Inorder traversal to list all words alphabetically.
Save to File: Export the dictionary to a text file.
Load from File: Import dictionary entries from a text file.

In the main file, I use switch statements to give the user a menu of options of functions they can use to build, search, and alter their dicitonary. Based on the input from the user, different functions are called.

I started by creating my RedBlackTree files to create the basic functions for my data structure. I made a structure for the nodes of the red black tree that would hold the word and defintion, color of the node, and a pointer to the parent and children. I also created a class for the redblack tree. I used helper functions and recursion to try to keep my code both readable and concise. The biggest challenge was maintaining the characteristics of the red black tree with the fixInsert and fixDelete functions. Once I completed these files I was able to create my Dicitonary files that called functions from the RedBlackTree file. 


