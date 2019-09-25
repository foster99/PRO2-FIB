#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct team {
	int num;
	int points;
	int gf;
	int gc; 
};

typedef pair<int,int> match;
typedef vector< vector<match> > matriz_match;
typedef vector<team> tabla_liga;


void leer_matriz_match(int n, matriz_match& m) {
	
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			cin >> m[i][j].first >> m[i][j].second;
		}
	}
	
}	

void print_tabla(const tabla_liga& t) {
	
	int c = t.size();
	for (int i=0; i<c; ++i){
		cout << t[i].num << ' ' << t[i].points << ' ' << t[i].gf << ' ' << t[i].gc <<endl;
	}
}	

void computo_liga(int n, tabla_liga& t, matriz_match& m){
	
	
	
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (i != j) {	//descartamos diagonal
				
				//asignacion del numero
				t[i].num = i+1;
/*				
				//inicializacion de contadores de puntos/goles
				t[i].points = 0;
				t[i].gf = 0;
				t[i].gc = 0;
				
				t[i].points = 0;
				t[j].gf = 0;
				t[j].gc = 0;
*/				
				//suma de goles
				
				t[i].gf += m[i][j].first; //goles a favor local
				t[i].gc += m[i][j].second;//goles en contra local
				
				t[j].gf += m[i][j].second;//goles a favor visitante
				t[j].gc += m[i][j].first; //goles en contra visitante
				
				//calculo de puntos
				if (m[i][j].first == m[i][j].second) { //empate
					t[i].points += 1;
					t[j].points += 1;
				}
				else if (m[i][j].first > m[i][j].second) t[i].points += 3;	//gana equipo local
				else t[j].points += 3; //gana equipo visitante
			}
		}
	}
}

bool clasificacion(const team& a, const team& b) {

	if (a.points != b.points) { //si no empatan a puntuacion
		return (a.points > b.points); //orden por puntos
	}
	
	if ((a.gf - a.gc) != (b.gf - b.gc)){	//si la d.d.g. es diferente
		return ((a.gf - a.gc) > (b.gf - b.gc)); //orden por d.d.g
	}
	
	return (a.num < b.num);	//orden por nombre (numero)	
}

int main() {
	
	int N;
	cin >>N;
	
	matriz_match m(N, vector<match>(N));
	leer_matriz_match(N, m);
	
	tabla_liga t(N);
	computo_liga(N, t, m);
	
	sort(t.begin(), t.end(), clasificacion);
	
	print_tabla(t);
}
