#ifndef SOLVENQUEENS_H
#define SOLVENQUEENS_H
#include <iostream>
#include <vector>
#include <string>

bool isSafe(const std::vector<std::string>& board, int row, int col, int n) {
    // Check if there's a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void solve(int n, int row, std::vector<std::string>& board, std::vector<std::vector<std::string>>& solutions) {
    if (row == n) {
        // Found a valid solution, add it to the solutions vector
        solutions.push_back(board);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q'; // Place the queen
            solve(n, row + 1, board, solutions); // Recurse to place queens in the next row
            board[row][col] = '.'; // Backtrack and remove the queen
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> solutions; // To store all solutions
    std::vector<std::string> board(n, std::string(n, '.')); // Initialize the board with empty cells ('.')

    solve(n, 0, board, solutions); // Start solving from the first row
    return solutions;
}
#endif // SOLVENQUEENS_H
