// Fringe.h
#ifndef FRINGE_H
#define FRINGE_H

#include <vector>
#include <queue>
#include "Tree.h"

template <typename T>
std::vector<T> getFringe(const Tree<T>& tree) {
    std::vector<T> fringe;
    TreeNode<T>* root = tree.getRoot();

    if (!root) return fringe;

    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<T>* curr = q.front();
        q.pop();

        if (tree.isLeaf(curr)) {
            fringe.push_back(curr->data);
        }

        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    return fringe;
}

template <typename T>
bool hasSameFringe(const Tree<T>& a, const Tree<T>& b) {
    return getFringe(a) == getFringe(b);
}

#endif
