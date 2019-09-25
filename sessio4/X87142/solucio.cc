#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
	int dni = est.consultar_DNI();
	int pos = cerca_dicot(vest, 0, nest-1, dni);
	
	b = false;
	if (vest[pos].consultar_DNI() == dni) b = true;
	
	if (not b) {
		++nest;
		
		if (est.te_nota() and (imax == -1 or est.consultar_nota() > vest[imax].consultar_nota())) imax = pos;
		else if (imax >= pos) ++imax;
		
		for (int i = nest-1; i>pos; --i) vest[i] = vest[i-1];
		vest[pos] = est;	
		
	}
}

void Cjt_estudiants::eliminar_estudiants_sense_nota()
{
	vector<Estudiant> aux(nest);
	int count = 0;
	for (int i=0; i<nest; ++i) {
		if (vest[i].te_nota()) {
			aux[count] = vest[i];
			++count;
		}
	}
	nest = count;
	for (int i = 0; i<nest; ++i) vest[i] = aux[i];
	recalcular_posicio_imax();
}
