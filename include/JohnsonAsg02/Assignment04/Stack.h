#ifndef STACK_H
#define STACK_H

#include "List.h"

template <typename T>
class Stack {
private:
    List<T> list;
public:
    void push(const T& value) { list.push_back(value); }
    void pop() { list.pop_back(); }
    T& top() { return list.back(); }
    bool empty() const { return list.empty(); }
    int size() const { return list.size(); }
};
#endif
