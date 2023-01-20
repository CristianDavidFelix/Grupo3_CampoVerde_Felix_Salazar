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
#include "graphics.h"
#include <string>

template <typename T>
class VisualizadorGrafico {
public:
	VisualizadorGrafico();
	void dibujar(ArbolAVL<T> arbol, NodoAVL<T>* nodo_buscado = nullptr);
	void finalizar();

private:
	void dibujar_recursivo(NodoAVL<T>* raiz);
};

/**
 * @brief Construct a new Visualizador Grafico object
 *
 */

template<typename T>
inline VisualizadorGrafico<T>::VisualizadorGrafico()
{
	initwindow(1100, 900, "Arbol AVL");
	cleardevice();
}

/**
 * @brief Dibuja el arbol AVL
 *
 * @param arbol Arbol AVL a dibujar
 * @param nodo_buscado Nodo a resaltar
 */
template<typename T>
inline void VisualizadorGrafico<T>::dibujar(ArbolAVL<T> arbol, NodoAVL<T>* nodo_buscado)
{
	setbkcolor(BLACK);
	cleardevice();
	
	arbol.recorrer([&](NodoAVL<T>* nodo) {
		int x = nodo->x();
		int y = nodo->y();

		if (nodo->padre() != nullptr) {
			setcolor(WHITE);
			line(x, y, nodo->padre()->x(), nodo->padre()->y());
		}
	}, TipoRecorrido::POSTORDEN);
	
	arbol.recorrer([&](NodoAVL<T>* nodo) {
		int x = nodo->x();
		int y = nodo->y();
		int radius = 20;

		setcolor(GREEN);
		setfillstyle(SOLID_FILL, GREEN);
		
		if (nodo == nodo_buscado) {
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
		}

		fillellipse(x, y, radius, radius);

		std::string valor = std::to_string(nodo->valor());
		setcolor(WHITE);
		setbkcolor(GREEN);



		if (nodo == nodo_buscado) {
			setbkcolor(RED);
		}

		outtextxy(
			x - textwidth((char*)valor.c_str()) / 2,
			y - radius / 2 + 2,
			(char*)valor.c_str());

	}, TipoRecorrido::PREORDEN);
}

/**
 * @brief Finaliza el dibujo
 *
 */
template<typename T>
inline void VisualizadorGrafico<T>::finalizar()
{
	closegraph();
}

/**
 * @brief Dibuja el arbol AVL
 *
 * @param arbol Arbol AVL a dibujar
 * @param nodo_buscado Nodo a resaltar
 */
template<typename T>
inline void VisualizadorGrafico<T>::dibujar_recursivo(NodoAVL<T>* raiz)
{
	
}
