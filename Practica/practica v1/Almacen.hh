/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/
#ifndef ALMACEN_HH
#define ALMACEN_HH

#include "Sala.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/*
 * Clase Almacen
 */

/** @class Almacen
	@brief Representa el almacen virtual que contiene en su interior el conjunto completo de salas.
	
	Ofrece operaciones para "movernos" entre las diferentes salas.
*/

class Almacen {
	
  private:
	
	/** @brief Lista de productos y cantidades */
	map<string,int> item_list;
	
	/** @brief Contenido del almacen estructurado (salas) */
	BinTree<Sala> Salas;
	
	/** @brief Consultora encargada de acceder a la Sala con identificador <em>id</em>.
		\pre cierto
		\post E
		\coste Lineal 
	*/
	void sala(int id);
  
  public:
	
	// Constructora
	
	
	/** @brief Creadora por defecto
		\pre cierto
		\post El resultado es un almacen con una sala vacia y una lista de productos vacia.
		\coste Constante
	*/
	Almacen();
	
	
	// Modificadoras
	
	
	/** @brief Modificadora que añade un producto a la lista de productos.
		\pre cierto
		\post La lista de productos del parámetro implícito se mantiene igual y contiene el producto <em>prod</em>. Si previamente lo contenia se produce un error.
		\coste Constante 
	*/
	void poner_prod(const string& prod);
	
	
	/** @brief Modificadora que elimina un producto a la lista de productos.
		\pre cierto
		\post La lista de productos del parámetro implícito se mantiene igual pero sin el producto <em>prod</em>. Si previamente no estaba contenido se produce un error.
		\coste Constante 
	*/
	void quitar_prod(const string& prod);
	
	
	/** @brief Modificadora que distribuye una cantidad de productos por el almacen y retorna la cantidad sobrante.
		\pre
		La cantidad <em>cant</em> de productos <em>prod</em> es positiva.
		
		\post
		Se han distribuido una cantidad <em>cant</em> de productos
		<em>prod</em> por las diferentes salas segun un (*)criterio y se retorna la cantidad de productos no añadidos.
				
			(*)Criterio (jerárquico):
				(1)	Hay que añadir tantos productos como cantidad del
					mismo definida.
					
				(2)	Si el almacen esta lleno, se finaliza el proceso.
					
				(3)	Se empieza por la primera sala, si esta se llena (o
					lo estaba previamente) se divide la cantidad C que
					queda por repartir en 2 partes iguales A y B (si la
					cantidad C es impar, se cumplirá A+1 = B). La
					cantidad A va la sala de la izquierda, y la
					cantidad B a la sala de la derecha. Sucesivamente, aplicamos
					a cada sala el mismo criterio.
					
					
					
				
				
		\coste Lineal.
	*/
	int distribuir(const string& prod, int cant);
	
	
	/** @brief Modificadora de una sala que compacta todos los elementos de la estanteria que contiene.
		\pre	El identificador de sala <em>s</em> pertenece a una sala que existe.
		\post	Todos los elementos de la estanteria del parámetro immplícito 
				quedan agrupados (sin espacios vacios entre	ellos) lo mas abajo
				y a la izquierda posible de la misma y manteniendo el orden previo.
		\coste	Lineal. 
	*/
	void compactar(int s);
	
	
	/** @brief Modificadora de una sala que ordena todos los elementos de la estantería que contiene por orden alfabetico.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe.
		\post 	La estanteria del parámetro implicito tiene los items compactados y ordenados alfabeticamente.
		\coste	Logaritmico. 
	*/
	void reorganizar(int s);
	
	
	/** @brief Modificadora de una sala que, si puede, modifica las dimensiones de la estanteria que contiene.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe y los enteros <em>fil</em> y <em>col</em> son positivos o iguales a 0.
		\post 	Si la cantidad de items cabe en las nuevas dimensiones, la estanteria del parámetro implicito queda redimensionada a <em>fil x col</em> y tiene los items compactados.
				Por contra, si la cantidad de items no cabe en las nuevas dimensiones, se produce un error y el parametro implicito permanece igual.
		\coste	Lineal.
	*/
	bool redimensionar(int s, int fil, int col);
		
		
	// Consultoras
		
		
	/** @brief Consultora que imprime por pantalla la lista de productos y cantidades por orden alfabetico.
		\pre 	Cierto.
		\post 	Se escriben los identificadores de los todos productos y sus respectivas cantidades por orden alfabetico.
		\coste	Lineal.
	*/
	void inventario();
	
	
	/** @brief Consultora que imprime por pantalla la estanteria de la sala solicitada.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe.
		\post 	Se escriben los identificadores de los todos productos y sus respectivas cantidades por orden alfabetico.
		\coste	Lineal.
	*/
	void escribir(int s);
	
	
	/** @brief Consultora que retorna el item que se encuentra en una posicion concreta.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe. Los enteros <em>Fil</em> y <em>col</em> se encuentran dentro del rango (0, FILAS) y (0, COLUMNAS) respectivamente, donde FILAS es el numero total de filas - 1 y COLUMNAS es el numero total de columnas - 1 de la estaneria.
		\post 	Se retorna el identificador del item que se encuentra en la posicion fil-col de la sala s. Si dicha posicion esta vacia se retorna "NULL".
		\coste	Lineal.
	*/
	string consultar_pos(int s, int fil, int col);
	
	
	/** @brief Consultora retorna la cantidad que hay de un producto.
		\pre 	Cierto.
		\post 	Se retorna la cantidad de items del producto <em>prod</em>. En caso de que el prodcuto no este en la lista de productos, se retorna un -1.
		\coste	Constante.
	*/
	int consultar_prod(const string& prod);
	
	
};
#endif
