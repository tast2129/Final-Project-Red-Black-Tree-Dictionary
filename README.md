# Final-Project-Red-Black-Tree-Dictionary
In this project, I implements a dictionary data structure using a Red-Black Tree in C++. The dictionary supports insertion, deletion, search, and traversal of words and their definitions while maintaining balanced tree properties for efficient operations. My project is built to take in a .txt file that has each word and its definition separted by a ":" (word: definiton) and the sets of words are separated by being on separate lines.

A Red-Black Tree is a type of binary search tree that maintains balance by coloring nodes red or black and enforcing the following rules:

1. Every node is either red or black.
2. The root is always black.
3. No two red nodes can be adjacent (a red node cannot have a red parent or child).
4. Every path from a node to its descendant NULL nodes must contain the same number of black nodes.
These rules ensure the tree remains approximately balanced, making operations efficient even in the worst case.

The features of my project include:

Add Word: Insert a word with its definition.
Delete Word: Remove a word from the dictionary.
Find Word: Search for a word and retrieve its definition.
Display All: Inorder traversal to list all words alphabetically.
Save to File: Export the dictionary to a text file.
Load from File: Import dictionary entries from a text file.

To run my project:
1. cd build
2. cmake ..
3. make
4. ./dictionary

In the main file, I use switch statements to give the user a menu of options of functions they can use to build, search, and alter their dicitonary. Based on the input from the user, different functions are called.

I started by creating my RedBlackTree files to create the basic functions for my data structure. I made a structure for the nodes of the red black tree that would hold the word and defintion, color of the node, and a pointer to the parent and children. I also created a class for the redblack tree. I used helper functions and recursion to try to keep my code both readable and concise. The biggest challenge was maintaining the characteristics of the red black tree with the fixInsert and fixDelete functions. Once I completed these files I was able to create my Dicitonary files that called functions from the RedBlackTree file. 


