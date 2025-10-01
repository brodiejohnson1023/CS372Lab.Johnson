#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <typename T>
class Queue {
private:
    List<T> list;
public:
    void enqueue(const T& value) { list.push_back(value); }
    void dequeue() { list.pop_front(); }
    T& front() { return list.front(); }
    bool empty() const { return list.empty(); }
    int size() const { return list.size(); }
};
#endif
