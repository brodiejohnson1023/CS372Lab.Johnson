// AVLTree.h : Include file for standard system include files,
// or project specific include files.

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <algorithm>
using namespace std;


template <typename T>
struct AVLNode {
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};


template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    
    int getHeight(AVLNode<T>* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

  
    int getBalance(AVLNode<T>* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

  
    AVLNode<T>* rotateRight(AVLNode<T>* y) {
        AVLNode<T>* x = y->left;
        AVLNode<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    
    AVLNode<T>* rotateLeft(AVLNode<T>* x) {
        AVLNode<T>* y = x->right;
        AVLNode<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    
    AVLNode<T>* insertRec(AVLNode<T>* node, T value) {
        if (node == nullptr)
            return new AVLNode<T>(value);

        if (value < node->data)
            node->left = insertRec(node->left, value);
        else if (value > node->data)
            node->right = insertRec(node->right, value);
        else
            return node;


        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    
        int balance = getBalance(node);


        if (balance > 1 && value < node->left->data)
            return rotateRight(node);


        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

    
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

 
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }


    bool findRec(AVLNode<T>* node, T value) const {
        if (node == nullptr)
            return false;
        if (value == node->data)
            return true;
        if (value < node->data)
            return findRec(node->left, value);
        else
            return findRec(node->right, value);
    }

 
    void clear(AVLNode<T>* node) {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
  
    AVLTree() {
        root = nullptr;
    }

    
    ~AVLTree() {
        clear(root);
    }

   
    void insert(T value) {
        root = insertRec(root, value);
    }


    bool find(T value) const {
        return findRec(root, value);
    }


    AVLNode<T>* getRoot() const {
        return root;
    }

    
    void inorderPrint(AVLNode<T>* node) const {
        if (node == nullptr)
            return;
        inorderPrint(node->left);
        cout << node->data << " ";
        inorderPrint(node->right);
    }

    void display() const {
        inorderPrint(root);
        cout << endl;
    }
};

#endif
