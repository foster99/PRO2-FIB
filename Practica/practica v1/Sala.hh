/** @file Sala.hh
    @brief Especificación de la clase Sala
*/

#ifndef SALA_HH
#define SALA_HH


#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#include <algorythm>
#endif

/*
 * Clase Sala
 */

/** @class Sala
	@brief Representa una sala virtual que contiene una estanteria.
	
	Ofrece operaciones para modificar el contenido de la sala: las estanterías.
*/

class Sala {
	
  private:
	
	/** @brief Estanteria contenida */
	vector< vector<string> > Estanteria;
	
	/** @brief Identificador de la sala */
	int id;
	
  
  public:
	
	// Constructora
	
	/** @brief Creadora con identificador
		\pre cierto
		\post El resultado es una sala con el identificador <em>id</em> y con una estantería vacía (de tamaño 0x0).
		\coste Constante
	*/
	Sala(int id);
	
	
	// Modificadoras
	
	/** @brief Modificadora del identificador
		\pre cierto
		\post El parámetro implícito pasa a tener a <em>id</em> como identificador
		\coste Constante 
	*/
	void ejemplo(clase xd);
	 
	/**
};
#endif
