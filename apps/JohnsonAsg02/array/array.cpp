// array.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * @brief A simple fixed-size array class with bounds checking.
 *
 * @tparam T Type of elements stored in the array.
 * @tparam N Fixed size of the array.
 *
 * This class mimics std::array but includes bounds checking
 * to prevent out-of-range errors.
 */
template <typename T, size_t N>
class Array {
    T data[N]; // Internal storage for array elements

public:
    /// Constructor: initializes the array (elements are default-constructed).
    Array() {}

    /// Get the number of elements in the array.
    size_t size() const { return N; }

    /**
     * @brief Access an element by index (with bounds checking).
     * @param i Index of the element.
     * @return Reference to the element.
     * @throws out_of_range if index is invalid.
     */
    T& operator[](size_t i) {
        if (i >= N) throw out_of_range("Index out of bounds");
        return data[i];
    }

    /// Const version of operator[].
    const T& operator[](size_t i) const {
        if (i >= N) throw out_of_range("Index out of bounds");
        return data[i];
    }
};

int main() {
    Array<int, 5> arr;

    // Fill array with multiples of 10
    for (int i = 0; i < (int)arr.size(); i++) {
        arr[i] = i * 10;
    }

    cout << "Array contents: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}
