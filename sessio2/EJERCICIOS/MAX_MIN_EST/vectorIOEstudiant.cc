#include "vectorIOEstudiant.hh"

/* Leer vector */
void leer_vector_Estudiant(vector<Estudiant>& v) {// version accion
  cout<<"Escribe el tamaño del vector:"<<endl;
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  
  cout<<"Escribe los elementos del vector:"<<endl;  
  for (int i=0; i<numEst;++i)
    cin >> v[i];
}

/* Escribir vector */
void escribir_vector_Estudiant(const vector<Estudiant>& v) {
  for (int i=0; i<v.size();++i)
    cout << v[i] << " ";
  cout << endl;
}
