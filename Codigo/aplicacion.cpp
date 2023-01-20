/*
* Universidad de las Fuerzas Armadas ESPE
*       Ingenieria de Software
* Autores:
*
* Salazar Encalada Edwin Matthew
* Felix Paredes Cristian David
* Campoverde Encarnacion Carlos Danny
*
* Enunciado: Arbol AVL en modo grafico
*
* Fecha de creacion: 11/01/2023
* Fecha de modificacion: 19/01/2023
*
*/

#include "aplicacion.h"
#include "utilidades.h"

using namespace std;

ArbolAVLApp::ArbolAVLApp() {}

/**
 * @brief  Ejecuta la aplicacion
 *
 */
void ArbolAVLApp::ejecutar()
{
	visualizador_grafico.dibujar(arbol);
	menu();
	visualizador_grafico.finalizar();
}
/**
 * @brief  Muestra el menu de opciones
 *
 */

void ArbolAVLApp::menu()
{
	int seleccion;
	
	do {
		system("cls");
		cout << "1. Insertar" << endl;
		cout << "2. Buscar" << endl;
		cout << "3. Eliminar" << endl;
		cout << "4. Salir" << endl << endl;

		seleccion = leer_numero("Seleccione una opcion: ");
		
		if (seleccion < 1 || seleccion > 4) {
			continue;
		}

		menu_seleccion(seleccion);
	} while (seleccion != 4);
}

/**
 * @brief  Muestra el menu de opciones
 *
 * @param  seleccion
 */
void ArbolAVLApp::menu_seleccion(int seleccion)
{
	switch (seleccion) {
		case 1:
		{
			int valor = leer_numero("Ingrese un valor: ");
			arbol.insertar(valor);
			visualizador_grafico.dibujar(arbol);
		}
		break;
		case 2:
		{
			int valor = leer_numero("Ingrese un valor: ");
			NodoAVL<int>* nodo = arbol.buscar(valor);

			if (nodo != nullptr) {
				cout << "Valor encontrado" << endl;
				visualizador_grafico.dibujar(arbol, nodo);
			} else {
				cout << "Valor no encontrado" << endl;
			}

			cout << endl << endl;
			system("pause");
			visualizador_grafico.dibujar(arbol);
		}
		break;
		case 3:
		{
			int valor = leer_numero("Ingrese un valor: ");
			arbol.eliminar(valor);
			visualizador_grafico.dibujar(arbol);
		}
		break;
	}
}
