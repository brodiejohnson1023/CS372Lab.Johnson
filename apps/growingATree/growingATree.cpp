#include <iostream>
#include <queue>
#include <functional>
#include "List.h"
#include "Tree.h"

int main() {
    std::cout << "=== SMART POINTER LIST TEST ===\n";
    List<int> myList;
    myList.push_front(3);
    myList.push_front(2);
    myList.push_front(1);
    myList.push_back(4);

    std::cout << "List contents: ";
    myList.print();

    std::cout << "\n=== TREE CLASS TEST ===\n";

    Tree<std::string> tree("Root");
    auto childA = tree.addChild(tree.root, "Child A");
    auto childB = tree.addChild(tree.root, "Child B");
    auto grandChildA1 = tree.addChild(childA, "Grandchild A1");
    auto grandChildA2 = tree.addChild(childA, "Grandchild A2");
    auto grandChildB1 = tree.addChild(childB, "Grandchild B1");

    std::cout << "Original tree structure:\n";
    tree.print(tree.root);

    std::cout << "\n=== LEVEL TRAVERSAL (inline BFS) ===\n";
    if (tree.root) {
        std::queue<std::shared_ptr<typename Tree<std::string>::Node>> q;
        q.push(tree.root);
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            std::cout << current->data << " ";
            for (auto& child : current->children)
                q.push(child);
        }
    }

    std::cout << "\n\n=== PRUNE TEST (Remove Leaf Nodes) ===\n";

    using Node = typename Tree<std::string>::Node;
    using NodePtr = std::shared_ptr<Node>;
    std::function<NodePtr(const NodePtr&)> pruneHelper;

    pruneHelper = [&](const NodePtr& node) -> NodePtr {
        if (!node || node->children.empty())
            return NodePtr(nullptr);
        auto newNode = std::make_shared<Node>(node->data);
        for (const auto& child : node->children) {
            auto prunedChild = pruneHelper(child);
            if (prunedChild) {
                prunedChild->parent = newNode;
                newNode->children.push_back(prunedChild);
            }
        }
        return newNode;
        };

    Tree<std::string> prunedTree;
    prunedTree.root = pruneHelper(tree.root);

    std::cout << "Pruned tree structure:\n";
    prunedTree.print(prunedTree.root);

    std::cout << "\nProgram complete.\n";
    return 0;
}
