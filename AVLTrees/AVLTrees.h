#ifndef AVLTREES_H
#define AVLTREES_H

#include <iostream>
#include <algorithm>

template <typename T>
class AVLNode {
public:
    T key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    int height(AVLNode<T>* node);
    int balanceFactor(AVLNode<T>* node);
    AVLNode<T>* rightRotate(AVLNode<T>* y);
    AVLNode<T>* leftRotate(AVLNode<T>* x);
    AVLNode<T>* insert(AVLNode<T>* node, T key);
    AVLNode<T>* deleteNode(AVLNode<T>* root, T key);
    AVLNode<T>* minValueNode(AVLNode<T>* node);
    void inorder(AVLNode<T>* root);
    bool search(AVLNode<T>* root, T key);

public:
    AVLTree();
    void insert(T key);
    void remove(T key);
    bool search(T key);
    void printInorder();
};

#endif
