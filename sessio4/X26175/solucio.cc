#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
	int d = est.consultar_DNI();
	b = false;
	int pos = cerca_dicot(vest, 0, nest-1, d);
	
	if (vest[pos].consultar_DNI() == d) b = true;
	
	if (not b) {
		
		for (int i=nest; i>pos; --i) vest[i] = vest[i-1];
		vest[pos] = est;
		++nest;
	
		if (est.te_nota()) incrementar_interval(est.consultar_nota());

	}
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */
{
	b = false;
	int pos = cerca_dicot(vest, 0, nest-1, dni);
	
	if (vest[pos].consultar_DNI() == dni) b = true;
	
	if (b) {
		
		if (vest[pos].te_nota()) decrementar_interval(vest[pos].consultar_nota());
		for (int i=pos; i<nest-1; ++i) vest[i] = vest[i+1];
		--nest;
	
	}
}
