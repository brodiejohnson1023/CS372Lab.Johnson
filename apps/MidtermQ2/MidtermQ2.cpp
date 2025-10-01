// MidtermQ2.cpp : Defines the entry point for the application.
//

#include "iteratorVector.h"

using namespace std;

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

