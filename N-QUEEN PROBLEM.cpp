#include <iostream>
#include <vector>
using namespace std;

// Utility function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Utility function to check if a queen can be placed at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Recursive function to solve N-Queen problem
bool solveNQueen(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        printBoard(board);  
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;  // Place queen
            foundSolution = solveNQueen(board, row + 1, N) || foundSolution;
            board[row][col] = 0;  // Backtrack
        }
    }
    return foundSolution;
}

int main() {
    int N = 4;
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueen(board, 0, N)) {
        cout << "No solution exists." << endl;
    }
    return 0;
}
