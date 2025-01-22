# Depth First Search (DFS) and Breadth First Search (BFS) Algorithms Implementation

This repository contains the implementation of two popular graph traversal algorithms: **Depth First Search (DFS)** and **Breadth First Search (BFS)**, using an undirected graph represented by an adjacency list. Both algorithms are implemented using C++ and are tested with a sample graph.

## Table of Contents
- [Overview](#overview)
- [Graph Representation](#graph-representation)
- [DFS Algorithm](#dfs-algorithm)
- [BFS Algorithm](#bfs-algorithm)
- [Example](#example)
- [Explanation of Code](#explanation-of-code)
- [Key Concepts](#key-concepts)
  - [Depth First Search (DFS)](#depth-first-search-dfs)
  - [Breadth First Search (BFS)](#breadth-first-search-bfs)
- [Conclusion](#conclusion)

## Overview

This program demonstrates both **Depth First Search (DFS)** and **Breadth First Search (BFS)** for graph traversal. We use an **undirected graph** in the form of an adjacency list to represent the graph structure. The program implements both algorithms and demonstrates their use in traversing the graph starting from a specified vertex.

## Graph Representation

An **undirected graph** is represented using an adjacency list, where each vertex stores a list of its adjacent vertices. For example, consider the following graph:

```
0 -- 1
|    |
2 -- 3
|    |
4
```

The graph has 5 vertices: 0, 1, 2, 3, and 4. The edges are represented as:

- 0 is connected to 1 and 2.
- 1 is connected to 0, 3, and 4.
- 2 is connected to 0 and 3.
- 3 is connected to 1, 2, and 4.
- 4 is connected to 1 and 3.

This graph is represented in the adjacency list as follows:

```
0: [1, 2]
1: [0, 3, 4]
2: [0, 3]
3: [1, 2, 4]
4: [1, 3]
```

## DFS Algorithm

### Depth First Search (DFS) Traversal
- DFS starts from a given vertex and explores as far as possible along each branch before backtracking.
- The traversal is implemented **recursively**, and it explores each vertex's neighbors as deeply as possible.
- A `visited` array is used to ensure each vertex is visited only once.

## BFS Algorithm

### Breadth First Search (BFS) Traversal
- BFS starts from a given vertex and explores all its neighbors level by level.
- The algorithm uses a **queue** to explore vertices in a breadth-first manner.
- A `visited` array is used to ensure each vertex is visited only once.



You should see the DFS and BFS traversal outputs printed to the console.

## Example

Given the following graph:

```
0 -- 1
|    |
2 -- 3
|    |
4
```

DFS starting from vertex 0 will print: `0 1 3 4 2 `

BFS starting from vertex 0 will print: `0 1 2 3 4`

## Explanation of Code

### Graph Class

The Graph class represents the graph with the following member functions:

- **Constructor (Graph(int v))**:
  Initializes the graph with v vertices and resizes the adjacency list to accommodate all vertices.

- **addEdge(int u, int v)**:
  Adds an undirected edge between vertices u and v by adding v to the adjacency list of u and u to the adjacency list of v.

- **DFS(int vertex, std::vector<bool>& visited)**:
  This is a recursive function that performs a depth-first search starting from the given vertex.
  It marks the vertex as visited, prints it, and recursively visits all its unvisited neighbors.

- **BFS(int start)**:
  This function performs a breadth-first search starting from the start vertex.
  It uses a queue to explore vertices level by level, printing each vertex as it is visited.

### Main Function

- A graph with 5 vertices is created.
- Edges are added between the vertices using addEdge.
- The program demonstrates the DFS and BFS algorithms starting from vertex 0.

## Key Concepts

### Depth First Search (DFS)

- **Time Complexity**: O(V + E) where V is the number of vertices and E is the number of edges.
- **Space Complexity**: O(V) due to the recursive stack and the visited array.
- **Traversal Strategy**: DFS explores the graph by visiting as deep as possible before backtracking. It uses a stack (implicitly with recursion).

### Breadth First Search (BFS)

- **Time Complexity**: O(V + E) where V is the number of vertices and E is the number of edges.
- **Space Complexity**: O(V) due to the queue and the visited array.
- **Traversal Strategy**: BFS explores all vertices at the current level before moving to the next level. It uses a queue for level-order traversal.

## Conclusion

In this project, we've implemented both DFS and BFS traversal algorithms for an undirected graph. Both algorithms are fundamental in graph theory and have wide applications in computer science, such as searching, pathfinding, and graph analysis.
