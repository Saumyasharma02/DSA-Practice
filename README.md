# DSA-Practice
**1. N-QUEEN PROBLEM** 🏰
Problem Statement:
The N-Queen problem involves placing N queens on an N x N chessboard such that no two queens can attack each other. This means:
- No two queens share the same row.
- No two queens share the same column.
- No two queens share the same diagonal.
  
Approach:
We can solve this problem using Backtracking, where we try to place a queen in each row, one by one, and backtrack if we encounter a conflict.

Steps:
- Place a queen in the first row and try different columns.
- Move to the next row and try placing the queen in different columns.
- If a column in the current row doesn't lead to a solution, backtrack and move the queen in the previous row to the next column.
- Repeat until all queens are placed successfully.

Time Complexity: O(N!):
- For each row, we have N options to place a queen. If the board size is N x N, there are N! possible ways to arrange N queens.
Space Complexity: O(N^2):
- For the board and auxiliary space used during recursion.
