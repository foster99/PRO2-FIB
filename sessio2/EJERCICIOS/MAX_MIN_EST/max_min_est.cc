#include "vectorIOEstudiant.hh"
using namespace std;

typedef pair<int,int> parint;

pair<int,int> max_and_min(const vector<Estudiant>& v) {
	
	parint resultado;
	resultado.first = v[0].consultar_nota();
	resultado.second = v[0].consultar_nota();
	
	int x = v.size();
	for (int i=0; i<x; ++i) {
		if (v[i].consultar_nota() > resultado.first) resultado.first = v[i].consultar_nota();
		else if (v[i].consultar_nota() < resultado.second) resultado.second = v[i].consultar_nota();
	}
	
	return resultado;
}

int main() {
	
	vector<Estudiant> v;
	leer_vector_Estudiant(v);
	
	parint r = max_and_min(v);
	cout << "nota max: " << r.first << " nota min: " << r.second << endl;
}
