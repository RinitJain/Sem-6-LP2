# N-Queen Problem (Constraint Satisfaction Problem)

## What is the N-Queen Problem?

The N-Queen problem is a classic combinatorial problem that involves placing **N chess queens on an N x N chessboard** so that no two queens threaten each other. This means:

* No two queens can be in the same **row**.
* No two queens can be in the same **column**.
* No two queens can be on the same **diagonal** (both positive and negative diagonals).

The goal is to find all the distinct arrangements that satisfy these conditions.

## Conditions Checked While Placing Queens

When placing a queen at position `(row, col)`, we check the following three constraints:

1. **Column Constraint**: Is there already a queen placed in column `col`?
2. **Positive Diagonal Constraint (bottom left to top right)**: Is there a queen on the diagonal represented by `row + col`?
3. **Negative Diagonal Constraint (top left to bottom right)**: Is there a queen on the diagonal represented by `row - col`?

If all three checks pass, then it is safe to place a queen at `(row, col)`.

## How the Backtracking Works (Example: N = 4)

Backtracking is a trial-and-error algorithmic technique that incrementally builds candidates to the solutions and abandons a candidate (“backtracks”) as soon as it determines that this candidate cannot possibly lead to a valid solution.

For the N-Queen problem, we attempt to place a queen in each row one at a time. The approach is recursive:

1. Start with row 0.
2. Try placing the queen in every column of that row.
3. For each attempted placement, check the 3 conditions:

   * Is the column free?
   * Is the positive diagonal (row + col) free?
   * Is the negative diagonal (row - col) free?
4. If the queen can be placed safely, mark the position and proceed to the next row.
5. If we reach the end (row == n), we have placed all queens successfully and print the board.
6. Whether we succeed or fail, we backtrack: remove the queen, and try the next column in the previous row.

### Example for N = 4:

The algorithm tries placing a queen row-by-row. For instance:

* Row 0: Try column 0 → safe, place queen.
* Row 1: Try columns 0–3 → only column 2 is safe, place queen.
* Row 2: No safe position → backtrack to Row 1 and try next columns.
* Row 1: Try column 3 → safe, place queen.
* Continue similarly until all 4 queens are placed.

One Valid Solution:

```
. Q . .
. . . Q
Q . . .
. . Q .
```

Explanation:

* Queens placed at (0,1), (1,3), (2,0), (3,2)
* None of them share the same row, column, or diagonal.

We use a recursive approach where we attempt to place a queen in each row. For every row, we:

* Try every column from `0` to `n-1`.
* Check if it's safe to place a queen at that column.
* If yes, we place the queen and move to the next row.
* If we reach row `n`, it means we've successfully placed queens in all rows, and we print the board.
* After checking a position, we backtrack by removing the queen and trying the next column.

### Example for N = 4:

Valid Solution:

```
. Q . .
. . . Q
Q . . .
. . Q .
```

Explanation:

* Queen at (0,1), (1,3), (2,0), (3,2) — No queens attack each other.

## Code Components Explained

### Class `n_queen`

This class encapsulates the logic and state for solving the N-Queen problem.

#### Member Variable

* `bool found`: Keeps track of whether at least one solution was found.

#### Constructor

* Initializes `found` to `false`.

### `isSafe()`

* Arguments: board, row, col, n, sets for cols, positive diagonals, negative diagonals
* Returns `true` if it is safe to place a queen at (row, col) based on the 3 constraint checks.

### `solveQueens()`

* A recursive backtracking function to try placing queens row by row.
* Base Case: If `row == n`, it prints the board and sets `found = true`.
* For each column in the current row, it checks safety and proceeds to the next row if safe.
* Performs backtracking by removing the queen and trying the next possibility.

### `run()`

* Takes user input `n`.
* Initializes the board and the constraint-tracking sets.
* Starts solving from the 0th row.
* Prints a message if no solution is found.

### `main()`

* Instantiates the `n_queen` class and calls the `run()` method.
* Compact and clean with `return n_queen().run();`

---

This code finds and prints all valid solutions for the N-Queen problem using backtracking, while avoiding unnecessary computations by leveraging sets for constraint checks.
