#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;


vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();

    vector<int> dist(n, numeric_limits<int>::max());

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[source] = 0;
    pq.push({ 0, source });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            int alt = dist[u] + w;

            if (alt < dist[v]) {
                dist[v] = alt;
                pq.push({ alt, v });
            }
        }
    }

    return dist;
}

int main() {
   
    vector<vector<pair<int, int>>> graph = {
        { {1, 4}, {2, 1} },        
        { {0, 4}, {2, 2}, {3, 5} },
        { {0, 1}, {1, 2}, {3, 8} },
        { {1, 5}, {2, 8} }       
    };

    int source = 0;
    vector<int> dist = dijkstra(graph, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < dist.size(); i++) {
        cout << "Node " << i << " = ";
        if (dist[i] == numeric_limits<int>::max())
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}

