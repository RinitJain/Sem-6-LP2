# Minimum Spanning Tree using Kruskal's Algorithm

## Overview

This project demonstrates Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a graph. It uses a disjoint-set (union-find) data structure to efficiently detect cycles and build the MST.

## Code Structure

### 1. **Edge Structure**

```cpp
struct Edge {
  int src, dest, weight;
};
```

Defines an edge with source vertex, destination vertex, and edge weight.

### 2. **compareEdges Function**

```cpp
bool compareEdges(const Edge& e1, const Edge& e2)
```

Sorts the edges based on their weights in ascending order.

### 3. **Disjoint-Set Functions**

* **findParent**: Implements path compression.
* **unionSets**: Uses union by rank for efficiency.

```cpp
int findParent(vector<int>& parent, int u)
void unionSets(vector<int>& parent, vector<int>& rank, int x, int y)
```

### 4. **KruskalsMST Function**

```cpp
vector<Edge> KruskalsMST(vector<Edge>& edges, int V)
```

* Sorts all edges.
* Iterates through them and uses disjoint sets to ensure no cycles are formed.
* Builds the MST incrementally.

### 5. **main Function**

```cpp
int main()
```

* Defines a sample graph.
* Calls `KruskalsMST`.
* Prints edges in the MST.

## Sample Output

```
Edges in the constructed MST: 
1 -- 2 == 1
1 -- 3 == 2
0 -- 2 == 3
0 -- 1 == 4
4 -- 5 == 3
5 -- 6 == 1
```

## How Kruskal's Algorithm Works

* Greedy approach: always pick the smallest available edge that doesn't form a cycle.
* Sort all edges.
* Use disjoint set to keep track of connected components.
* Stop when MST has `V - 1` edges.

## Time Complexity

* Sorting edges: `O(E log E)`
* Union-find operations: nearly `O(1)` per operation with path compression and union by rank.

## Usage

Compile with any standard C++ compiler:

```bash
g++ -o mst kruskal_mst.cpp
./mst
```

## Notes

* Make sure vertex indices are consistent (0-based).
* Can be easily extended to handle real-world graph input or city names with a mapping.
