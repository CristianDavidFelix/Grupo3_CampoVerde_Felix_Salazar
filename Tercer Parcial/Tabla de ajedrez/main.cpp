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
    }

    // Contador de filas
    int filas = 0;
    // Recorre cada línea del archivo
    string line;
    while (getline(file, line))
    {
        filas++;
        // Verifica que la longitud de la línea sea 8
        if (line.length() != N)
        {
            cout << "Error: El archivo debe tener 8 columnas en cada fila" << endl;
            return 1;
        }
        // Verifica que cada caracter de la línea sea 0 o 1
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != '0' && line[i] != '1')
            {
                cout << "Error: El archivo debe tener solo 0 y 1" << endl;
                return 1;
            }
        }
    }
    // Verifica que el archivo tenga 8 filas
    if (filas != N)
    {
        cout << "Error: El archivo debe tener 8 filas" << endl;
        return 1;
    }
    file.close();
    // Esta parte es para centrar el tablero en la pantalla
    // Obtiene el ancho de la consola
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
