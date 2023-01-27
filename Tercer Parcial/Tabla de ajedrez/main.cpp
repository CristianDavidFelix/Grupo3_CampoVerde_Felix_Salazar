/*

* Universidad de las Fuerzas Armadas ESPE
*       Ingenieria de Software
* Autores:
*
* Salazar Encalada Edwin Matthew
* Felix Paredes Cristian David
* Campoverde Encarnacion Carlos Danny
*
* Enunciado: Tablero de ajedrez en consola
*
* Fecha de creacion: 25/01/2023
* Fecha de modificacion: 26/01/2023
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;

const int N = 8;
const int tam_aumentado = 4; // Tamaño aumentado

int main()
{
    // Abre el archivo de texto
    ifstream file("chessboard.txt");
    // Verifica que el archivo se haya abierto correctamente
    if (!file)
    {
        cout << "Error al abrir el archivo" << endl;
        return 1;
