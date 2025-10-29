// Tree.h
#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


template <typename T>
class Tree {
private:
    TreeNode<T>* root;


    TreeNode<T>* insertRec(TreeNode<T>* node, T value) {
        if (node == nullptr)
            return new TreeNode<T>(value);

        if (value < node->data)
            node->left = insertRec(node->left, value);
        else if (value > node->data)
            node->right = insertRec(node->right, value);


        return node;
    }

   
    bool findRec(TreeNode<T>* node, T value) const {
        if (node == nullptr)
            return false;
        if (value == node->data)
            return true;
        if (value < node->data)
            return findRec(node->left, value);
        else
            return findRec(node->right, value);
    }

    
    void clear(TreeNode<T>* node) {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
   
    Tree() {
        root = nullptr;
    }

    ~Tree() {
        clear(root);
    }

    void insert(T value) {
        root = insertRec(root, value);
    }

  
    bool find(T value) const {
        return findRec(root, value);
    }

    
    TreeNode<T>* getRoot() const {
        return root;
    }

    
    void inorderPrint(TreeNode<T>* node) const {
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
