// Assignment04.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Queue.h"
using namespace std;

int josephus(int n, int m) {
    Queue<int> q;
    for (int i = 1; i <= n; i++) q.enqueue(i);

    while (q.size() > 1) {
        for (int i = 0; i < m; i++) {
            int x = q.front();
            q.dequeue();
            q.enqueue(x);
        }
        q.dequeue();
    }
    return q.front();
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << josephus(n, m) << endl;
    return 0;
}
