// Tree.h
#pragma once
#include <memory>
#include <vector>
#include <iostream>

template <typename T>
class Tree {
public:
    struct Node {
        T data;
        std::weak_ptr<Node> parent;
        std::vector<std::shared_ptr<Node>> children;

        explicit Node(const T& value) : data(value) {}
    };

    std::shared_ptr<Node> root;

    Tree() = default;
    explicit Tree(const T& rootValue) {
        root = std::make_shared<Node>(rootValue);
    }

    std::shared_ptr<Node> addChild(std::shared_ptr<Node> parent, const T& value) {
        auto child = std::make_shared<Node>(value);
        child->parent = parent;
        parent->children.push_back(child);
        return child;
    }

    void print(const std::shared_ptr<Node>& node, int depth = 0) const {
        if (!node) return;
        std::cout << std::string(depth * 2, ' ') << node->data << "\n";
        for (const auto& child : node->children)
            print(child, depth + 1);
    }
};
