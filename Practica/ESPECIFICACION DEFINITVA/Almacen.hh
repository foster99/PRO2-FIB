/** @file Almacen.hh
    @brief Especificación de la clase Almacen.
*/
#ifndef ALMACEN_HH
#define ALMACEN_HH

  #include "Sala.hh"

#ifndef NO_DIAGRAM

  #include <map>
  #include <set>
  #include "BinTree.hh"
  
#endif

/*
 * Clase Almacen
 */

/** @class	Almacen
	@brief	Representa el almacén virtual que contiene en su interior el
			conjunto completo de salas. A su vez el almacén cuenta con un
			registro de todos los productos que contiene con sus respectivas
			cantidades.
	
			Ofrece operaciones tanto como para modificar como para consultar el
			contenido de las salas y la lista o registro de productos de nuestro
			sistema.
*/

class Almacen {
	
  private:
	
	/** @brief	Lista de productos y cantidades.*/
	map<string,int> item_list;
	
	/** @brief	Contenido del almacén estructurado (salas). */
	BinTree<Sala> sala;
	
	/** @brief	Función encargada de acceder a la Sala con identificador <em>id</em>.
		\pre	Cierto.
		\post	El parámetro implícito apunta a la sala asociada al identificador <em>id</em>.
		\coste	Lineal.
	*/
	void apunta_sala(int id);
	
	
	/** @brief  Lista de identificadores de las salas ordenados. */
	set<int> id_salas;
	
	
	
  public:
	
	// Constructora
	
	
	/** @brief	Creadora de un almacén estructurado y completado con N salas asociadas cada una a un identificador.
		\pre 	N es un entero positivo.
		\post 	El parámetro implícito esta estructurado y completado con N salas asociadas cada una a un identificador.
		\coste	Lineal
	*/
	Almacen(int N);
	
	
	// Modificadoras
	
	
	/** @brief	Modificadora que añade un producto a la lista de productos.
		\pre 	Cierto.
		\post	La lista de productos del parámetro implícito se mantiene igual y contiene el producto <em>prod</em>. Si previamente lo contenia se produce un error.
		\coste	Constante.
	*/
	void poner_prod(const string& prod);
	
	
	/** @brief	Modificadora que elimina un producto a la lista de productos.
		\pre 	Cierto.
		\post	La lista de productos del parámetro implícito se mantiene igual pero sin el producto <em>prod</em>. Si previamente no estaba contenido se produce un error.
		\coste	Constante.
	*/
	void quitar_prod(const string& prod);
	
	
	/** @brief	Modificadora que añade una cantidad concreta de un producto a una sala concreta.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe y la cantidad <em>cant</em> es positiva.
		\post 	Si el producto no existe se produce un error. Si existe, la estantería de la sala contenida en el parámetro implícito ha sido llenada con una cantidad <em>cant</em> de productos <em>prod</em> o bien hasta que se ha llenado la estaneria o bien hasta que se haya agotado la susodicha cantidad. El rellenado se habra realizado llenando primero los huecos a partir del hueco que fuera antes. Se retorna la cantidad de items que no cabian en la estantería o un -1 en caso de producirse un error.
		\coste	Lineal. 
	*/
	int poner_items(int s, const string& prod, int cant);
	
	
	/** @brief	Modificadora que quita una cantidad concreta de un producto a una sala concreta.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe y la cantidad <em>cant</em> es positiva.
		\post 	Si el producto no existe se produce un error. Se quita de la estaneria de la sala contenida en el parámetro implícito una cantidad <em>cant</em> de productos <em>prod</em> empezando por el producto que vaya antes. Se retorna la cantidad de items que no se han podido quitar o un -1 en caso de producirse un error.
		\coste	Lineal. 
	*/
	int quitar_items(int s, const string& prod, int cant);
	
	
	/** @brief	Modificadora que distribuye una cantidad de productos por el almacén y retorna la cantidad sobrante.
		\pre	La cantidad <em>cant</em> de productos <em>prod</em> es positiva.
		
		\post	Se han distribuido una cantidad <em>cant</em> de productos <em>prod</em> por las diferentes salas
				segun un (*)criterio y se retorna la cantidad de productos no añadidos.
		
				(*)Criterio (jerárquico):
				
				(1)	Hay que añadir tantos productos como cantidad del mismo definida.
					
				(2)	Si el parámetro implícito esta lleno, se finaliza el proceso.
					
				(3)	Se empieza por la primera sala, si esta se llena (o lo estaba previamente) se divide la cantidad C que queda
					por repartir en 2 partes iguales A y B (si la cantidad C es impar, se cumplirá A+1 = B). La cantidad A va la
					sala de la izquierda, y la cantidad B a la sala de la derecha. Sucesivamente, aplicamos a cada sala el mismo proceso y criterio.
					

		\coste	Lineal.
	*/
	int distribuir(const string& prod, int cant);
	
	
	/** @brief	Modificadora de una sala que compacta todos los items de la estantería que contiene.
		\pre	El identificador de sala <em>s</em> pertenece a una sala que existe.
		\post	Todos los items de la estantería contenida en la sala del parámetro implícito 
				quedan agrupados (sin espacios vacíos entre	ellos) lo mas abajo
				y a la izquierda posible de la misma y manteniendo el orden previo.
		\coste	Lineal. 
	*/
	void compactar(int s);
	
	
	/** @brief	Modificadora de una sala que ordena todos los elementos de la estantería que contiene por orden alfabético.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe.
		\post 	La sala <em>s</em> del parámetro implícito tiene los items de la estantería compactados y ordenados alfabeticamente segun el identificador de producto.
		\coste	Logarítmico. 
	*/
	void reorganizar(int s);
	
	
	/** @brief	Modificadora de una sala que, si puede, modifica las dimensiones de la estantería que contiene.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe y los enteros <em>fil</em> y <em>col</em> son positivos o iguales a 0.
		\post 	Si la cantidad de items cabe en las nuevas dimensiones, la estantería contenida en la sala del parámetro implícito queda redimensionada a <em>fil x col</em> y tiene los items compactados.
				Por contra, si la cantidad de items no cabe en las nuevas dimensiones, se produce un error y el parámetro implícito permanece igual.
		\coste	Lineal.
	*/
	bool redimensionar(int s, int fil, int col);
	
	
	/** @brief	Modificadora lee las dimensiones de las salas contenidas en el parámetro implícito por orden de identificador.
		\pre 	Cierto.
		\post 	Todas las salas del parámetro implícito contienen una estantería dimensionada vacia.
		\coste	Lineal.
	*/
	void lectura_dimensiones_salas();

	
	// Consultoras
	

	/** @brief	Consultora que imprime por pantalla la lista de productos y cantidades por orden alfabético.
		\pre 	Cierto.
		\post 	Se escriben los identificadores de los todos productos y sus respectivas cantidades por orden alfabético.
		\coste	Lineal.
	*/
	void inventario();
	
	
	/** @brief	Consultora que imprime por pantalla la estantería de la sala solicitada.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe.
		\post 	Se imprime por pantalla, tal y como estan posicionados en la estantería,
				el conenido de cada una de las celdas de la estantería	de la sala <em>s</em>.
				Si hay un item, se imprime su identificar. Si hay un hueco vacío, se imprime NULL.
		\coste	Lineal.
	*/
	void escribir(int s);
	
	
	/** @brief	Consultora que retorna el item que se encuentra en una posicion concreta de la estantería, contenida en una sala.
		\pre 	El identificador de sala <em>s</em> pertenece a una sala que existe. Los enteros <em>i</em> y <em>j</em> se encuentran dentro del rango (0, FILAS) y (0, COLUMNAS) respectivamente, donde FILAS es el numero total de filas - 1 y COLUMNAS es el numero total de columnas - 1 de la estaneria.
		\post 	Se retorna el identificador del item que se encuentra en la posicion i-j de la sala s. Si dicha posicion esta vacia se retorna "NULL".
		\coste	Lineal.
	*/
	string consultar_pos(int s, int i, int j);
	
	
	/** @brief	Consultora retorna la cantidad que hay de un producto.
		\pre 	Cierto.
		\post 	Se retorna la cantidad de items del producto <em>prod</em>. En caso de que el prodcuto no este en la lista de productos, se retorna un -1.
		\coste	Constante.
	*/
	int consultar_prod(const string& prod);
	
	
};
#endif
