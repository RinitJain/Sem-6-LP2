#include <iostream>
#include <vector>
#include <queue>

class Tree {
private:
    int nodes; // Number of nodes
    std::vector<std::vector<int>> adjList; // Adjacency list

public:
    Tree(int n) : nodes(n) {
        adjList.resize(n);
    }

    void addEdge(int parent, int child) {
        // Since it's an undirected tree (or rooted tree), connect both
        adjList[parent].push_back(child);
        adjList[child].push_back(parent);
    }

    void DFS(int current, int parent) {
        std::cout << current << " ";

        for (int child : adjList[current]) {
            if (child != parent) {
                DFS(child, current);
            }
        }
    }

    void BFS(int root) {
        std::vector<bool> visited(nodes, false);
        std::queue<int> q;

        visited[root] = true;
        q.push(root);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            std::cout << current << " ";

            for (int child : adjList[current]) {
                if (!visited[child]) {
                    visited[child] = true;
                    q.push(child);
                }
            }
        }
    }
};

int main() {
    Tree t(5); // Tree with 5 nodes

    t.addEdge(0, 1);
    t.addEdge(0, 2);
    t.addEdge(1, 3);
    t.addEdge(1, 4);

    std::cout << "DFS Traversal of Tree:\n";
    t.DFS(0, -1);  // Root is 0, parent is -1

    std::cout << "\nBFS Traversal of Tree:\n";
    t.BFS(0);      // Root is 0

    return 0;
}
