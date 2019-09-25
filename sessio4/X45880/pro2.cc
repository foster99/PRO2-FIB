#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include "Eines_Vec_Lliu.hh"
using namespace std;


// NO PODEU MODIFICAR AQUEST FITXER, PERQUÈ NO
// S'UTILITZARÀ PER AVALUAR EL VOSTRE LLIURAMENT.

// NO PODEIS MODIFICAR ESTE FICHERO, PORQUE NO
// SE UTILIZARA PARA EVALUAR VUESTRA ENTREGA


const int MAX_ENV = 30; // Màxim nombre de lliuraments per estudiant


typedef vector<vector<Lliurament> > Classificacio; 


int main() {
  int n; // Nombre d'estudiants
  cin >> n;
  int n_max = n*MAX_ENV; // Màxim nombre de lliuraments de la seqüència
  vector<Lliurament> v;
  int n_lliu; 
  emmagatzema(n_max, v, n_lliu);
  ordena(n_lliu, v);
  cout << endl << n_lliu << " LLIURAMENTS REBUTS" << endl << endl;
  for (int i = 0; i < n_lliu; ++i) v[i].escriure();
  bool primer = false;
  Classificacio c;
  string opcio;
  cin >> opcio; 
  while (opcio != "fi") {
    assert(opcio == "consultar" or opcio == "classificar"); 
    if (opcio == "classificar") {
       if (not primer) {
	  c = Classificacio(Lliurament::nombre_jps() + 1);
	  classifica(n_lliu, v, c);
	  primer = true;
       }
       cout << endl << "CLASSIFICACIO" << endl;
       escriure(c);
    }
    else if (opcio == "consultar") {
      int dni_x;
      cin >> dni_x;
      assert(dni_x > 0); 
      int pos = cerca_bin(dni_x, v, 0, n_lliu - 1); 
      if (pos != -1) {
	cout << endl << "LLIURAMENTS DE " << dni_x << endl;
	while (pos < n_lliu and v[pos].consultar_DNI() == dni_x) {
	  v[pos].escriure();
	  ++pos;
	}
      }
      else cout << endl << "NO HI HA LLIURAMENTS DE " << dni_x << endl;
    }
    cin >> opcio;
  }
}
