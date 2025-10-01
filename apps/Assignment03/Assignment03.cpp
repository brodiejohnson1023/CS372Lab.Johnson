// Assignment03.cpp : Defines the entry point for the application.
//

#include "List.h"
#include "Bag.h"
#include "CircularList.h"
#include <iostream>

int main() {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    std::cout << "List: ";
    l.traverse([](int x) { std::cout << x << " "; });
    std::cout << "\n";

    Bag<int> b;
    b.add(5);
    b.add(10);
    b.add(5);

    std::cout << "Bag contents: ";
    b.display();

    b.remove(5);
    std::cout << "After removing one 5: ";
    b.display();

    CircularList<int> cl;
    cl.push_back(10);
    cl.push_back(20);
    cl.push_back(30);

    std::cout << "Circular traversal (start at index 1): ";
    cl.traverseCircular([](int x) { std::cout << x << " "; }, 1);
    std::cout << "\n";

    return 0;
}
