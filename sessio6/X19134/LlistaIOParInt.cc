#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l)
{
	list<ParInt>::iterator it;
	
	ParInt p;
	p.llegir();
	
	while (p.primer() != 0 and p.segon() != 0) {
	
		it = l.end();
		l.insert(it, p);
		
		p.llegir();
	}
}
