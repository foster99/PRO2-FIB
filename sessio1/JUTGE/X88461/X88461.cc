#include "vectorIOint.hh"

typedef pair<int,int> parint;

pair<int,int> max_and_min(const vector<int>& v) {
	
	parint resultado;
	resultado.first = v[0];
	resultado.second = v[0];
	
	for (int i=0; i<v.size(); ++i) {
		if (v[i] > resultado.first) resultado.first = v[i];
		else if (v[i] < resultado.second) resultado.second = v[i];
	}
	
	return resultado;
}

int main() {
	
	vector<int> v;
	leer_vector_int(v);
	
	parint r = max_and_min(v);
	cout << r.first << ' ' << r.second << endl;
}
