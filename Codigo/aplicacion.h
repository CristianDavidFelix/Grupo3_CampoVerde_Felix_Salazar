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

#pragma once
#include "arbol_avl.h"
#include "visualizador_grafico.h"

class ArbolAVLApp
{
public:
	ArbolAVLApp();
	void ejecutar();
	void menu();
	void menu_seleccion(int seleccion);
	
private:
	ArbolAVL<int> arbol;
	VisualizadorGrafico<int> visualizador_grafico;
};
