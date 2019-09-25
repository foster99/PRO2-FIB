#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	
	int n, x;
	cin >> n >> x;
	
	vector< stack<string> > gen(n+1);	//utilizare gen[0] como pila auxiliar
							//para la escritura (func. -3)
	int cat, qua;
	string s;
	
	while (x != -4) {
		
		if (x == -1) {		//añade
			cin >> s >> cat;
			gen[cat].push(s);
		}
		
		else if (x == -2) { //elimina
			cin >> qua >> cat;
			for (int i=0; i<qua; ++i) gen[cat].pop();
		}
		
		else if (x == -3) {	//escribe
			
			cin >> cat;
			gen[0] = gen[cat];
			cout << "Pila de la categoria " << cat <<endl;
			
			while (not gen[0].empty()) {
				cout << gen[0].top() << endl;
				gen[0].pop();
			}
			
			cout << endl;
		}
		
		cin >> x;
	}
}
