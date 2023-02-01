/*
* Universidad de las Fuerzas Armadas ESPE
*       Ingenieria de Software
* Autores:
*
* Salazar Encalada Edwin Matthew
* Felix Paredes Cristian David
* Campoverde Encarnacion Carlos Danny
*
* Enunciado: Correcion de la prueba
*
* Fecha de creacion: 30/01/2023
* Fecha de modificacion: 31/01/2023
*
*/

#include "Tablero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	Tablero tablero;
	tablero.dibujarTablero(0, 0);

	srand(time(NULL));
	int row = rand() % tablero.BOARD_SIZE;
	int col = rand() % tablero.BOARD_SIZE;
	int x = col * tablero.SQUARE_SIZE;
	int y = row * tablero.SQUARE_SIZE;
	tablero.dibujarPieza(x, y, RED);

	int dx[] = { -1, -1, 1, 1, -1, 1, -1, 1 };
	int dy[] = { -1, 1, -1, 1, 1, -1, 1, -1 };

	for (int i = 0; i < 8; i++) {
		int x = col;
		int y = row;
		while (true) {
			x += dx[i];
			y += dy[i];
			if (x >= 0 && x < tablero.BOARD_SIZE && y >= 0 && y < tablero.BOARD_SIZE) {
				tablero.dibujarPieza(x * tablero.SQUARE_SIZE, y * tablero.SQUARE_SIZE, GREEN);
				delay(1000);
			}
			else {
				break;
			}
		}
	}

	getch();
	closegraph();

	return 0;

}
