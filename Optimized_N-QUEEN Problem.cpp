#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class NQueens {
private:
    int N;
    vector<vector<string>> solutions;
    unordered_set<int> columns, diag1, diag2;

    void solve(int row, vector<string>& board) {
        if (row == N) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++) {
            if (columns.count(col) || diag1.count(row - col) || diag2.count(row + col)) continue;

            // Place the queen
            board[row][col] = 'Q';
            columns.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            solve(row + 1, board); // Move to next row

            // Backtrack
            board[row][col] = '.';
            columns.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(N, string(N, '.'));
        solve(0, board);
        return solutions;
    }

    void printSolutions() {
        for (const auto& sol : solutions) {
            for (const auto& row : sol) {
                cout << row << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    int N = 8; // Solve for N=8
    NQueens nq;
    vector<vector<string>> result = nq.solveNQueens(N);
    
    cout << "Total Solutions for " << N << "-Queens: " << result.size() << endl;
    nq.printSolutions();

    return 0;
}
