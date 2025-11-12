#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph social(20, false);

   
    social.addEdge(0, 1);
    social.addEdge(1, 2);
    social.addEdge(2, 3);
    social.addEdge(3, 4);
    social.addEdge(4, 19);
    social.addEdge(2, 5);
    social.addEdge(5, 10);
    social.addEdge(10, 15);
    social.addEdge(15, 19);

    vector<int> path;
    if (social.findConnection(0, 19, path)) {
        cout << "Connected to Kevin Bacon\nPath: ";
        for (int p : path) cout << p << " ";
        cout << "\nKevin Bacon Number: " << path.size() - 1 << endl;
    }
    else {
        cout << "No connection to Kevin Bacon\n";
    }

    vector<int> testCycle = { 2, 5, 10, 15, 2 };
    cout << "\nCycle Test: ";
    if (social.isSimpleCycle(testCycle))
        cout << "Is a valid simple cycle\n";
    else
        cout << "Not a simple cycle\n";

    return 0;
}
