#include <set>
#include <iostream>
using namespace std;

typedef set<string> apuntados;

void read_names(apuntados& S) {
	
	string s;
	cin >> s;
	
	while (s != ".") { 
		S.insert(s);
		cin >> s;
	}
	
}

void elimina(apuntados& ori, const apuntados& lis) {
	
	apuntados::iterator it1 = ori.begin();
	apuntados::iterator it2 = lis.begin();
	bool control  = false;
	
	while (it1 != ori.end() and not control) {
		
		if (it2 == lis.end()) control = true;
		
		else if (*it2 != *it1) {
			it1 = ori.erase(it1);
		}
		else {
			++it1;
			++it2;
		}
	}
	
	if (control) 
	  while (it1 != ori.end()) it1 = ori.erase(it1);
	
}

void print(const apuntados& A) {
	
	apuntados::const_iterator it;
	if (A.empty()) cout <<' ';
	for (it = A.begin(); it != A.end(); ++it) cout <<' ' << *it;
	cout <<endl;
}

int main() {
	
	apuntados original;
	read_names(original);
	
	apuntados vagos(original);
	apuntados entrada;
	
	int n;
	string s;
	
	cin >> n;
	
	for (int i=0; i<n; ++i) {
		
		
		cin >> s;
		while (s != ".") { 
			vagos.erase(s);
			entrada.insert(s);
			cin >> s;
		}
		
		elimina(original, entrada);
		entrada.clear();
	}
	
	cout << "Totes les activitats:";
	print(original);
	
	cout << "Cap activitat:";
	print(vagos);
	
}
