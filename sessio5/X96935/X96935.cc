#include <iostream>
#include <stack>
using namespace std;

int main() {
	
	stack<int> s;
	
	int n;
	cin >> n;
	
	int aux, i=0;
	
	while (i<(n/2)) {	//lectura de media secuencia
		cin >> aux;
		s.push(aux);
		++i;
	}
	
	if (n%2 == 1) {	//si la secuncia es impar, ignoramos el elemento central
		cin >> aux;
		++i;
	}
	
	bool control = true;
	
	while (control and i<n) { //comparamos la otra mitad con la que tenemos en el stack
		
		cin >> aux;
		if (aux != s.top()) control = false;
		
		s.pop();	
		++i;
	}
	
	if (control) cout << "SI" << endl ;
	else cout << "NO" << endl ;
}
