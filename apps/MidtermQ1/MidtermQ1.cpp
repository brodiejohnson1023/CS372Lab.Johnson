// MidtermQ1.cpp : Defines the entry point for the application.
//

#include "MidtermQ1.h"

using namespace std;

int main() {
    LazyList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.remove(20);
    list.display();
    list.remove(10);
    list.display();
    list.remove(30);
    list.display();
}