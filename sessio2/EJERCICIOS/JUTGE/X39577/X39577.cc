#include "Estudiant.hh"
#include <vector>


typedef vector<Estudiant> lista;
typedef vector<double> fila;
typedef vector<fila> matriz;

void lectura_tam_matriz(matriz& m) {
	
	int M, N;
	cin >> M >> N;
	
	m.resize(M, fila(N+1));
	
}

void lectura_asignaturas_seleccionadas(vector<int>& v) {
	
	int S;
	cin >> S;
	
	v.resize(S);
	
	for (int i=0; i<S; ++i) cin >>v[i];
	
}

void lectura_datos(matriz& m){
	
	int I = m.size(), J = m[0].size();
	
	for (int i=0; i<I; ++i) {
		for (int j=0; j<J; ++j) {
			cin >> m[i][j];
		}
	}
}

void generacion_de_lista(const matriz& m, lista& s, const vector<int>& v) {
	
	int nest = m.size(), nasS = v.size();
	
	s.resize(nest);
	
	double nota_aux;
	
	for (int i=0; i<nest; ++i) {
		
		nota_aux = 0;						//reset de la nota auxiliar
		
		s[i] = Estudiant(int(m[i][0]));
		
		for (int k=0; k<nasS; ++k) {		//suma de notas
			nota_aux += m[i][v[k]];
		}
		
		nota_aux = double(nota_aux/nasS);	//calculo de media (division real)
		
		s[i].afegir_nota(nota_aux);			//añadir nota a al estudiante
	}
}

void print_lista(const lista& s) {

	int n = s.size();
	
	for (int i=0; i<n; ++i) s[i].escriure();
	
}

int main() {
	
	matriz m;
	lectura_tam_matriz(m);
	
	vector<int> v;
	lectura_asignaturas_seleccionadas(v);
	
	lectura_datos(m);
	
	lista s;
	generacion_de_lista(m, s, v);
	
	print_lista(s);
	
}
