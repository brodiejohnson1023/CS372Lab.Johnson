// array.cpp : Defines the entry point for the application.
//

#include <iostream>
using namespace std;

template <typename T, size_t N>
class Array {
    T data[N];
public:
    Array() {}
    size_t size() const { return N; }
    T& operator[](size_t i) { return data[i]; }
    const T& operator[](size_t i) const { return data[i]; }
};

int main() {
    Array<int, 5> arr;
    for (int i = 0; i < 5; i++) arr[i] = i * 10;
    cout << "Array contents: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
