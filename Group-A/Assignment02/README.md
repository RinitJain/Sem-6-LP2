# A* Pathfinding Algorithm Implementation

## Description
This C++ implementation demonstrates the A* pathfinding algorithm on a 5x5 grid. The algorithm finds the shortest path between a start and goal point while avoiding obstacles.

## Features
- A* algorithm with Manhattan distance heuristic
- Visualization of pathfinding process
- Customizable grid layout
- Path reconstruction and display

## Code Structure
- `Cell` struct: Represents each grid cell with position, cost values (g, h), and parent pointer
- `heuristic()`: Calculates Manhattan distance between two points
- `isValid()`: Checks if a cell is within bounds and walkable
- `printPath()`: Reconstructs and displays the final path
- `a_star()`: Main algorithm implementation
- Predefined grid with obstacles (1 = obstacle, 0 = walkable)

## Example Output
The program will display:
- Node exploration details (coordinates, g/h/f values)
- Final path from start to goal (if found)
- "No path found" message if goal is unreachable

## Customization
To modify the grid or start/goal positions:
1. Edit the `grid` variable in `main()` to change obstacles
2. Update `start` and `goal` pairs in `main()`

## Algorithm Overview
A* combines:
- g(n): Actual cost from start to current node
- h(n): Heuristic estimate from current node to goal
- f(n) = g(n) + h(n): Total estimated path cost

The algorithm prioritizes nodes with lowest f(n) values, ensuring optimal path finding when using an admissible heuristic.
