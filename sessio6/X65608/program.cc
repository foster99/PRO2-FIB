#include "BinTreeIOEst.hh"

void cerca(const BinTree<Estudiant>& t, const int& dni, int& prof, const int& aux1, double& nota) {
	
	if (not t.empty()) {
		
		if (t.value().consultar_DNI() == dni) {		//cuando encuentras un nodo con ese dni
			if (prof == -1 or aux1 < prof) {						//primera vez que encuentra uno
				
				prof = aux1;
				if (t.value().te_nota()) nota = t.value().consultar_nota();
				else nota = -1;
			}	
		}

		if (prof != 0) {	//si no está en la raiz del arbol principal

			BinTree<Estudiant> e1(t.left());
			cerca(e1, dni, prof, aux1+1, nota);
			
			BinTree<Estudiant> e2(t.right());
			cerca(e2, dni, prof, aux1+1, nota);
		}
	}	
}
	


int main() {
	
	BinTree<Estudiant> tree;
	read_bintree_est(tree);
	
	int x, y;	//dni, prof
	double z;	//nota
	
	while (cin >> x) {
		
		y = -1;
		
		int aux = 0;
		cerca(tree, x, y, aux, z);
		
		if (y == -1) cout <<x <<" -1" <<endl;
		else cout <<x <<' ' <<y <<' ' <<z <<endl;
		
	}
	
	
}
