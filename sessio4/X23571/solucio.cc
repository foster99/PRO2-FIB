#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
	
	for (int i = primer_est_amb_nota; i<nest; ++i) {
		if (vest[i].consultar_nota() >= nota_b) return i;
	}
	return nest;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat)
{
	int pos = cerca_lineal_per_dni(vest, 0, nest - 1, est.consultar_DNI());
	
	trobat = false;
	if (est.consultar_DNI() == vest[pos].consultar_DNI()) trobat = true;
		
	if (not trobat) {
		
		if (not est.te_nota()) ++primer_est_amb_nota;
		
		++nest;
		vest[nest-1] = est;
		ordenar();
	}
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const
{
	int i = posicio_nota(nota_i);
	while(i < nest and vest[i].consultar_nota() <= nota_s) {
		vest[i].escriure();
		++i;
	}
}
