#include <iostream>
using namespace std;

int main() {
	int max; cin >> max;
	for (int i=1; i<=max; ++i) {
		
		int dni = i*100;
		double nota = i/2.0 + i/10.0;
		
		if (nota > 10) nota /= 10;
		cout << dni <<' ' << nota <<endl;
	}
}
