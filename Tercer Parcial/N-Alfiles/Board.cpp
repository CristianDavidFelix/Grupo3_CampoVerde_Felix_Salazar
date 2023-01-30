#include "Board.h"

Board::Board(int n) {
    this->n = n;
    solutions = 0;
    board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
}

void Board::printBoard(std::ofstream& file) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file << board[i][j] << " ";
        }
        file << std::endl;
    }
    file << std::endl;
}

bool Board::isValidMove(int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }

    return true;
}

void Board::nAlfiles(int col) {
    if (col == n) {
        solutions++;
        std::ofstream file;
        file.open("solutions.txt", std::ios::app);
        file << "Solution " << solutions << ":" << std::endl;
        printBoard(file);
        file.close();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isValidMove(i, col)) {
            board[i][col] = 1;
            nAlfiles(col + 1);
            board[i][col] = 0;
        }
    }
}

