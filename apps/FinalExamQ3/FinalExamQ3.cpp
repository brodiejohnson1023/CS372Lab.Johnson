#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> floydWarshall(const vector<vector<int>>& W) {
    int n = W.size();
    vector<vector<int>> D = W;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

               
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    return D;
}

int main() {
    const int INF = INT_MAX;

    vector<vector<int>> W = {
        {0,   3, INF,  7},
        {8,   0,   2, INF},
        {5, INF,   0,   1},
        {2, INF, INF,  0}
    };

    vector<vector<int>> D = floydWarshall(W);

    cout << "Shortest distance matrix:\n";
    for (auto& row : D) {
        for (auto val : row) {
            if (val == INF) cout << "INF ";
            else cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
