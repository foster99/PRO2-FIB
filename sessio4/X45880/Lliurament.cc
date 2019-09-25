#include <iostream>
#include "Lliurament.hh"

// NO PODEU MODIFICAR AQUEST FITXER, PERQUÈ NO
// S'UTILITZARÀ PER AVALUAR EL VOSTRE LLIURAMENT.

// NO PODEIS MODIFICAR ESTE FICHERO, PORQUE NO
// SE UTILIZARA PARA EVALUAR VUESTRA ENTREGA


Lliurament::Lliurament() {
  dni = 0;
  temps = 0;
  n_verds = 0;
  jps = vector<bool>(NJPS,false);
}


void Lliurament::modificar_jp(int i, bool v) {
  assert(1 <= i and i <= NJPS);
  if (jps[i-1] and not v) n_verds--;
  else if (not jps[i-1] and v) n_verds++; 
  jps[i-1] = v;
}


bool Lliurament::consultar_jp(int i) const {
  assert(1 <= i and i <= NJPS);
  return jps[i-1];
}


int Lliurament::consultar_DNI() const {
  return dni;
}


int Lliurament::consultar_temps() const {
  return temps;
}


int Lliurament::superats() const {
  return n_verds;
}


int Lliurament::nombre_jps() {
  return NJPS;
}


bool Lliurament::menor_dni_temps(const Lliurament& e1, const Lliurament& e2) {
  if (e1.dni != e2.dni) return e1.dni < e2.dni;
  return e1.temps < e2.temps;
}


bool Lliurament::llegir() {
  cin >> dni;
  if (dni == 0) return false;
  assert(dni > 0);
  n_verds = 0;
  jps = vector<bool>(NJPS);
  for (int i = 0; i < NJPS; ++i) {
    int v;
    cin >> v;
    assert(v == 0 or v == 1);
    if (v != 0) {
      jps[i] = true;
      n_verds++;
    }
    else jps[i] = false;
  }
  cin >> temps;
  assert(temps > 0);
  return true;
}


void Lliurament::escriure() const {
  cout << "DNI " << dni << ": [";  
  for (int i = 0; i < NJPS; ++i) {
    if (i != 0) cout << ","; 
    cout << jps[i];
  }
  cout << "]; " << " temps: " << temps << endl;
}
