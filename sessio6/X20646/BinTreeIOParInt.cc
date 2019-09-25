#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a)
{
	
	ParInt p;
	p.llegir();
	
	ParInt marca(0,0);
	
	if (p.primer() != marca.primer() and p.segon() != marca.segon()) {
		
		BinTree<ParInt> l;		//lee todo lo de la izquierda
		read_bintree_parint(l);
		BinTree<ParInt> r;		//lee todo lo de la derecha, de abajo arriba
		read_bintree_parint(r);
		
		a = BinTree<ParInt>(p, l, r);	//raiz, sub-arbol izquierdo, sub-arbol derecho.
	}
	
}

/*void write_bintree_parint(const BinTree<ParInt>& a)
{
	
	
	
	
	
}
*/
