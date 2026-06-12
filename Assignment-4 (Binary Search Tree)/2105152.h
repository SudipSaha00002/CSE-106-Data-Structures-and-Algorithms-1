#ifndef BST_H
#define BST_H

#include<iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
class BSTnode{
    public:
    T key;
    BSTnode* left;
    BSTnode* right;
    BSTnode* root;
    BSTnode();
    BSTnode<T>* tree(T& key);
    BSTnode<T>* insert(BSTnode<T>* root,T& key);
    BSTnode<T>* find(BSTnode<T>* node);
    BSTnode<T>* deleteN(BSTnode<T>* root,T& key);
    bool search(BSTnode<T>* root,T& key);
    void display(BSTnode<T>* root, ofstream& outfile);
    void inorder(BSTnode<T>* root, ofstream& outfile);
    void preorder(BSTnode<T>* root, ofstream& outfile);
    void postorder(BSTnode<T>* root, ofstream& outfile);

};
#endif