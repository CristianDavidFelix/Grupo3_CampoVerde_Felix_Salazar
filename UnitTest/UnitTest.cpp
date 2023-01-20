#include "pch.h"
#include "CppUnitTest.h"
#include "ArbolAVL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestArbolAVL
{
	TEST_CLASS(UnitTestArbolAVL)
	{
	public:
		TEST_METHOD(TestInsertar)
		{
			ArbolAVL<int> arbol;
			arbol.insertar(5);
			arbol.insertar(3);
			arbol.insertar(7);

			Assert::IsNotNull(arbol.buscar(5));
			Assert::IsNotNull(arbol.buscar(3));
			Assert::IsNotNull(arbol.buscar(7));
		}

		TEST_METHOD(TestEliminar)
		{
			ArbolAVL<int> arbol;
			arbol.insertar(5);
			arbol.insertar(3);
			arbol.insertar(7);

			arbol.eliminar(3);
			Assert::IsNull(arbol.buscar(3));

			arbol.eliminar(5);
			Assert::IsNull(arbol.buscar(5));
		}

		TEST_METHOD(TestBuscar)
		{
			ArbolAVL<int> arbol;
			arbol.insertar(5);
			arbol.insertar(3);
			arbol.insertar(7);

			Assert::IsNotNull(arbol.buscar(5));
			Assert::IsNotNull(arbol.buscar(3));
			Assert::IsNotNull(arbol.buscar(7));

				// Configurar el estado inicial antes de cada prueba
				virtual void SetUp() {
					arbol.insertar(5);
					arbol.insertar(3);
					arbol.insertar(7);
					arbol.insertar(2);
					arbol.insertar(4);
					arbol.insertar(6);
					arbol.insertar(8);
				}
			};

			// Prueba para comprobar el correcto funcionamiento de la función insertar
		TEST_F(TestArbolAVL, insertarTest) {
			arbol.insertar(1);
			arbol.insertar(9);
			arbol.insertar(10);
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_NE(arbol.buscar(1), nullptr);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_NE(arbol.buscar(9), nullptr);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_NE(arbol.buscar(10),
		};

		/ Prueba para comprobar el correcto funcionamiento de la función buscar
			TEST_F(TestArbolAVL, buscarTest) {
			// Comprobar que se encuentra el valor 5 en el arbol
			EXPECT_NE(arbol.buscar(5), nullptr);
			// Comprobar que se encuentra el valor 3 en el arbol
			EXPECT_NE(arbol.buscar(3), nullptr);
			// Comprobar que no se encuentra el valor 0 en el arbol
			EXPECT_EQ(arbol.buscar(0), nullptr);
		};

				// Prueba para comprobar el correcto funcionamiento de la función eliminar
		TEST_F(TestArbolAVL, eliminarTest) {
			arbol.eliminar(3);
			// Comprobar que el valor 3 ya no se encuentra en el arbol
			EXPECT_EQ(arbol.buscar(3), nullptr);
			arbol.eliminar(5);
			// Comprobar que el valor 5 ya no se encuentra en el arbol
			EXPECT_EQ(arbol.buscar(5), nullptr);
			arbol.eliminar(8);
			// Comprobar que el valor 8 ya no se encuentra en el arbol
			EXPECT_EQ(arbol.buscar(8), nullptr);
		};

				// Prueba para comprobar el correcto funcionamiento de la función obtener_factor_balance
		TEST_F(TestArbolAVL, obtenerFactorBalanceTest) {
			// Comprobar que el factor de balance del nodo con valor 5 es 0
			EXPECT_EQ(arbol.obtener_factor_balance(arbol.buscar(5)), 0);
			// Comprobar que el factor de balance del nodo con valor 3 es -1
			EXPECT_EQ(arbol.obtener_factor_balance(arbol.buscar(3)), -1);
			// Comprobar que el factor de balance del nodo con valor 7 es 1
			EXPECT_EQ(arbol.obtener_factor_balance(arbol.buscar(7)), 1);
		};

		TEST_F(TestArbolAVL, insertarTest) {
			arbol.insertar(1);
			arbol.insertar(9);
			arbol.insertar(10);
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_NE(arbol.buscar(1), nullptr);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_NE(arbol.buscar(9), nullptr);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_NE(arbol.buscar(10), nullptr);
		};
				
				// Prueba para comprobar el correcto funcionamiento de la función leer numero
		TEST_F(TestArbolAVL, leerNumeroTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(leer_numero("1"), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(leer_numero("9"), 9);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(leer_numero("10"), 10);
		};

				
		TEST_F(TestArbolAVL, calcularPosicionesTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_posiciones(arbol.buscar(1), 1, 1, 1), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_posiciones(arbol.buscar(9), 1, 1, 1), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_posiciones(arbol.buscar(10), 1, 1, 1), 1);
		};
				
				
		TEST_F(TestArbolAVL, rotarIzquierdaDerechaTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.rotar_izquierda_derecha(arbol.buscar(1)), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.rotar_izquierda_derecha(arbol.buscar(9)), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.rotar_izquierda_derecha(arbol.buscar(10)), 1);
		};

		TEST_F(TestArbolAVL, rotarDerechaIzquierdaTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.rotar_derecha_izquierda(arbol.buscar(1)), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.rotar_derecha_izquierda(arbol.buscar(9)), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.rotar_derecha_izquierda(arbol.buscar(10)), 1);
		};


				//prueba de insercion
		TEST_F(TestArbolAVL, insertarTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.insertar(1), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.insertar(9), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.insertar(10), 1);
		};
				
				//prueba de calculo de anchos
				
		TEST_F(TestArbolAVL, calcularAnchosTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_anchos(arbol.buscar(1)), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_anchos(arbol.buscar(9)), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_anchos(arbol.buscar(10)), 1);
		};

				//prueba de calculo de posiciones
				
		TEST_F(TestArbolAVL, calcularPosicionesTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_posiciones(arbol.buscar(1), 1, 1, 1), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_posiciones(arbol.buscar(9), 1, 1, 1), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.calcular_posiciones(arbol.buscar(10), 1, 1, 1), 1);
		};

		template <typename T>
		void ArbolAVL<T>::postorden(NodoAVL<T>* nodo, std::function<void(NodoAVL<T>*)> funcion) {
			if (nodo != nullptr) {
				postorden(nodo->izquierdo(), funcion);
				postorden(nodo->derecho(), funcion);
				funcion(nodo);
			}
		}

		template <typename T>
		void ArbolAVL<T>::inorden(NodoAVL<T>* nodo, std::function<void(NodoAVL<T>*)> funcion) {
			if (nodo != nullptr) {
				inorden(nodo->izquierdo(), funcion);
				funcion(nodo);
				inorden(nodo->derecho(), funcion);
			}
		}
		
		TEST_F(TestArbolAVL, postordenTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.postorden(arbol.buscar(1)), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.postorden(arbol.buscar(9)), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.postorden(arbol.buscar(10)), 1);
		};
		
		TEST_F(TestArbolAVL, inordenTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.inorden(arbol.buscar(1)), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.inorden(arbol.buscar(9)), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.inorden(arbol.buscar(10)), 1);
		};

		TEST_F(TestArbolAVL, preordenTest) {
			// Comprobar que el valor 1 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.preorden(arbol.buscar(1)), 1);
			// Comprobar que el valor 9 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.preorden(arbol.buscar(9)), 1);
			// Comprobar que el valor 10 se ha insertado correctamente en el arbol
			EXPECT_EQ(arbol.preorden(arbol.buscar(10)), 1);
		};
				
		int main(int argc, char** argv) {
			::testing::InitGoogleTest(&argc, argv);
			return RUN_ALL_TESTS();
		}

				
				