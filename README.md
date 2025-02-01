## DSA-Practice
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

*Explanation of Optimizations*

**Uses three hash sets:**

- columns[col] → Ensures no two queens are in the same column.
- diag1[row - col] → Prevents queens from attacking along / diagonals.
- diag2[row + col] → Prevents queens from attacking along \ diagonals.

**Backtracking only on valid moves:**

- Instead of checking the whole board (O(N)), we use set lookups (O(1)) to check for conflicts.
  
**Efficiently stores solutions:**

- Uses a vector of strings instead of a 2D array.

Time Complexity Analysis:

Optimized Hashing Approach: O(N!) but much faster in practice due to constant-time lookups in unordered_set.

**2.Sieve of Eratosthenes** 🏛️

The Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a given number N.

*Concept*
1. Create a boolean array of size N+1 initialized to true (assuming all numbers are prime).
2. Start from 2, the smallest prime number.
3. Mark all multiples of 2 as false (not prime).
4. Move to the next unmarked number, mark its multiples as false.
5. Repeat the process until you reach √N.
6. The remaining true values in the array correspond to prime numbers.

Time Complexity Analysis:

O(N log log N) → Much faster than checking each number individually (O(N√N)).

Space Complexity: O(N) → Uses an array of size N.
