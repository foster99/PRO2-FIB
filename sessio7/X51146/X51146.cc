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

void elimina(apuntados& ori, apuntados& vag, const apuntados& lis) {
	
	apuntados::iterator it1 = ori.begin();
	apuntados::iterator it2 = lis.begin();
	apuntados::iterator it3 = vag.begin();

	bool control  = (it2 == lis.end());
	
	while (it1 != ori.end() and it3 != vag.end() and not control) {
		
		control  = (it2 == lis.end());
		
		if (*it2 == *it3) it3 = vag.erase(it3);
		
		if (not control and *it2 != *it1) {
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
	cin >> n;
	
	for (int i=0; i<n; ++i) {
		
		read_names(entrada);
		elimina(original, vagos, entrada);
		
		entrada.clear();
	}
	
	cout << "Totes les activitats:";
	print(original);
	
	cout << "Cap activitat:";
	print(vagos);
	
}
