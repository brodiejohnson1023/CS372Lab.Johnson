// MidtermQ1.h : Include file for standard system include files,
// or project specific include files.

#include <iostream>
using namespace std;

class LazyList {
private:
    struct Node {
        int data;
        bool deleted;
        Node* next;
        Node(int val) : data(val), deleted(false), next(nullptr) {}
    };

    Node* head;
    int activeCount;
    int deletedCount;

    void cleanup() {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->deleted) {
                if (prev) {
                    prev->next = curr->next;
                }
                else {
                    head = curr->next;
                }
                Node* toDelete = curr;
                curr = curr->next;
                delete toDelete;
                deletedCount--;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

public:
    LazyList() : head(nullptr), activeCount(0), deletedCount(0) {}

    ~LazyList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        activeCount++;
    }

    Node* find(int value) {
        Node* curr = head;
        while (curr) {
            if (!curr->deleted && curr->data == value) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void remove(int value) {
        Node* node = find(value);
        if (node && !node->deleted) {
            node->deleted = true;
            activeCount--;
            deletedCount++;
            if (deletedCount == activeCount) {
                cleanup();
            }
        }
    }

    void display() {
        Node* curr = head;
        while (curr) {
            if (!curr->deleted) {
                cout << curr->data << " ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
};
