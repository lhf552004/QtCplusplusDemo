#ifndef QUEEN_H
#define QUEEN_H
#include <vector>
#include <string>

bool isSafe(std::vector<std::string>& board, int row, int col, int n) {
    for(int i = 0; i< row; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    for(int i = row-1, j = col-1; i>= 0 && j>=0 ; i--,j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    for(int i = row-1, j = col+1; i>= 0 && j<n ; i--,j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

}

void solve(int n, int row, std::vector<std::string>& board, std::vector<std::vector<std::string>>& solutions) {
    if(row == n) {
        solutions.push_back(board);
    }

    for(int col = 0; col < n; col++) {
        if(isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(n, row+1, board, solutions);
            board[row][col] = '.';
        }
    }
}

std::vector<std::vector<std::string>> solveQueens(int n) {
    std::vector<std::vector<std::string>> solutions;
    std::vector<std::string> board(n, std::string(n, '.'));

    solve(n, 0, board, solutions);
    return solutions;
}
#endif // QUEEN_H
