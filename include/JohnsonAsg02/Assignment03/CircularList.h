#pragma once
#include "List.h"

template <typename T>
class CircularList : public List<T> {
public:
    void traverseCircular(std::function<void(const T&)> visit, size_t startIndex = 0) const {
        if (this->empty()) return;
        typename List<T>::Node* start = this->head;
        for (size_t i = 0; i < startIndex && start; i++) {
            start = start->next;
        }
        if (!start) return;
        typename List<T>::Node* curr = start;
        do {
            visit(curr->data);
            curr = curr->next ? curr->next : this->head;
        } while (curr != start);
    }
};
