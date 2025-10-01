
#pragma once
#include <iostream>
#include <functional>

template <typename T>
class List {
protected:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* head;
    Node* tail;
    size_t size_;

    void copyFrom(const List& other) {
        Node* curr = other.head;
        while (curr) {
            push_back(curr->data);
            curr = curr->next;
        }
    }

    void clear() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = tail = nullptr;
        size_ = 0;
    }

public:
    List() : head(nullptr), tail(nullptr), size_(0) {}
    ~List() { clear(); }

    List(const List& other) : head(nullptr), tail(nullptr), size_(0) {
        copyFrom(other);
    }

    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    List(List&& other) noexcept : head(other.head), tail(other.tail), size_(other.size_) {
        other.head = other.tail = nullptr;
        other.size_ = 0;
    }

    List& operator=(List&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            size_ = other.size_;
            other.head = other.tail = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value, head);
        head = newNode;
        if (!tail) tail = head;
        size_++;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
        size_++;
    }

    bool remove(const T& value) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr) {
            if (curr->data == value) {
                if (prev) prev->next = curr->next;
                else head = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
                size_--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    bool find(const T& value) const {
        Node* curr = head;
        while (curr) {
            if (curr->data == value) return true;
            curr = curr->next;
        }
        return false;
    }

    void traverse(std::function<void(const T&)> visit) const {
        Node* curr = head;
        while (curr) {
            visit(curr->data);
            curr = curr->next;
        }
    }

    T& front() {
        return head->data;
    }

    const T& front() const {
        return head->data;
    }

    T& back() {
        return tail->data;
    }

    const T& back() const {
        return tail->data;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        size_--;
    }

    void pop_back() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* curr = head;
            while (curr->next != tail) {
                curr = curr->next;
            }
            delete tail;
            tail = curr;
            tail->next = nullptr;
        }
        size_--;
    }


    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
};
