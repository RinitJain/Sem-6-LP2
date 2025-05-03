# Prim's Algorithm for Minimum Spanning Tree (MST)

This project implements **Prim's Algorithm** in C++ using an **adjacency list** to construct a **Minimum Spanning Tree** (MST) from a given set of weighted undirected edges between cities.

## 👨‍💻 How it works

1. **Graph Setup**

   * The graph is defined using city names which are mapped to indices using `map<string, int>`.
   * The adjacency list `adj` stores neighboring nodes and their edge weights.
   * Edges are provided in the form of a vector of tuples: `{from, to, weight}`.

2. **Prim's MST Algorithm**

   * Uses a **min-heap priority queue** to always expand the minimum weighted edge.
   * Maintains:

     * `key[]`: Minimum weight to connect a vertex to the MST.
     * `parent[]`: Parent of each vertex in the MST.
     * `inMST[]`: Tracks which vertices are already included in MST.

3. **MST Construction**

   * Starts from an arbitrary vertex (index `0`, mapped to city `X` here).
   * Greedily picks the lowest weight edge that expands the MST.
   * Prints the final MST and its **total weight**.

## 📦 Input (Hardcoded)

```cpp
vector<tuple<string, string, int>> edges = {
    {"X", "Y", 4},
    {"X", "Z", 3},
    {"Y", "Z", 1},
    {"Y", "W", 2},
    {"Z", "W", 4},
    {"Z", "V", 5},
    {"W", "V", 7},
    {"V", "U", 3},
    {"W", "U", 8}
};
```

## ✅ Output

Example output may look like:

```
Minimum Spanning Tree:
From - To - Weight
Y  -  Z  -  1
Y  -  W  -  2
X  -  Z  -  3
V  -  U  -  3
Z  -  V  -  5
Total Weight: 14
```

---

Feel free to replace city names or edge weights to test different graphs.
