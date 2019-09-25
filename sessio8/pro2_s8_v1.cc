/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{
	
	Lavadora L;
	Cubeta C;
	
	int op;
	cin >> op;
	
	while (op != -8) {
		
		if (op == -1) {
			int pmax;
			cin >> pmax;
			cout << "   Lavadora: " <<endl;
			L.inicializar(pmax, readbool());
		}
		else if (op == -2) {
			int pes;
			cin >> pes;
			cout << "   Lavadora: " <<endl;
			C.anadir_prenda(Prenda (pes, readbool()));
		}
		else if (op == -3) {
			int pes;
			cin >> pes;
			cout << "   Cubeta:" <<endl;
			C.anadir_prenda(Prenda (pes, readbool()));
		}
		else if (op == -4) {
			cout << "   Lavadora: " <<endl;
			C.completar_lavadora(L);
		}
		else if (op == -5) {
			cout << "   Lavadora: " <<endl;
			L.lavado();
		}	
		else if (op == -6) {
			cout << "   Cubeta:" <<endl;
			C.escribir();
		}
		else if (op == -7) {
			cout << "   Lavadora: " <<endl;
			L.escribir();
		}
		
		cin >> op;
	}
}
