#include "LlistaIOEstudiant.hh"

int main() {
	
	list<Estudiant> l;
	LlegirLlistaEstudiant(l);
	
	int dni, count = 0;
	cin >> dni;
	
	list<Estudiant>::const_iterator it;
	
	for (it=l.begin(); it != l.end(); ++it) {
		if ((*it).consultar_DNI() == dni) ++count;
	}
	
	cout << dni <<' ' << count <<endl;
}
