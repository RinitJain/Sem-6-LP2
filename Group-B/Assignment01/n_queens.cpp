#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class n_queen{
public:
    bool found;

    n_queen(){
        found = false;
    }

    // Function to check whether a given place is safe to place the queen
    bool isSafe(vector<vector<int>> &board, int row, int col, int n, set<int> &cols, set<int> &posD, set<int> &negD)
    {
        // If any 1 of the 3 condition gets unsatisfied, return false
        if (cols.find(col) != cols.end())
            return false;

        if (posD.find(row + col) != posD.end())
            return false;

        if (negD.find(row - col) != negD.end())
            return false;

        return true;
    }

    // Recursive and Backtracking funciton to exploit all possible locations to place the queen
    bool solveQueens(vector<vector<int>> &board, int row, int n, set<int> &cols, set<int> &posD, set<int> &negD)
    {
        // If row==n, it means we have reached the final row and a solution exists so directly print it
        if (row == n)
        {
            found = true;
            for (auto &r : board)
            {
                for (int cell : r)
                {
                    cout << (cell ? "Q " : ". ");
                }
                cout << endl;
            }
            cout << endl;
            return false; // Don't stop after the first solution; continue to find more
        }

        // Traverse through all the column elements of this row to check if it is safe to place a queen there
        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, row, col, n, cols, posD, negD))
            {
                // Place the queen and update the sets
                board[row][col] = 1;
                cols.insert(col);
                posD.insert(row + col);
                negD.insert(row - col);

                // Recurse for the next row
                solveQueens(board, row + 1, n, cols, posD, negD);

                // Backtrack to the previous row
                board[row][col] = 0;
                cols.erase(col);
                posD.erase(row + col);
                negD.erase(row - col);
            }
        }
        return false; // Continue exploring after printing a solution
    }

    int run()
    {
        int n;
        cout << "Enter value of N: ";
        cin >> n;

        // Create the board (n x n) and our 3 check sets: column, positive diagonal and negative diagonal
        vector<vector<int>> board(n, vector<int>(n, 0));
        set<int> cols, posD, negD;

        solveQueens(board, 0, n, cols, posD, negD);

        if (!found)
            cout << "No solution exists!" << endl;

        return 0;
    }
};

int main(){
    return n_queen().run();
}
