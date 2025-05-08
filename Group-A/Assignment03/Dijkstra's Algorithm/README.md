# Dijkstra's Algorithm - Shortest Path Finder

This C++ program demonstrates **Dijkstra's Algorithm** using a custom `Graph` class to find the shortest path from a source city to all other cities in a weighted graph.

---

## How It Works

### 1. **Graph Construction**

* A total of **6 cities** are represented: `X`, `Y`, `Z`, `W`, `V`, `U`.
* Each city is assigned a unique index (0 to 5).
* A list of weighted edges defines the connectivity between the cities.
* An **adjacency list** is used to store the graph internally.

### 2. **Dijkstra's Algorithm**

* Finds the **shortest path** from a single source (by default, city `X`) to all other nodes.
* A **min-heap (priority queue)** ensures the closest unvisited city is processed first.
* Arrays:

  * `dist[]` holds the shortest distance to each city.
  * `visited[]` keeps track of processed cities.

---

## 🧪 Sample Graph

```
City Connections with Weights:
X - Y - 4
X - Z - 3
Y - Z - 1
Y - W - 2
Z - W - 4
Z - V - 5
W - V - 7
V - U - 3
W - U - 8
```

---

## 📤 Output

After running Dijkstra from city `X`, the output displays:

```
Shortest distances from source (X):
X -> X = 0
X -> Y = 4
X -> Z = 3
X -> W = 6
X -> V = 8
X -> U = 11
```
---

## 🧠 Concepts Covered

* Graph Representation using Adjacency List
* Priority Queue (Min-Heap)
* Dijkstra’s Algorithm for Shortest Paths
* STL: `map`, `vector`, `priority_queue`, `tuple`

---

Happy Coding! 💻
