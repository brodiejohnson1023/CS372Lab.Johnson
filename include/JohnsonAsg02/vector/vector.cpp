// vector.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <chrono>
using namespace std;

/**
 * @brief A simple dynamic array (Vector) implementation.
 *
 * Features:
 *  - Automatically doubles its capacity when full.
 *  - Supports adding elements with push_back().
 *  - Tracks size and capacity internally.
 */
template <typename T>
class Vector {
    T* data;        // Pointer to the dynamic array
    size_t size_;   // Current number of elements
    size_t cap_;    // Current capacity of the array

    /**
     * @brief Increase the capacity of the array when it's full.
     *
     * This doubles the current capacity or starts at 1
     * if the vector is currently empty. Existing elements
     * are copied to the new storage.
     */
    void grow() {
        cap_ = cap_ == 0 ? 1 : cap_ * 2;
        T* newData = new T[cap_];
        for (size_t i = 0; i < size_; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    /// Constructor: initializes an empty vector.
    Vector() : data(nullptr), size_(0), cap_(0) {}

    /// Destructor: releases allocated memory.
    ~Vector() { delete[] data; }

    /**
     * @brief Add a new element to the end of the vector.
     * @param val The value to add.
     */
    void push_back(const T& val) {
        if (size_ == cap_) grow();
        data[size_++] = val;
    }

    /// Get the current number of elements.
    size_t size() const { return size_; }

    /// Get the current capacity (allocated space).
    size_t capacity() const { return cap_; }
};

int main() {
    cout << "Timing Vector growth with powers-of-two sizes:\n";

    // Test for sizes: 2, 4, 8, ..., up to ~1 million elements
    for (size_t n = 2; n <= (1 << 20); n <<= 1) {
        Vector<int> v;

        // Start timer
        auto start = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < n; i++) v.push_back((int)i);
        auto end = chrono::high_resolution_clock::now();

        // Calculate time in milliseconds
        auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "Inserted " << n << " elements -> " << ms << " ms\n";
    }
    return 0;
}
