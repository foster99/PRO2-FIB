#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c)
{
	ParInt n;
	n.llegir();
	
	while (n.primer() != 0 and n.segon() != 0) {
		c.push(n);
		n.llegir();
	}
}

void escriureCuaParInt(queue<ParInt> c)
{
	queue<ParInt> aux(c);
	while (not aux.empty()) {
		aux.front().escriure();
		aux.pop();
	}
}
