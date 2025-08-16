#include "RedBlackTree.h"

#include <iostream>
using namespace std;

RedBlackTree::RedBlackTree(){
    // set root to nullptr to create an empty tree
    root = nullptr;
}

RedBlackTree::~RedBlackTree(){
    // calls recursive helper function
    deleteTree(root);
}

void RedBlackTree::insert(string key, string value){
    //create new node to be added
    Node* newNode = new Node();

    Node* current = root;

    // first find the correct parent
    while (current != nullptr) {
        newNode->parent = current;
        if(key < current->key){
            current = current->left;
        }
        else if(key > current->key){
            current = current->right;
        }
        else {
            // word already exists in the dkctionary; update definition
            current->value = value;
            delete newNode; // we don't need the new node
            return;
        }
    }

    // next place the new node "under" the correct parent node
    if (newNode->parent == nullptr) {
        root = newNode; // tree was empty
    } else if (key < newNode->parent->key) {
        newNode->parent->left = newNode;
    } else {
        newNode->parent->right = newNode;
    }

    //call fix up to keep characteristics of the new node in line with red black tree characteristics
    fixInsert(newNode);
}

void RedBlackTree::remove(string key){
    // use the search function to first find the correct node
    Node* node = searchNode(root, key);

    // if the node is found, delete it
    if (node != nullptr) {
        deleteNode(node);
    }
}

string RedBlackTree::search(string key){
    // calls the helper function and return the word if found
    Node* result = searchNode(root, key);
    if(result != nullptr){
        return result->value;
    }
    else{
        return "Word not found.";
    }
}

void RedBlackTree::inorderTraversal(){
    // does in order tranversal and prints each word and definition on a new line
    // call the private helper function
    inorderHelper(root);
}

void RedBlackTree::inorderToFile(ofstream& out) {
    // calls the helper function
    inorderToFileHelper(root, out);
}

//HELPER FUNCTIONS:

void RedBlackTree::leftRotate(Node* &node){
    if(node == nullptr || node->right == nullptr){
        return;
    }

    Node* newParent = node->right;
    node->right = newParent->left;

    if(newParent->left != nullptr){
        newParent->left->parent = node;
    }

    newParent->parent = node->parent;

    if(node->parent == nullptr) {
        root = newParent;
    } 
    else if (node == node->parent->left) {
        node->parent->left = newParent;
    } 
    else {
        node->parent->right = newParent;
    }

    newParent->left = node;
    node->parent = newParent;

}

void RedBlackTree::rightRotate(Node* &node){
    if (node == nullptr || node->left == nullptr){
        return;
    }

    Node* newParent = node->left;
    node->left = newParent->right;

    if(newParent->right != nullptr){
        newParent->right->parent = node;
    }

    newParent->parent = node->parent;

    if (node->parent == nullptr){
        root = newParent;
    } 
    else if (node == node->parent->left){
        node->parent->left = newParent;
    } 
    else {
        node->parent->right = newParent;
    }

    newParent->right = node;
    node->parent = newParent;
}

void RedBlackTree::fixInsert(Node* &node){
    while(node != root && node->parent->color == RED){
        Node* parent = node->parent;
        Node* grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            // Case 1: Uncle is RED → Recolor
            if (uncle != nullptr && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                // Case 2: Node is right child → Left rotate
                if (node == parent->right) {
                    node = parent;
                    leftRotate(node);
                    parent = node->parent;  // Update parent after rotation
                }

                // Case 3: Node is left child → Right rotate
                parent->color = BLACK;
                grandparent->color = RED;
                rightRotate(grandparent);
            }
        } else {
            // Mirror cases if parent is right child
            Node* uncle = grandparent->left;

            // Case 1
            if (uncle != nullptr && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                // Case 2
                if (node == parent->left) {
                    node = parent;
                    rightRotate(node);
                    parent = node->parent;
                }

                // Case 3
                parent->color = BLACK;
                grandparent->color = RED;
                leftRotate(grandparent);
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::fixDelete(Node* &node, Node* xParent){
    while (node != root && (node == nullptr || node->color == BLACK)) {
        if (node == xParent->left) {
            Node* w = xParent->right;

            if (w != nullptr && w->color == RED) {
                // Case 1: Sibling is red
                w->color = BLACK;
                xParent->color = RED;
                leftRotate(xParent);
                w = xParent->right;
            }

            // Case 2: Sibling's children are black
            if ((w->left == nullptr || w->left->color == BLACK) &&
                (w->right == nullptr || w->right->color == BLACK)) {
                w->color = RED;
                node = xParent;
                xParent = node->parent;
            } else {
                // Case 3: Sibling's right child is black
                if (w->right == nullptr || w->right->color == BLACK) {
                    if (w->left != nullptr)
                        w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = xParent->right;
                }

                // Case 4: Sibling's right child is red
                w->color = xParent->color;
                xParent->color = BLACK;
                if (w->right != nullptr)
                    w->right->color = BLACK;
                leftRotate(xParent);
                node = root;
                break;
            }
        } else {
            // Mirror image of above (x is right child)
            Node* w = xParent->left;

            if (w != nullptr && w->color == RED) {
                // Case 1
                w->color = BLACK;
                xParent->color = RED;
                rightRotate(xParent);
                w = xParent->left;
            }

            // Case 2
            if ((w->right == nullptr || w->right->color == BLACK) &&
                (w->left == nullptr || w->left->color == BLACK)) {
                w->color = RED;
                node = xParent;
                xParent = node->parent;
            } else {
                // Case 3
                if (w->left == nullptr || w->left->color == BLACK) {
                    if (w->right != nullptr)
                        w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = xParent->left;
                }

                // Case 4
                w->color = xParent->color;
                xParent->color = BLACK;
                if (w->left != nullptr)
                    w->left->color = BLACK;
                rightRotate(xParent);
                node = root;
                break;
            }
        }
    }

    if (node != nullptr)
        node->color = BLACK;
}

Node* RedBlackTree::findMin(Node* node){
    if (node == nullptr){
        return nullptr;
    }

    while (node->left != nullptr){
        node = node->left;
    }
    return node;
}

Node* RedBlackTree::searchNode(Node* node, string key){
    // recursively searchs the tree for the given key

    // checks if the tree is empty or node is found
    if(node == nullptr || node->key == key){
        return node;
    }

    if (key < node->key){
        return searchNode(node->left, key);
    }
    else{
        return searchNode(node->right, key);
    }
}

void RedBlackTree::inorderHelper(Node* node){
    // return if the tree is empty
    if(node == nullptr){
        return;
    }

    inorderHelper(node->left);
    // prints the word and definition out
    cout << node->key << ": " << node->value << endl;
    inorderHelper(node->right);
}

void RedBlackTree::inorderToFileHelper(Node* node, ofstream& out) {
    // check if the tree is empty
    if(node == nullptr){
        return;
    }

    inorderToFileHelper(node->left, out);
    out << node->key << ":" << node->value << endl;
    inorderToFileHelper(node->right, out);
}

// recursive helper to delete nodes
void RedBlackTree::deleteTree(Node* node) {
    if(node == nullptr){
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void RedBlackTree::deleteNode(Node* node){
    Node* pointer = node;
    Color OriginalColor = pointer->color;
    Node* placeholder;
    Node* placeholderParent = nullptr;

    if (node->left == nullptr) {
        placeholder = node->right;
        placeholderParent = node->parent;
        transplant(node, node->right);
    } else if (node->right == nullptr) {
        placeholder = node->left;
        placeholderParent = node->parent;
        transplant(node, node->left);
    } else {
        pointer = findMin(node->right);
        OriginalColor = pointer->color;
        placeholder = pointer->right;
        if (pointer->parent == node) {
            if (placeholder != nullptr) {
                placeholder->parent = pointer;
            }
            placeholderParent = pointer;
        } else {
            transplant(pointer, pointer->right);
            pointer->right = node->right;
            pointer->right->parent = pointer;
            placeholderParent = pointer->parent;
        }

        transplant(node, pointer);
        pointer->left = node->left;
        pointer->left->parent = pointer;
        pointer->color = node->color;
    }

    delete node;

    if (OriginalColor == BLACK) {
        fixDelete(placeholder, placeholderParent);
    }
}

// helper for the delte node function
void RedBlackTree::transplant(Node* u, Node* v) {
    if(u->parent == nullptr){
        root = v;
    } 
    else if(u == u->parent->left){
        u->parent->left = v;
    } 
    else{
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}
