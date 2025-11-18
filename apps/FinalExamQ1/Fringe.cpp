// main.cpp

#include <iostream>
#include <vector>
#include <queue>


template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
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
        if (node == nullptr) return false;
        if (value == node->data) return true;
        if (value < node->data) return findRec(node->left, value);
        return findRec(node->right, value);
    }

    void clear(TreeNode<T>* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    Tree() : root(nullptr) {}
    ~Tree() { clear(root); }

    void insert(T value) { root = insertRec(root, value); }
    bool find(T value) const { return findRec(root, value); }
    TreeNode<T>* getRoot() const { return root; }

    
    bool isLeaf(TreeNode<T>* node) const {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }

    
    void inorderPrint(TreeNode<T>* node) const {
        if (!node) return;
        inorderPrint(node->left);
        std::cout << node->data << " ";
        inorderPrint(node->right);
    }
    void display() const { inorderPrint(root); std::cout << '\n'; }
};


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
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return fringe;
}

template <typename T>
bool hasSameFringe(const Tree<T>& a, const Tree<T>& b) {
    return getFringe(a) == getFringe(b);
}


int main() {
    Tree<int> t1;
    Tree<int> t2;

    
    t1.insert(10);
    t1.insert(5);
    t1.insert(1);
    t1.insert(7);
    t1.insert(40);

   
    t2.insert(20);
    t2.insert(15);
    t2.insert(25);
    t2.insert(5);
    t2.insert(1);
    t2.insert(7);
    t2.insert(40);

    auto f1 = getFringe(t1);
    auto f2 = getFringe(t2);

    std::cout << "Fringe of t1: ";
    for (const auto& v : f1) std::cout << v << ' ';
    std::cout << '\n';

    std::cout << "Fringe of t2: ";
    for (const auto& v : f2) std::cout << v << ' ';
    std::cout << '\n';

    std::cout << (hasSameFringe(t1, t2) ? "Same fringe\n" : "Different fringe\n");

    return 0;
}
