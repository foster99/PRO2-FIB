#include "Eines_Vec_Lliu.hh"
#include <algorithm>


// NO PODEU MODIFICAR AQUEST FITXER, PERQUÈ NO
// S'UTILITZARÀ PER AVALUAR EL VOSTRE LLIURAMENT.

// NO PODEIS MODIFICAR ESTE FICHERO, PORQUE NO
// SE UTILIZARA PARA EVALUAR VUESTRA ENTREGA


void emmagatzema(int n_max, vector<Lliurament>& v, int& n_lliu) {
  v = vector<Lliurament>(n_max);
  n_lliu = 0;
  bool ultim = false; 
  while (not ultim and n_lliu < n_max) {
    ultim = not v[n_lliu].llegir();
    if (not ultim) ++n_lliu;
  }
  if (not ultim and n_max != 0) {
    Lliurament e;
    ultim = not e.llegir();
    assert(ultim);
  }
}


void ordena(int n_lliu, vector<Lliurament>& v) {
  assert(n_lliu <= int(v.size()));
  sort(v.begin(), v.begin() + n_lliu, Lliurament::menor_dni_temps);
}


int cerca_bin(int dni_x, const vector<Lliurament>& v, int esq, int dre) {
  assert(dni_x > 0);
  assert(0 <= esq and esq <= int(v.size())); 
  assert(-1 <= dre and dre < int(v.size()));
  assert(esq <= (dre + 1));
  if (esq > dre) return -1;
  int m = (esq + dre)/2;
  if (v[m].consultar_DNI() < dni_x) return cerca_bin(dni_x,v,m+1,dre);
  else if (v[m].consultar_DNI() > dni_x) return cerca_bin(dni_x,v,esq,m-1);
  else {
    while (m > 0 and v[m-1].consultar_DNI() == dni_x) --m;
    return m;
  }
}
  

void escriure(const vector<vector<Lliurament> >& m) {
  for (int i = 0; i < m.size(); ++i) {
    cout << endl << i << " jocs de proves superats" << endl;
    for (int j = 0; j < m[i].size(); ++j) m[i][j].escriure(); 
  }
}

