#ifndef EINES_VEC_LLIU_HH
#define EINES_VEC_LLIU_HH

#include <iostream>
#include <cassert>
#include <vector>
#include "Lliurament.hh" 
using namespace std;


// NO PODEU MODIFICAR AQUEST FITXER, PERQUÈ NO
// S'UTILITZARÀ PER AVALUAR EL VOSTRE LLIURAMENT.

// NO PODEIS MODIFICAR ESTE FICHERO, PORQUE NO
// SE UTILIZARA PARA EVALUAR VUESTRA ENTREGA



// -----------------------------------------------
  // Tipus de mòdul: funcional
  // Descripció: Conté funcions per realitzar diferents operacions amb 
  // vectors d'objectes de tipus Lliurament. 
// -----------------------------------------------



void emmagatzema(int n_max, vector<Lliurament>& v, int& n_lliu);
  /* Pre: Hi ha preparat al canal estàndar d'entrada una seqüència de 
     lliuraments acabada en 0. n_max és el màxim nombre de lliuraments 
     que pot contenir la seqüència.*/
  /* Post: S'han llegit els lliuraments de la seqüència. v.size() = n_max. 
     n_lliu és el nombre de lliuraments que contenia la seqüència. 
     Les posicions v[0, ..., n_lliu - 1] del vector v contenen els 
     lliuraments de la seqüència en l'ordre d'entrada. */


void ordena(int n_lliu, vector<Lliurament>& v);
  /* Pre: 0 <= n_lliu <= v.size() */
  /* Post: Les posicions v[0, ..., n_lliu - 1] del vector v estan ordenades 
     en ordre creixent per número de DNI. Les del mateix DNI estan ordenades 
     en ordre creixent per temps de lliurament. */


int cerca_bin(int dni_x, const vector<Lliurament>& v, int esq, int dre); 
  /* Pre: v.size() > 0, v[esq, ..., dre] està ordenat en ordre creixent per 
     número de DNI, i en el cas de lliuraments del mateix DNI en ordre 
     creixent per temps de lliurament.  
     0 <= esq <= v.size(), -1 <= dre < v.size(), esq <= dre + 1 */
  /* Post: Si a vest[esq, ..., dre] hi ha un lliurament amb número de DNI dni_x,
     el resultat és la posició que ocupa a v el primer lliurament amb número de 
     DNI dni_x; si no, el resultat és -1. */


void escriure(const vector<vector<Lliurament> >& m);
  /* Pre: m és una matriu la fila i-èsima de la qual conté lliuraments que 
     han superat i jocs de proves. */
  /* Post: S'han escrit pel canal estàndard de sortida els lliuraments de m.  
     Per cada fila de m s'especifica el nombre de jocs de proves superats. */


void classifica(int n_lliu, const vector<Lliurament>& v, vector<vector<Lliurament> >& m);
  /* Pre: 0 <= n_lliu <= v.size(), v[0 ... n_lliu -1] està ordenat en ordre 
     creixent per número de DNI i, en cas d'empat, per temps de lliurament. 
     m = M, M.size() = 1 + Lliurament::nombre_jps() i M[j].size() = 0 per a tot j */
  /* Post: Per cada x tal que v[0, ..., n_lliu - 1] conté com a mínim un 
     lliurament amb DNI = x, m conté el millor lliurament amb DNI = x de 
     v[0, ..., n_lliu - 1]. El millor lliurament d'un estudiant és el que 
     supera més jocs de proves i, en cas d'empat, el que té el temps de 
     lliurament més gran. 
     La matriu m no conté més d'un lliurament amb el mateix DNI. A més,  
     els lliuraments de m estan organitzats de la manera següent: 1) cada 
     fila k només conté lliuraments que superen exactament k jocs de proves; 
     2) dins d'una fila concreta, els lliuraments estan ordenats en ordre 
     creixent per número de DNI. */

#endif
