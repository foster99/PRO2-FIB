#include "BinTreeIOParInt.hh"
#include <iostream>



ParInt search_tree(const BinTree<ParInt>& a, int& elem, int depth) {
	
	ParInt result(-1, -1);
	
	if (not a.empty() and a.value().primer() == elem) {	//nodo que consulto es el correcto
		result = ParInt (a.value().segon(), depth);
	}
	
	else if (not a.empty()) {
		
		BinTree<ParInt> a1(a.left());
		BinTree<ParInt> a2(a.right());
		
		result = search_tree(a1, elem, depth+1);
		if (result.primer() != -1) return result;
		
		result = search_tree(a2, elem, depth+1);
	}
	
	return result;
}


int main() {
	
	BinTree<ParInt> a;
	read_bintree_parint(a);
	
	int element;
	while (cin >> element) {
		
		int depth = 0;
		ParInt resultat = search_tree(a, element, depth);
		
		if (resultat.primer() == -1) cout <<-1 <<endl;
		else cout <<element <<' ' <<resultat.primer() <<' ' <<resultat.segon() <<endl;
	}
}
