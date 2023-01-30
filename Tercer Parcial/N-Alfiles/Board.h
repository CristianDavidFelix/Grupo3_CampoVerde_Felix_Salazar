#ifndef BOARD_H
#define BOARD_H

#include <fstream>

class Board {
private:
    int** board;
    int n;

public:
    int solutions;
    Board(int n);
    void printBoard(std::ofstream& file);
    bool isValidMove(int row, int col);
    void nAlfiles(int col);

};

#endif

