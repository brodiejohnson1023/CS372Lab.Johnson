// MidtermQ2.h : Include file for standard system include files,
// or project specific include files.

#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* data;
    size_t capacity;
    size_t length;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Vector() : data(nullptr), capacity(0), length(0) {}

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (length == capacity) {
            size_t newCap = (capacity == 0) ? 1 : capacity * 2;
            resize(newCap);
        }
        data[length++] = value;
    }

    size_t size() const {
        return length;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    class Iterator {
    private:
        Vector<T>* vec;
        size_t index;
    public:
        Iterator(Vector<T>* v, size_t i) : vec(v), index(i) {}

        T& operator*() {
            return (*vec)[index];
        }

        Iterator& operator++() {
            index++;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return vec == other.vec && index == other.index;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin() {
        return Iterator(this, 0);
    }

    Iterator end() {
        return Iterator(this, length);
    }
};
