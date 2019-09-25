#include "BinTree.hh"
#include "Estudiant.hh"

void read_bintree_est(BinTree<Estudiant>& a)
// Pre: a és buit; el canal estandar d’entrada conté una seqüència
// de parells <int, double> que representa un arbre binari d’estudiants 
// en preordre, on un parell amb l’int = ‘‘marca’’ representa 
// un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada
{
	
	Estudiant est;
	est.llegir();
	
	if (est.consultar_DNI() != 0 and (not est.te_nota() or (est.te_nota() and est.consultar_nota() != 0))) {
				
		BinTree<Estudiant> l;
		read_bintree_est(l);
		
		BinTree<Estudiant> r;
		read_bintree_est(r);
		
		a = BinTree<Estudiant> (est, l, r);
					
	}
}





//void write_bintree_est(const BinTree<Estudiant>& a);
// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorreguts en inordre, a = A
