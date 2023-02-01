
#include "Tablero.h"

Tablero::Tablero() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
}

void Tablero::dibujarTablero(int x, int y) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if ((i + j) % 2 == 0) {
				setfillstyle(SOLID_FILL, WHITE);
			}
			else {
				setfillstyle(SOLID_FILL, BLACK);
			}
			bar(x + i * SQUARE_SIZE, y + j * SQUARE_SIZE, x + (i + 1) * SQUARE_SIZE, y + (j + 1) * SQUARE_SIZE);
		}
	}
}

void Tablero::dibujarPieza(int x, int y, int color) {
	setfillstyle(SOLID_FILL, color);
	fillellipse(x + SQUARE_SIZE / 2, y + SQUARE_SIZE / 2, SQUARE_SIZE / 2 - 5, SQUARE_SIZE / 2 - 5);
}
