#include "LlistaIOParInt.hh"

int main() {
	
	list<ParInt> l;
	LlegirLlistaParInt(l);
	
	int N, count = 0, suma = 0;
	cin >> N;
	
	list<ParInt>::const_iterator it;
	
	for (it=l.begin(); it != l.end(); ++it) {
		if ((*it).primer() == N) {
			
			suma += (*it).segon();
			++count;
		}
	}
	
	cout << N <<' ' << count <<' ' << suma <<endl;
}
