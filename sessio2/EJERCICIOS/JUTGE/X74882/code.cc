#include "Cjt_estudiants.hh"

void actualizar(Cjt_estudiants& a, const Cjt_estudiants& b) {
	
	int n = a.mida();
	
	for (int i=1; i<=n; ++i) {
		
		Estudiant estA;
		Estudiant estB;
		estA = a.consultar_iessim(i);
		estB = b.consultar_iessim(i);
		
		if (estB.te_nota()){
			
			if (not estA.te_nota())  a.modificar_iessim(i, estB);
			else if (estA.consultar_nota() < estB.consultar_nota()) {
				
				 a.modificar_iessim(i, estB);
			}
		}
	}
	
}


int main() {
	
	Cjt_estudiants a;
	Cjt_estudiants b;
	
	a.llegir();
	b.llegir();
	
	actualizar(a, b);
	
	a.escriure();
	
}
