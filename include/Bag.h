#pragma once
#include "List.h"

template <typename T>
class Bag {
private:
    List<T> items;

public:
    Bag() = default;

    void add(const T& item) {
        items.push_back(item);
    }

    bool remove(const T& item) {
        return items.remove(item);
    }

    bool contains(const T& item) const {
        return items.find(item);
    }

    void display() const {
        items.traverse([](const T& val) {
            std::cout << val << " ";
            });
        std::cout << "\n";
    }

    bool empty() const { return items.empty(); }
    size_t size() const { return items.size(); }
};
