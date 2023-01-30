#include <iostream>
#include <fstream>
#include "Board.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
    std::cout  << "Ingrese el numero de Alfiles: \n";
	std::cin >> n;
    Board b(n);
    b.nAlfiles(0);
    std::cout << "Soluciones Totales: " << b.solutions << std::endl;
    return 0;
}
