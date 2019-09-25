#include "Cjt_estudiants.hh"


/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
	int dni = est.consultar_DNI();
	int posicion = cerca_dicot(vest, 0, nest-1, dni);
	
	b = false;
	if (vest[posicion].consultar_DNI() == dni) b = true;	//este estudiante ya existe en el conjunto
	
	if (not b) {	//añadir estudiante nuevo
		
		++nest;
		
		for (int i=nest-1; i>posicion; --i) vest[i] = vest[i-1];
		vest[posicion] = est;
		
		if (est.te_nota()) {
			if (nest_amb_nota == 0) suma_notes = est.consultar_nota();
			else suma_notes += est.consultar_nota();			
			++nest_amb_nota;	
		}
	}
}


/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */


void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
	b = false;
	int posicion = cerca_dicot(vest, 0, nest-1, dni);
	if (vest[posicion].consultar_DNI() == dni) b = true;
	
	if (b) {
		
		if (vest[posicion].te_nota()) {
			--nest_amb_nota;
			suma_notes -= vest[posicion].consultar_nota();
		}
		
		for (int i = posicion; i<nest-1; ++i) vest[i] = vest[i+1];
		--nest;
	}
}

