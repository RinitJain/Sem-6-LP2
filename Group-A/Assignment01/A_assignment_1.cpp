#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int vertices; // Number of vertices
    std::vector<std::vector<int>> adjList; // Adjacency list representation

public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    void DFS(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    void BFS(int start) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            std::cout << vertex << " ";

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    std::cout << "DFS starting from vertex 0:\n";
    std::vector<bool> visited(5, false);
    g.DFS(0, visited);

    std::cout << "\nBFS starting from vertex 0:\n";
    g.BFS(0);

    return 0;
}
