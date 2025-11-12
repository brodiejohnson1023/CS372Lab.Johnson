#include "Graph.h"

Graph::Graph(int vertices, bool matrix) {
    vertexCount = vertices;
    useMatrix = matrix;

    if (useMatrix)
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    else
        adjList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    if (useMatrix) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    else {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

bool Graph::isNeighbor(int u, int v) {
    if (useMatrix)
        return adjMatrix[u][v] == 1;

    for (int n : adjList[u])
        if (n == v) return true;
    return false;
}

bool Graph::isSimpleCycle(const vector<int>& path) {
    if (path.size() < 3) return false;
    if (path[0] != path[path.size() - 1]) return false;

    vector<bool> visited(vertexCount, false);

    for (int i = 0; i < path.size() - 1; i++) {
        int curr = path[i];
        int next = path[i + 1];

        if (!isNeighbor(curr, next))
            return false;

        if (visited[curr])
            return false;

        visited[curr] = true;
    }
    return true;
}

bool Graph::findConnection(int start, int target, vector<int>& pathOut) {
    vector<bool> visited(vertexCount, false);
    vector<int> parent(vertexCount, -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == target) {
            int node = target;
            while (node != -1) {
                pathOut.insert(pathOut.begin(), node);
                node = parent[node];
            }
            return true;
        }

        for (int i = 0; i < vertexCount; i++) {
            if (isNeighbor(curr, i) && !visited[i]) {
                visited[i] = true;
                parent[i] = curr;
                q.push(i);
            }
        }
    }
    return false;
}
