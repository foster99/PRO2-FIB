#include "Cjt_estudiants.hh"

void Cjt_estudiants::recalcular_pos_max_no_becat() {
	
  	//creamos un estudiante auxilar para realizar comparaciones con las
  	//peores caracteristicas (pero validas) para tener nota
	Estudiant potencial(0);
	potencial.afegir_nota(5);
	
	int pos = -1;		//posicion a retornar como i_max_no_becat
						//el -1 controla si existe un estudiante becario potencial
	
	for (int i=0; i<nest; ++i) {
		
		Estudiant aux = vest[i];
		
		if (not aux.te_beca() and aux.te_nota()) {	//estudiante no becado. si tiene nota, y esta es >=5, es un estudiante becario en potencia
			
			// mejor = true si el estudiante es mejor candidato (buscamos la mejor nota de los no becarios (empate: mirar DNI))
			bool mejor = ((aux.consultar_nota() > potencial.consultar_nota()) or ((aux.consultar_nota() == potencial.consultar_nota()) and (aux.consultar_DNI() > potencial.consultar_DNI())));
			
			if (mejor) {
				potencial = aux;
				pos = i;
			}
		}
	}
	
	if (pos != -1) i_max_no_becat = pos;
	else i_max_no_becat = -1;
	
}

void Cjt_estudiants::esborrar_estudiant(int x, bool& trobat) {
	
	trobat = false;
	int pos = cerca_dicot(vest, 0, nest-1, x);
	
	if (vest[pos].consultar_DNI() == x) trobat = true;
	
	if (trobat) {
		
		bool cambiar_imaxbeca = false;
		
		if (vest[pos].te_nota()) {
		
			if (vest[pos].te_beca()) { // tiene beca
				
				if (i_max_no_becat != -1) {
					
					vest[i_max_no_becat].modificar_beca(true);
					cambiar_imaxbeca = true;	//habra que recalcular la posicion
				}
				
				else --n_bec;
			}
			
			//no tiene beca, pero el mejor candidato a el: recalcular
			else if (i_max_no_becat == pos)	cambiar_imaxbeca = true;
		}
		
		
		for (int i=pos; i<nest-1;++i) vest[i] = vest[i+1];
		--nest;	
		
		if (cambiar_imaxbeca) recalcular_pos_max_no_becat();
		else if (i_max_no_becat > pos) --i_max_no_becat;		//Obs: si i_max... es == -1, tampoco hace el cambio
	}
}
