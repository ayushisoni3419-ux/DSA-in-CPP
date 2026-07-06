#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing a queen is safe
bool isSafe(vector<vector<char>> &board, int row, int col, int n)
{
    // Check upper-left diagonal
    int r = row;
    int c = col;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    // Check same column
    r = row;
    c = col;
    while (r >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
    }

    // Check upper-right diagonal
    r = row;
    c = col;
    while (r >= 0 && c < n)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c++;
    }

    return true;
}

// Backtracking function
void solve(vector<vector<char>> &board, int row, int n)
{
    // Base Case
    if (row == n)
    {
        // Print the board
        cout << "Solution:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Try placing queen in every column
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            // Place Queen
            board[row][col] = 'Q';

            // Recursive Call
            solve(board, row + 1, n);

            // Backtrack
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    solve(board, 0, n);

    return 0;
}