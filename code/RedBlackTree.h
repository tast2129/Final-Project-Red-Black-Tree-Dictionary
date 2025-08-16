#ifndef REDBLACKTREE_H__
#define REDBLACKTREE_H__

#include <memory>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//INTRO

enum Color{
    RED, 
    BLACK
};

struct Node {
    string key;        //word
    string value;      //the definition
    Color color;

    Node* parent;
    Node* left;
    Node* right;

    // Constructor
    Node(){
        key = "";
        value = "";
        color = RED;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class RedBlackTree {
public:
    RedBlackTree();
    ~RedBlackTree();

    void insert(string key, string value);
    void remove(string key);
    string search(string key);
    void inorderTraversal();
    void inorderToFile(ofstream& out);

private:
    Node* root;

    // Helper functions
    void leftRotate(Node* &node);
    void rightRotate(Node* &node);
    void fixInsert(Node* &node);
    void fixDelete(Node* &node, Node* xParent);
    void transplant(Node* u, Node* v);
    Node* findMin(Node* node);
    Node* searchNode(Node* node, string key);
    void inorderHelper(Node* node);
    void deleteTree(Node* node);
    void inorderToFileHelper(Node* node, ofstream& out);

    // For deletion
    void deleteNode(Node* node);
};

#endif // REDBLACKTREE_H__