#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int vertexCount;
    vector<tuple<int, int, int>> edges; // {weight, u, v}

    Graph() {
        // Set the number of vertices
        vertexCount = 6;

        // Add edges as {weight, from, to}
        edges = {
            {4, 0, 1}, {3, 0, 2}, {1, 1, 2}, {2, 1, 3},
            {4, 2, 3}, {5, 2, 4}, {7, 3, 4}, {3, 4, 5}, {8, 3, 5}
        };
    }

    // Disjoint Set (Union-Find) helpers
    int find(vector<int>& parent, int u) {
        if (parent[u] != u)
            parent[u] = find(parent, parent[u]); // Path compression
        return parent[u];
    }

    void unite(vector<int>& parent, vector<int>& rank, int u, int v) {
        int rootU = find(parent, u);
        int rootV = find(parent, v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    void KruskalMST() {
        // Sort edges by weight
        sort(edges.begin(), edges.end());

        vector<int> parent(vertexCount);
        vector<int> rank(vertexCount, 0);
        for (int i = 0; i < vertexCount; i++) parent[i] = i;

        vector<tuple<int, int, int>> mst; // to store result edges
        int totalWeight = 0;

        for (auto &[weight, u, v] : edges) {
            if (find(parent, u) != find(parent, v)) {
                mst.push_back({u, v, weight});
                unite(parent, rank, u, v);
                totalWeight += weight;
            }
        }

        cout << "Minimum Spanning Tree (Kruskal's):\nFrom - To - Weight\n";
        for (auto &[u, v, w] : mst)
            cout << u << " - " << v << " - " << w << endl;
        cout << "Total Weight: " << totalWeight << endl;
    }
};

int main() {
    Graph g;
    g.KruskalMST();
    return 0;
}
