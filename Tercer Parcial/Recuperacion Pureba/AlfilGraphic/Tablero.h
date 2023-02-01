#pragma once
#ifndef TABLERO_H
#define TABLERO_H

#include <graphics.h>
#include <cstdlib>
#include <ctime>

class Tablero {
public:
    const int BOARD_SIZE = 8;
    const int SQUARE_SIZE = 50;
    Tablero();
    void dibujarTablero(int x, int y);
    void dibujarPieza(int x, int y, int color);
};

#endif
