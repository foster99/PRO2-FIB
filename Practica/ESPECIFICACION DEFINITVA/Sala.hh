/** @file Sala.hh
    @brief Especificación de la clase Sala.
*/

#ifndef SALA_HH
#define SALA_HH


#ifndef NO_DIAGRAM

	#include <vector>
	#include <algorithm>
	#include <iostream>
	
#endif

using namespace std;

/*
 * Clase Sala
 */

/** @class	Sala
	@brief 	Representa una sala virtual asociada a un identificador y que contiene
			una estantería junto a datos relacionadas con la misma: dimensiones,
			espacio ocupado y espacio máximo.
			
			Ofrece operaciones para modificar el contenido de las estanterías así como
			las variables asociadas a la misma y citadas previamente. 
*/
class Sala {
	
  private:
	
	/** @brief Identificador de la sala */
	int id;
	
	/** @brief 	Estantería encargada de alojar en su interior los diferentes items. Cada "celda" de la misma puede estar ocupada por un solo item o por ninguno (hueco vacío).*/
	vector< vector<string> > estanteria;
	
	/** @brief	Cantidad de filas de la estantería.*/
	int FILAS;
	
	/** @brief	Cantidad de columnas de la estantería.*/
	int COLUMNAS;
	
	/** @brief	Numero máximo de items que puede alojar la estantería */
	int max_items;
	
	/** @brief	Cantidad de items contenida en la estantería.*/
	int actual_items;
	
  
  public:
	
	// Constructora
	
	
	/** @brief	Creadora de Sala asociada a un identificador.
		\pre	El identificador es un entero positivo y diferente de cero.
		\post	El resultado es una sala asociada al identificador <em>id</em> con una estantería vacía y de tamaño cero.
		\coste	Constante.
	*/
	Sala(int id);
	
	
	// Modificadoras
	
	
	/** @brief	Modificadora que añade una cantidad concreta de items a una estantería.
		\pre	La cantidad <em>cant</em> es positiva.
		\post	la estantería contenida en el parámetro implícito ha sido llenada con una cantidad
				<em>cant</em> de productos <em>prod</em> o bien hasta que se ha llenado la estaneria o bien hasta que se haya agotado la susodicha cantidad. El rellenado
				se habra realizado llenando primero los huecos a partir del hueco que fuera antes.
		\coste	Lineal. 
	*/
	void poner_items(const string& prod, int cant);
	
	
	/** @brief	Modificadora que quita una cantidad concreta de items a una estantería.
		\pre	La cantidad <em>cant</em> es positiva.
		\post	A la estantería contenida en el parámetro implícito le ha sido retirada una cantidad <em>cant</em> de productos <em>prod</em> o bien hasta que se ha llenado la estaneria o bien hasta que se haya agotado la susodicha cantidad.
				La acción se habra realizado quitando primero los items que vayan antes.
		\coste	Lineal. 
	*/
	void quitar_items(const string& prod, int cant);
	
	
	/** @brief	Modificadora que compacta todos los elementos de la estantería del parámetro implicito.
		\pre	Cierto.
		\post	Todos los elementos de la estantería del parámetro implícito quedan agrupados (sin espacios vacíos entre ellos) lo mas abajo y a la izquierda posible de la misma y manteniendo el orden previo.
		\coste	Lineal. 
	*/
	void compactar();
	
	/** @brief	Modificadora que ordena alfabeticamente (segun su identificador) todos los elementos de la estantería del parámetro implicito.
		\pre 	Cierto.
		\post 	La estantería del parámetro implicito tiene los items compactados y ordenados alfabeticamente.
		\coste	Logarítmico. 
	*/
	void reorganizar();
	
	/** @brief	Modificadora que, si los items que contiene la estaneria caben en las nuevas dimensiones, modifica las dimensiones de la misma y compacta los items.
		\pre 	Los enteros <em>fil</em> y <em>col</em> son positivos o iguales a 0.
		\post 	Si la cantidad de items cabe en las nuevas dimensiones, la estantería del parámetro implicito queda redimensionada a <em>fil x col</em> y tiene los items compactados.
				Por contra, si la cantidad de items no cabe en las nuevas dimensiones, se produce un error y el parámetro implicito permanece igual.
		\coste	Lineal.
	*/
	bool redimensionar(int fil, int col);
	
	/** @brief	Modificadora que otorga las características espaciales a una estaneria adimensionada.
		\pre 	La estantería del parámetro implicito esta adimensionada.
		\post 	La estaneria del parámetro implicito cuenta con unas dimensiones (filas y columnas) y un tamaño (filas x columnas).
		\coste	Constante.
	*/
	void asignacion_dimensiones_estanteria(int filas, int columnas);
	
	
	// Consultoras
	
	
	/** @brief	Consultora encargada de imprimir por pantalla la estaneria del parámetro implicito.
		\pre 	Cierto.
		\post 	Se ha impreso por pantalla la estaneria del parámetro implicito. En caso de haber un hueco vacío, se ha escrito "NULL".
		\coste	Lineal.
	*/
	void escribir();
	
	
	/** @brief	Consultora que retorna el identificador del item que se encuentra en una posicion concreta.
		\pre 	Cierto.
		\post 	Se ha impreso por pantalla la estaneria del parámetro implicito. En caso de haber un hueco vacío, se ha escrito "NULL".
		\coste	Constante.
	*/
	string consultar_pos(int i, int j);
};
#endif
