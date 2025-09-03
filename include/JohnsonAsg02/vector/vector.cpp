// vector.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <chrono>
using namespace std;

template <typename T>
class Vector {
    T* data;
    size_t size, cap;

    void grow() {
        cap = cap == 0 ? 1 : cap * 2;
        T* newData = new T[cap];
        for (size_t i = 0; i < size; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    Vector() : data(nullptr), size(0), cap(0) {}
    ~Vector() { delete[] data; }

    void push_back(const T& val) {
        if (size == cap) grow();
        data[size++] = val;
    }
};

int main() {
    cout << "Timing Vector growth (powers of 2):\n";
    for (size_t n = 2; n <= (1 << 20); n <<= 1) {
        Vector<int> v;
        auto start = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < n; i++) v.push_back((int)i);
        auto end = chrono::high_resolution_clock::now();
        auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "N=" << n << " -> " << ms << " ms\n";
    }
    return 0;
}
