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
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <functional>

template <typename T>
class NodoAVL {
public:
	NodoAVL(T valor) {
		valor_ = valor;
	}

	void izquierdo(NodoAVL<T>* izquierdo) {
		izquierdo_ = izquierdo;
	}

	void derecho(NodoAVL<T>* derecho) {
		derecho_ = derecho;
	}

	NodoAVL<T>*& izquierdo() {
		return izquierdo_;
	}

	NodoAVL<T>*& derecho() {
		return derecho_;
	}

	NodoAVL<T>*& padre() {
		return padre_;
	}

	void padre(NodoAVL<T>* padre) {
		padre_ = padre;
	}

	int x() {
		return x_;
	}

	int y() {
		return y_;
	}

	void x(int x) {
		x_ = x;
	}

	void y(int y) {
		y_ = y;
	}

	int height() {
		return height_;
	}

	void height(int height) {
		height_ = height;
	}

	T valor() {
		return valor_;
	}

	void valor(T valor) {
		valor_ = valor;
	}

	int modotail() {
		return modotail_;
	}

	void modotail(int modotail) {
		modotail_ = modotail;
	}

	int ancho_izq() {
		return ancho_izq_;
	}

	int ancho_der() {
		return ancho_der_;
	}

	void ancho_izq(int ancho_izq) {
		ancho_izq_ = ancho_izq;
	}

	void ancho_der(int ancho_der) {
		ancho_der_ = ancho_der;
	}

	bool es_hijo_izq() {
		if (padre_ == nullptr) {
			return true;
		}

		return padre_->izquierdo() == this;
	}

private:
	NodoAVL<T>* derecho_ = nullptr;
	NodoAVL<T>* izquierdo_ = nullptr;
	NodoAVL<T>* padre_ = nullptr;
	T valor_;
	int modotail_;
	int x_ = 1100 / 2;
	int y_ = 50;
	int height_ = 1;
	int ancho_izq_ = 0;
	int ancho_der_ = 0;
};

enum class TipoRecorrido {
	PREORDEN,
	INORDEN,
	POSTORDEN
};

template <typename T>
class ArbolAVL {
public:
	void insertar(T valor);
	void eliminar(T valor);
	NodoAVL<T>* buscar(T valor);
	void recorrer(std::function<void(T)> funcion, TipoRecorrido tipo_recorrido = TipoRecorrido::INORDEN);
	void recorrer(std::function<void(NodoAVL<T>*)> funcion, TipoRecorrido tipo_recorrido = TipoRecorrido::INORDEN);

	NodoAVL<T>* obtener_raiz() { return raiz; }


private:
	void preorden(NodoAVL<T>* nodo, std::function<void(T)> funcion);
	void postorden(NodoAVL<T>* nodo, std::function<void(T)> funcion);
	void inorden(NodoAVL<T>* nodo, std::function<void(T)> funcion);

	void preorden(NodoAVL<T>* nodo, std::function<void(NodoAVL<T>*)> funcion);
	void postorden(NodoAVL<T>* nodo, std::function<void(NodoAVL<T>*)> funcion);
	void inorden(NodoAVL<T>* nodo, std::function<void(NodoAVL<T>*)> funcion);

	//NodoAVL<T>* insertar_recursivo(NodoAVL<T>*& actual, NodoAVL<T>* nodo);
	//NodoAVL<T>* eliminar_recursivo(NodoAVL<T>*& actual, T valor);
	void insertar_recursivo(NodoAVL<T>*& actual, NodoAVL<T>* nodo);
	void eliminar_recursivo(NodoAVL<T>* actual, T valor);
	NodoAVL<T>* buscar_recursivo(NodoAVL<T>* actual, T valor);

	NodoAVL<T>* balancear_arbol(NodoAVL<T>*& actual);
	int obtener_factor_balance(NodoAVL<T>* nodo);
	int obtener_altura(NodoAVL<T>* nodo);
	void rotar_izquierda_izquierda(NodoAVL<T>* nodo);
	void rotar_derecha_derecha(NodoAVL<T>* nodo);
	void rotar_izquierda_derecha(NodoAVL<T>* nodo);
	void rotar_derecha_izquierda(NodoAVL<T>* nodo);
	int maximo(int a, int b) { return a > b ? a : b; }
	void redimensionar();
	int calcular_anchos(NodoAVL<T>* arbol);
	void calcular_posiciones(NodoAVL<T>* arbol, int posicion_x, int posicion_y, int lado);
	void resetear_altura(NodoAVL<T>* arbol);

	NodoAVL<T>* raiz = nullptr;
};

/**
 * Inserta un valor en el árbol.
 * @param valor Valor a insertar.
 */

template <typename T>
void ArbolAVL<T>::insertar(T valor) {
	NodoAVL<T>* nodo = new NodoAVL<T>(valor);

	if (raiz == nullptr) {
		raiz = nodo;
	}
	else {
		insertar_recursivo(raiz, nodo);
	}

	redimensionar();
}

/**
 * Inserta un nodo en el árbol.
 * @param actual Nodo actual.
 * @param nodo Nodo a insertar.
 */
template <typename T>
void ArbolAVL<T>::eliminar(T valor) {
	//raiz = eliminar_recursivo(raiz, valor);
	eliminar_recursivo(raiz, valor);
	redimensionar();
}

/**
 * Elimina un valor del árbol.
 * @param actual Nodo actual.
 * @param valor Valor a eliminar.
 */
template <typename T>
NodoAVL<T>* ArbolAVL<T>::buscar(T valor) {
	NodoAVL<T>* nodo = buscar_recursivo(raiz, valor);

	if (nodo != nullptr && nodo->valor() == valor) {
		return nodo;
	}

	return nullptr;
}

/**
 * Busca un valor en el árbol.
 * @param actual Nodo actual.
 * @param valor Valor a buscar.
 * @return Nodo encontrado.
 */
template <typename T>
void ArbolAVL<T>::recorrer(std::function<void(T)> funcion, TipoRecorrido tipo_recorrido) {
	if (tipo_recorrido == TipoRecorrido::PREORDEN) {
		preorden(raiz, funcion);
	}
	else if (tipo_recorrido == TipoRecorrido::INORDEN) {
		inorden(raiz, funcion);
	}
	else if (tipo_recorrido == TipoRecorrido::POSTORDEN) {
		postorden(raiz, funcion);
	}
}

/**
 * Recorre el árbol en preorden.
 * @param nodo Nodo actual.
 * @param funcion Función a ejecutar.
 */
template <typename T>
void ArbolAVL<T>::recorrer(std::function<void(NodoAVL<T>*)> funcion, TipoRecorrido tipo_recorrido) {
	if (tipo_recorrido == TipoRecorrido::PREORDEN) {
		preorden(raiz, funcion);
	}
	else if (tipo_recorrido == TipoRecorrido::INORDEN) {
		inorden(raiz, funcion);
	}
	else if (tipo_recorrido == TipoRecorrido::POSTORDEN) {
		postorden(raiz, funcion);
	}
}

/**
 * Recorre el árbol en preorden.
 * @param nodo Nodo actual.
 * @param funcion Función a ejecutar.
 */
template <typename T>
void ArbolAVL<T>::preorden(NodoAVL<T>* nodo, std::function<void(T)> funcion) {
	if (nodo != nullptr) {
		funcion(nodo->valor());
		preorden(nodo->izquierdo(), funcion);
		preorden(nodo->derecho(), funcion);
	}
}

/**
 * Recorre el árbol en preorden.
 * @param nodo Nodo actual.
 * @param funcion Función a ejecutar.
 */
template <typename T>
void ArbolAVL<T>::postorden(NodoAVL<T>* nodo, std::function<void(T)> funcion) {
	if (nodo != nullptr) {
		postorden(nodo->izquierdo(), funcion);
		postorden(nodo->derecho(), funcion);
		funcion(nodo->valor());
	}
}

/**
 * Recorre el árbol en preorden.
 * @param nodo Nodo actual.
 * @param funcion Función a ejecutar.
 */
template <typename T>
void ArbolAVL<T>::inorden(NodoAVL<T>* nodo, std::function<void(T)> funcion) {
	if (nodo != nullptr) {
		inorden(nodo->izquierdo(), funcion);
		funcion(nodo->valor());
		inorden(nodo->derecho(), funcion);
	}
}

/**
 * Recorre el árbol en preorden.
 * @param nodo Nodo actual.
 * @param funcion Función a ejecutar.
 */
template <typename T>
void ArbolAVL<T>::preorden(NodoAVL<T>* nodo, std::function<void(NodoAVL<T>*)> funcion) {
	if (nodo != nullptr) {
		funcion(nodo);
		preorden(nodo->izquierdo(), funcion);
		preorden(nodo->derecho(), funcion);
	}
}

/**
 * Recorre el árbol en preorden.
 * @param nodo Nodo actual.
 * @param funcion Función a ejecutar.
 */
template <typename T>
void ArbolAVL<T>::postorden(NodoAVL<T>* nodo, std::function<void(NodoAVL<T>*)> funcion) {
	if (nodo != nullptr) {
		postorden(nodo->izquierdo(), funcion);
		postorden(nodo->derecho(), funcion);
		funcion(nodo);
	}
}

/**
 * Recorre el árbol en preorden.
 * @param nodo Nodo actual.
 * @param funcion Función a ejecutar.
 */
template <typename T>
void ArbolAVL<T>::inorden(NodoAVL<T>* nodo, std::function<void(NodoAVL<T>*)> funcion) {
	if (nodo != nullptr) {
		inorden(nodo->izquierdo(), funcion);
		funcion(nodo);
		inorden(nodo->derecho(), funcion);
	}
}

/**
 * Busca un valor en el árbol.
 * @param actual Nodo actual.
 * @param valor Valor a buscar.
 * @return Nodo encontrado.
 */
template <typename T>
void ArbolAVL<T>::insertar_recursivo(NodoAVL<T>*& arbol, NodoAVL<T>* nodo) {
	if (nodo->valor() < arbol->valor()) {
		if (arbol->izquierdo() == nullptr) {
			arbol->izquierdo(nodo);
			nodo->padre(arbol);
			
			redimensionar();

			if (arbol->height() < arbol->izquierdo()->height() + 1) {
				arbol->height(arbol->izquierdo()->height() + 1);
			}
		}
		else {
			insertar_recursivo(arbol->izquierdo(), nodo);

			if (arbol->height() < arbol->izquierdo()->height() + 1) {
				arbol->height(arbol->izquierdo()->height() + 1);
			}
			
			if ((arbol->derecho() != nullptr && arbol->izquierdo()->height() > arbol->derecho()->height() + 1)
				|| (arbol->derecho() == nullptr && arbol->izquierdo()->height() > 1)) {
				if (nodo->valor() < arbol->izquierdo()->valor()) {
					rotar_derecha_derecha(arbol);
				}
				else {
					rotar_derecha_izquierda(arbol);
				}
			}
		}
	}
	else {
		if (arbol->derecho() == nullptr) {
			arbol->derecho(nodo);
			nodo->padre(arbol);

			nodo->x(arbol->x() + 50 + 1);
			nodo->y(arbol->y() + 50);

			redimensionar();

			if (arbol->height() < arbol->derecho()->height() + 1) {
				arbol->height(arbol->derecho()->height() + 1);
			}
		}
		else {
			insertar_recursivo(arbol->derecho(), nodo);

			if (arbol->height() < arbol->derecho()->height() + 1) {
				arbol->height(arbol->derecho()->height() + 1);
			}

			if ((arbol->izquierdo() != nullptr && arbol->derecho()->height() > arbol->izquierdo()->height() + 1) ||
				(arbol->izquierdo() == nullptr && arbol->derecho()->height() > 1)) {
				if (nodo->valor() >= arbol->derecho()->valor()) {
					rotar_izquierda_izquierda(arbol);
				}
				else {
					rotar_izquierda_derecha(arbol);
				}
			}
		}
	}
}

/*
template <typename T>
NodoAVL<T>* ArbolAVL<T>::insertar_recursivo(NodoAVL<T>*& actual, NodoAVL<T>* nodo) {
	if (actual == nullptr) {
		actual = nodo;
		return actual;
	}
	else if (nodo->valor() < actual->valor()) {
		NodoAVL<T>* izquierdo = actual->izquierdo();
		actual->izquierdo(insertar_recursivo(izquierdo, nodo));
		actual = balancear_arbol(actual);
	}
	else if (nodo->valor() >= actual->valor()) {
		NodoAVL<T>* derecho = actual->derecho();
		actual->derecho(insertar_recursivo(derecho, nodo));
		actual = balancear_arbol(actual);
	}

	return actual;
}*/

/**
 * Busca un valor en el árbol.
 * @param actual Nodo actual.
 * @param valor Valor a buscar.
 * @return Nodo encontrado.
 */
template <typename T>
void ArbolAVL<T>::eliminar_recursivo(NodoAVL<T>* actual, T valor) {
	bool hijo_izq = false;

	if (actual != nullptr) {
		if (actual->padre() != nullptr) {
			hijo_izq = actual->padre()->izquierdo() == actual;
		}

		if (valor == actual->valor()) {
			if (actual->izquierdo() == nullptr && actual->derecho() == nullptr) {
				if (hijo_izq && actual->padre() != nullptr) {
					actual->padre()->izquierdo(nullptr);
				}
				else if (actual->padre() != nullptr) {
					actual->padre()->derecho(nullptr);
				}
				else {
					raiz = nullptr;
				}

				redimensionar();
			}
			else if (actual->izquierdo() == nullptr) {
				if (actual->padre() != nullptr) {
					if (hijo_izq) {
						actual->padre()->izquierdo(actual->derecho());
					}
					else {
						actual->padre()->derecho(actual->derecho());
					}

					actual->derecho()->padre(actual->padre());
				}
				else {
					raiz = actual->derecho();
					raiz->padre(nullptr);
				}

				redimensionar();
			}
			else if (actual->derecho() == nullptr) {
				if (actual->padre() != nullptr) {
					if (hijo_izq) {
						actual->padre()->izquierdo(actual->izquierdo());
					}
					else {
						actual->padre()->derecho(actual->izquierdo());
					}

					actual->izquierdo()->padre(actual->padre());
				}
				else {
					raiz = actual->izquierdo();
					raiz->padre(nullptr);
				}

				redimensionar();
			}
			else { // actual->izquierdo() != nullptr && actual->derecho() != nullptr
				NodoAVL<T>* tmp = actual;
				tmp = actual->izquierdo();

				while (tmp->derecho() != nullptr) {
					tmp = tmp->derecho();
				}

				actual->valor(tmp->valor());

				if (tmp->izquierdo() == nullptr) {
					if (tmp->padre() != actual) {
						tmp->padre()->derecho(nullptr);
					}
					else {
						tmp->izquierdo(nullptr);
					}

					redimensionar();
				}
				else {
					if (tmp->padre() != actual) {
						tmp->padre()->derecho(tmp->izquierdo());
						tmp->izquierdo()->padre(tmp->padre());
					}
					else {
						actual->izquierdo(tmp->izquierdo());
						tmp->izquierdo()->padre(actual);
					}

					redimensionar();
				}

				tmp = tmp->padre();

				if (this->obtener_altura(tmp) != (std::max)(obtener_altura(tmp->izquierdo()), obtener_altura(tmp->derecho())) + 1) {
					tmp->height(
						(std::max)(obtener_altura(tmp->izquierdo()), obtener_altura(tmp->derecho())) + 1
					);
				}

				while (tmp != actual) {
					NodoAVL<T>* tmpPadre = tmp->padre();

					if (obtener_altura(tmp->izquierdo()) - obtener_altura(tmp->derecho()) > 1) {
						if (obtener_altura(tmp->izquierdo()->derecho()) > obtener_altura(tmp->izquierdo()->izquierdo())) {
							rotar_derecha_izquierda(tmp);
						}
						else {
							rotar_derecha_derecha(tmp);
						}
					}

					if (tmpPadre->derecho() != nullptr) {
						if (obtener_altura(tmpPadre) != (std::max)(obtener_altura(tmpPadre->izquierdo()), obtener_altura(tmpPadre->derecho())) + 1) {
							tmpPadre->height(
								(std::max)(obtener_altura(tmpPadre->izquierdo()), obtener_altura(tmpPadre->derecho())) + 1
							);
						}
					}

					tmp = tmpPadre;
				}

				if (obtener_altura(actual->derecho()) - obtener_altura(actual->izquierdo()) > 1) {
					if (obtener_altura(actual->derecho()->izquierdo()) > obtener_altura(actual->derecho()->derecho())) {
						rotar_izquierda_derecha(actual);
					}
					else {
						rotar_izquierda_izquierda(actual);
					}
				}
			}
		}
		else if (valor < actual->valor()) {
			eliminar_recursivo(actual->izquierdo(), valor);

			if (obtener_altura(actual->derecho()) - obtener_altura(actual->izquierdo()) > 1) {
				if (obtener_altura(actual->derecho()->izquierdo()) > obtener_altura(actual->derecho()->derecho())) {
					rotar_izquierda_derecha(actual);
				}
				else {
					rotar_izquierda_izquierda(actual);
				}
			}

			if (obtener_altura(actual) != (std::max)(obtener_altura(actual->izquierdo()), obtener_altura(actual->derecho())) + 1) {
				actual->height(
					(std::max)(obtener_altura(actual->izquierdo()), obtener_altura(actual->derecho())) + 1
				);
			}
		}
		else {
			eliminar_recursivo(actual->derecho(), valor);

			if (obtener_altura(actual->izquierdo()) - obtener_altura(actual->derecho()) > 1) {
				if (obtener_altura(actual->izquierdo()->derecho()) > obtener_altura(actual->izquierdo()->izquierdo())) {
					rotar_derecha_izquierda(actual);
				}
				else {
					rotar_derecha_derecha(actual);
				}
			}

			if (obtener_altura(actual) != (std::max)(obtener_altura(actual->izquierdo()), obtener_altura(actual->derecho())) + 1) {
				actual->height(
					(std::max)(obtener_altura(actual->izquierdo()), obtener_altura(actual->derecho())) + 1
				);
			}
		}
	}
	else {
		std::cerr << "valor no encontrado" << std::endl;
	}
}

/*
template <typename T>
NodoAVL<T>* ArbolAVL<T>::eliminar_recursivo(NodoAVL<T>*& actual, T valor) {
	NodoAVL<T>* padre;

	if (actual == nullptr) {
		return nullptr;
	} else {
		if (valor < actual->valor()) {
			NodoAVL<T>* izquierdo = actual->izquierdo();
			actual->izquierdo(eliminar_recursivo(izquierdo, valor));

			if (obtener_factor_balance(actual) == -2) {
				if (obtener_factor_balance(actual->izquierdo()) <= 0) {
					actual = rotar_derecha_derecha(actual);
				} else {
					actual = rotar_derecha_izquierda(actual);
				}
			}
		} else if (valor > actual->valor()) {
			NodoAVL<T>* derecho = actual->derecho();
			actual->derecho(eliminar_recursivo(derecho, valor));

			if (obtener_factor_balance(actual) == 2) {
				if (obtener_factor_balance(actual->izquierdo()) >= 0) {
					actual = rotar_izquierda_izquierda(actual);
				} else {
					actual = rotar_izquierda_derecha(actual);
				}
			}
		} else {
			if (actual->derecho() != nullptr) {
				padre = actual->derecho();

				while (padre->izquierdo() != nullptr) {
					padre = padre->izquierdo();
				}

				actual->valor(padre->valor());
				NodoAVL<T>* derecho = actual->derecho();
				actual->derecho(eliminar_recursivo(derecho, padre->valor()));

				if (obtener_factor_balance(actual) == 2) {
					if (obtener_factor_balance(actual->izquierdo()) >= 0) {
						actual = rotar_izquierda_izquierda(actual);
					} else {
						actual = rotar_izquierda_derecha(actual);
					}
				}
			} else {
				return actual->izquierdo();
			}
		}
	}

	return actual;
}*/


/**
 * @brief Método que elimina un nodo del árbol AVL.
 * @param valor Valor del nodo a eliminar.
 */

template <typename T>
NodoAVL<T>* ArbolAVL<T>::buscar_recursivo(NodoAVL<T>* actual, T valor) {
	if (actual == nullptr) {
		return nullptr;
	}

	if (valor < actual->valor()) {
		if (valor == actual->valor()) {
			return actual;
		}
		else {
			return buscar_recursivo(actual->izquierdo(), valor);
		}
	}
	else {
		if (valor == actual->valor()) {
			return actual;
		}
		else {
			return buscar_recursivo(actual->derecho(), valor);
		}
	}
}

/**
 * @brief Método que busca un nodo en el árbol AVL.
 * @param valor Valor del nodo a buscar.
 * @return NodoAVL<T>* Nodo encontrado.
 */
template <typename T>
NodoAVL<T>* ArbolAVL<T>::balancear_arbol(NodoAVL<T>*& actual) {
	int factor_balance = obtener_factor_balance(actual);

	if (factor_balance > 1) {
		if (obtener_factor_balance(actual->izquierdo()) > 0) {
			actual = rotar_izquierda_izquierda(actual);
		}
		else {
			actual = rotar_izquierda_derecha(actual);
		}
	}
	else if (factor_balance < -1) {
		if (obtener_factor_balance(actual->derecho()) > 0) {
			actual = rotar_derecha_izquierda(actual);
		}
		else {
			actual = rotar_derecha_derecha(actual);
		}
	}

	return actual;
}

/**
 * @brief Método que balancea el árbol AVL.
 * @param actual Nodo actual.
 * @return NodoAVL<T>* Nodo actual.
 */

template <typename t>
int ArbolAVL<t>::obtener_factor_balance(NodoAVL<t>* nodo) {
	int izq = obtener_altura(nodo->izquierdo());
	int der = obtener_altura(nodo->derecho());
	int factor = izq - der;

	return factor;
}

/**
 * @brief Método que obtiene el factor de balance de un nodo.
 * @param nodo Nodo del que se obtiene el factor de balance.
 * @return int Factor de balance.
 */

template <typename T>
int ArbolAVL<T>::obtener_altura(NodoAVL<T>* nodo) {
	if (nodo == nullptr) {
		return 0;
	}

	return nodo->height();
}
/**
 * @brief Método que obtiene la altura de un nodo.
 * @param nodo Nodo del que se obtiene la altura.
 * @return int Altura del nodo.
 */

template <typename T>
void ArbolAVL<T>::rotar_izquierda_izquierda(NodoAVL<T>* nodo) {
	NodoAVL<T>* A = nodo;
	NodoAVL<T>* B = nodo->derecho();
	NodoAVL<T>* t1 = A->izquierdo();
	NodoAVL<T>* t2 = B->izquierdo();
	NodoAVL<T>* t3 = B->derecho();

	if (t2 != nullptr) {
		t2->padre(A);
	}
	
	B->padre(A->padre());
	
	if (raiz == A) {
		raiz = B;
	}
	else {
		if (A->es_hijo_izq()) {
			A->padre()->izquierdo(B);
		}
		else {
			A->padre()->derecho(B);
		}
	}

	B->izquierdo(A);
	A->padre(B);
	A->derecho(t2);
	resetear_altura(A);
	resetear_altura(B);
	redimensionar();
}

/**
 * @brief Método que rota un nodo hacia la izquierda.
 * @param nodo Nodo a rotar.
 */

template <typename T>
void ArbolAVL<T>::rotar_derecha_derecha(NodoAVL<T>* nodo) {
	NodoAVL<T>* B = nodo;
	NodoAVL<T>* t3 = B->derecho();
	NodoAVL<T>* A = nodo->izquierdo();
	NodoAVL<T>* t1 = A->izquierdo();
	NodoAVL<T>* t2 = A->derecho();

	if (t2 != nullptr) {
		t2->padre(B);
	}

	A->padre(B->padre());

	if (raiz == B) {
		raiz = A;
	}
	else {
		if (B->es_hijo_izq()) {
			B->padre()->izquierdo(A);
		}
		else {
			B->padre()->derecho(A);
		}
	}
	
	A->derecho(B);
	B->padre(A);
	B->izquierdo(t2);
	resetear_altura(B);
	resetear_altura(A);
	redimensionar();
}

/**
 * @brief Método que rota un nodo hacia la derecha.
 * @param nodo Nodo a rotar.
 */
template <typename T>
void ArbolAVL<T>::rotar_izquierda_derecha(NodoAVL<T>* nodo) {
	NodoAVL<T>* A = nodo;
	NodoAVL<T>* B = nodo->derecho()->izquierdo();
	NodoAVL<T>* C = nodo->derecho();
	NodoAVL<T>* t1 = A->izquierdo();
	NodoAVL<T>* t2 = B->izquierdo();
	NodoAVL<T>* t3 = B->derecho();
	NodoAVL<T>* t4 = C->derecho();

	if (t2 != nullptr) {
		t2->padre(A);
		A->derecho(t2);
	}
	
	if (t3 != nullptr) {
		t3->padre(C);
		C->izquierdo(t2);
	}


	if (A->padre() == nullptr) {
		B->padre(nullptr);
		raiz = B;
	}
	else {
		if (A->es_hijo_izq()) {
			A->padre()->izquierdo(B);
		}
		else {
			A->padre()->derecho(B);
		}
		
		B->padre(A->padre());
		A->padre(B);
	}

	B->izquierdo(A);
	A->padre(B);
	B->derecho(C);
	C->padre(B);
	A->derecho(t2);
	C->izquierdo(t3);
	
	resetear_altura(A);
	resetear_altura(C);
	resetear_altura(B);

	redimensionar();
}

/**
 * @brief Método que rota un nodo hacia la izquierda y luego hacia la derecha.
 * @param nodo Nodo a rotar.
 */

template <typename T>
void ArbolAVL<T>::rotar_derecha_izquierda(NodoAVL<T>* nodo) {
	NodoAVL<T>* A = nodo->izquierdo();
	NodoAVL<T>* B = nodo->izquierdo()->derecho();
	NodoAVL<T>* C = nodo;
	NodoAVL<T>* t1 = A->izquierdo();
	NodoAVL<T>* t2 = B->izquierdo();
	NodoAVL<T>* t3 = B->derecho();
	NodoAVL<T>* t4 = C->derecho();

	if (t2 != nullptr) {
		t2->padre(A);
		A->derecho(t2);
	}
	
	if (t3 != nullptr) {
		t3->padre(C);
		C->izquierdo(t2);
	}
	
	if (C->padre() == nullptr) {
		B->padre(nullptr);
		raiz = B;
	}
	else {
		if (C->es_hijo_izq()) {
			C->padre()->izquierdo(B);
		}
		else {
			C->padre()->derecho(B);
		}
		
		B->padre(C->padre());
		C->padre(B);
	}
	
	B->izquierdo(A);
	A->padre(B);
	B->derecho(C);
	C->padre(B);
	A->derecho(t2);
	C->izquierdo(t3);
	
	resetear_altura(A);
	resetear_altura(C);
	resetear_altura(B);

	redimensionar();
}

/**
 * @brief Método que inserta un nodo en el árbol.
 * @param nodo Nodo a insertar.
 */

template<typename T>
inline void ArbolAVL<T>::redimensionar()
{
	int inicial = 1100 / 2;
	calcular_anchos(raiz);

	if (raiz != nullptr)
	{
		if (raiz->ancho_izq() > inicial) {
			inicial = raiz->ancho_izq();
		}
		else if (raiz->ancho_der() > inicial) {
			inicial = (std::max)(raiz->ancho_izq(), 2 * inicial - raiz->ancho_der());
		}

		calcular_posiciones(raiz, inicial, 50, 0);
	}
}

/**
 * @brief Método que inserta un nodo en el árbol.
 * @param nodo Nodo a insertar.
 */

template<typename T>
inline int ArbolAVL<T>::calcular_anchos(NodoAVL<T>* arbol)
{
	if (arbol == nullptr) {
		return 0;
	}

	arbol->ancho_izq((std::max)(calcular_anchos(arbol->izquierdo()), 50 / 2));
	arbol->ancho_der((std::max)(calcular_anchos(arbol->derecho()), 50 / 2));

	return arbol->ancho_izq() + arbol->ancho_der();
}

/**
 * @brief Método que inserta un nodo en el árbol.
 * @param nodo Nodo a insertar.
 */

template<typename T>
inline void ArbolAVL<T>::calcular_posiciones(NodoAVL<T>* arbol, int posicion_x, int posicion_y, int lado)
{
	if (arbol != nullptr)
	{
		arbol->y(posicion_y);

		if (lado == -1)
		{
			posicion_x = posicion_x - arbol->ancho_der();
		}
		else if (lado == 1)
		{
			posicion_x = posicion_x + arbol->ancho_izq();
		}

		arbol->x(posicion_x);
		calcular_posiciones(arbol->izquierdo(), posicion_x, posicion_y + 50, -1);
		calcular_posiciones(arbol->derecho(), posicion_x, posicion_y + 50, 1);
	}
}

/**
 * @brief Método que inserta un nodo en el árbol.
 * @param nodo Nodo a insertar.
 */


template<typename T>
inline void ArbolAVL<T>::resetear_altura(NodoAVL<T>* arbol)
{
	if (arbol != nullptr)
	{
		int nueva_altura = (std::max)(obtener_altura(arbol->izquierdo()), obtener_altura(arbol->derecho())) + 1;

		if (arbol->height() != nueva_altura)
		{
			arbol->height((std::max)(obtener_altura(arbol->izquierdo()), obtener_altura(arbol->derecho())) + 1);
		}
	}
}
