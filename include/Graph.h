#pragma once
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    bool useMatrix;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;
    int vertexCount;

public:
    Graph(int vertices, bool matrix = false);

    void addEdge(int u, int v);
    bool isNeighbor(int u, int v);

    bool isSimpleCycle(const vector<int>& path);
    bool findConnection(int start, int target, vector<int>& pathOut);
};
