#include "Estudiant.hh"
#include <vector>

// Pre: secuencia no vacia de estudiantes. estudiantes repetidos, pero consecutivamente
// Post: impresion de secuencia de estudiantes sin repetirse (nota mas alta)

typedef vector<Estudiant> lista;

void leer_lista(lista& e) {
	//nº de elementos de la secuencia
	int N;		
	cin >>N;
	
	//asignamos tamaño a la lista
	e.resize(N);
	
	//lectura del canal de entrada n veces.
	for (int i=0; i<N; ++i) e[i].llegir();	
}

void tratamiento(const lista& e, lista& s) {
	
	s.push_back(Estudiant());
	s[0] = e[0];	//primer estudiante lo copiamos
	
	int N = e.size();
	for (int i=1; i<N; ++i) {
		
		int k = s.size()-1;
		
		if (s[k].consultar_DNI() == e[i].consultar_DNI()) {	//Dnis coinciden
			
			//si el dato que entra tiene nota, 2 opciones:
			//	- el de salida tambien tiene nota: compáralas
			//  - el de salida NO tiene nota: añade la nota del de entrada
			
			if (e[i].te_nota()) {
				
				if (s[k].te_nota()) { 
					//ambos tienen nota, si la de entrada es mayor, la cambiamos por esa
					if (s[k].consultar_nota() < e[i].consultar_nota()) {
						s[k].modificar_nota(e[i].consultar_nota());
					}
				}
				
				//si el de salida no tiene nota, añadimos la de entrada
				else s[k].afegir_nota(e[i].consultar_nota());
			}
			
			//en caso de que el estudiante de entrada no tenga nota, no hace falta realizar modificaciones
		}
		
		else {
			s.push_back(Estudiant());
			k = s.size()-1;
			s[k] = e[i];
		}
	}
	
}

void print_lista(const lista& s) {
	
	int N = s.size();
	for (int i=0; i<N; ++i)	s[i].escriure();

}

int main() {
	
	//lectura de lista de entrada
	lista e;
	leer_lista(e);
	
	//escritura de lista de salida tras tratamiento de la lista de entrada
	lista s;
	tratamiento(e, s);
	
	//impresion en pantalla de la lista de salida
	print_lista(s);
	
}
