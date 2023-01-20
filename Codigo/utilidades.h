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
#include <string>
#include <iostream>
#include <algorithm>

/**
 * @brief Clase NodoAVL
 *
 * @tparam T Tipo de dato del nodo
 */
static inline int leer_numero(std::string mensaje) {
	std::string valor;

	do {
		std::cout << mensaje;
		std::cin >> valor;

		valor.erase(0, valor.find_first_not_of(' '));
		valor.erase(valor.find_last_not_of(' ') + 1);
		

		if (valor.empty()) continue;

		if (valor.find_first_not_of("0123456789") == std::string::npos) {
			return std::stoi(valor);
		}
	} while (true);
}