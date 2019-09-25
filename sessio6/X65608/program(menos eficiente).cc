#include "BinTreeIOEst.hh"

void cerca(const BinTree<Estudiant>& t, const int& dni, int& prof, const int& aux1, double& nota, bool& trobat) {
	
	if (not t.empty()) {
		
		if (t.value().consultar_DNI() == dni) {		//cuando encuentras un nodo con ese dni
			if (not trobat or aux1 < prof) {						//primera vez que encuentra uno
				
				trobat = true;
				prof = aux1;
				if (t.value().te_nota()) nota = t.value().consultar_nota();
				else nota = -1;
			}	
		}

		if (prof != 0) {

			BinTree<Estudiant> e1(t.left());
			cerca(e1, dni, prof, aux1+1, nota, trobat);
			
			BinTree<Estudiant> e2(t.right());
			cerca(e2, dni, prof, aux1+1, nota, trobat);
		}
	}	
}
	


int main() {
	
	BinTree<Estudiant> tree;
	read_bintree_est(tree);
	
	int x, y;	//dni, prof
	double z;	//nota
	bool trobat;
	
	while (cin >> x) {
		
		y = -1;
		trobat = false;
		
		int aux = 0;
		cerca(tree, x, y, aux, z, trobat);
		
		if (not trobat) cout <<x <<" -1" <<endl;
		else cout <<x <<' ' <<y <<' ' <<z <<endl;
		
	}
	
	
}
