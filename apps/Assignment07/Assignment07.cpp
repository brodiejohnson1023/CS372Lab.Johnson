// Assignment07.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <random>
#include <chrono>
#include <utility>
#include <vector>
#include "Tree.h"
#include "AVLTree.h"

using namespace std;


Tree<int>* generateRandomBST(int n) {
    Tree<int>* bst = new Tree<int>();

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, n * 10);

    for (int i = 0; i < n; ++i) {
        bst->insert(dist(gen));
    }

    return bst;
}


void inorderHelper(TreeNode<int>* node, AVLTree<int>& avl) {
    if (node == nullptr)
        return;

    inorderHelper(node->left, avl);
    avl.insert(node->data);
    inorderHelper(node->right, avl);
}


void inorderToAVL(Tree<int>* bst, AVLTree<int>& avl) {
    if (bst == nullptr)
        return;

    inorderHelper(bst->getRoot(), avl);
}


pair<double, double> compareSearchTimes(Tree<int>& bst, AVLTree<int>& avl, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, n * 10);

    const int trials = 100;
    double totalBST = 0.0;
    double totalAVL = 0.0;

    for (int i = 0; i < trials; ++i) {
        int value = dist(gen);

       
        auto startBST = chrono::high_resolution_clock::now();
        bst.find(value);
        auto endBST = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> elapsedBST = endBST - startBST;
        totalBST += elapsedBST.count();

        
        auto startAVL = chrono::high_resolution_clock::now();
        avl.find(value);
        auto endAVL = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> elapsedAVL = endAVL - startAVL;
        totalAVL += elapsedAVL.count();
    }

    double avgBST = totalBST / trials;
    double avgAVL = totalAVL / trials;

    return make_pair(avgBST, avgAVL);
}


int main() {
    vector<int> sizes = { 100, 500, 1000, 2500, 5000, 10000 };

    cout << "Average search times (in microseconds):\n";
    cout << "----------------------------------------\n";
    cout << "Elements\tBST Avg\t\tAVL Avg\n";
    cout << "----------------------------------------\n";

    for (int n : sizes) {
        Tree<int>* bst = generateRandomBST(n);
        AVLTree<int> avl;
        inorderToAVL(bst, avl);

        pair<double, double> results = compareSearchTimes(*bst, avl, n);

        cout << n << "\t\t"
            << results.first << "\t\t"
            << results.second << endl;

        delete bst;
    }

    return 0;
}
