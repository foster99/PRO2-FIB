#ifndef LLIURAMENT_HH
#define LLIURAMENT_HH


#include <cassert>
#include <vector>
using namespace std;

// NO PODEU MODIFICAR AQUEST FITXER, PERQUÈ NO
// S'UTILITZARÀ PER AVALUAR EL VOSTRE LLIURAMENT.

// NO PODEIS MODIFICAR ESTE FICHERO, PORQUE NO
// SE UTILIZARA PARA EVALUAR VUESTRA ENTREGA


class Lliurament {

  // Tipus de mòdul: dades
  // Descripció del tipus: conté un lliurament d'un estudiant. 


private:    
  int dni; // DNI de l'estudiant
  vector<bool> jps; // Resultats de l'avaluació del lliurament a cadascun
  // dels jocs de proves (true significa 'superat', i false 'no superat')
  int n_verds; // Nombre de jocs de proves superats
  int temps; // Temps de lliurament, i.e. nombre de segons transcorreguts des del començament de l'examen
  static const int NJPS = 4; // Nombre de jocs de proves
  /* 
     Invariant de la representació: 
     1) 0 <= dni
     2) jps.size() = NJPS
     3) 0 <= n_verds <= NJPS
     4) n_verds = int(jps[0]) + ... + int(jps[NPJS - 1])
     5) Per tot j en {0,..., NPJS - 1}  jps[j] = true o jps[j] = false
     6) temps >= 0 
  */


  
public:


  // Constructors

  Lliurament();
  /* Pre: cert */ 
  /* Post: el resultat és un lliurament d'un estudiant amb DNI = 0, que no ha 
    superat cap joc de proves, i amb temps de lliurament 0. */


  
  // Modificadors   
  
  void modificar_jp(int i, bool v); 
  /* Pre: 1 <= i <= nombre_jps() */
  /* Post: El resultat de l'avaluació del joc de proves i-èsim del p.i. és ara. v. */



  // Consultors

  bool consultar_jp(int i) const;
  /* Pre: 1 <= i <= nombre_jps() */
  /* Post: Retorna el resultat de l'avaluació del joc de proves i-èsim del p.i. */

  int consultar_DNI() const;
  /* Pre: cert  */
  /* Post: El resultat és el DNI de l'estudiant que ha fet el lliurament del p.i. */

  int consultar_temps() const;
  /* Pre: cert */
  /* Post: El resultat és el temps de lliurament del p.i. */

  int superats() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre de jocs de proves que ha superat el p.i. */

  static int nombre_jps();
  /* Pre: cert */
  /* Post: El resultat és el nombre de jocs de proves del p.i. */
  
  static bool menor_dni_temps(const Lliurament& e1, const Lliurament& e2); 
  /* Pre: cert  */
  /* Post: Retorna true a algun dels casos següents: 1) el número de DNI de l'estudiant 
   que ha lliurat e1 és més petit que el número de DNI de l'estudiant que ha lliurat e2; 
   2) e1 i e2 han estat lliurats pel mateix estudiant, però el temps de 
   lliurament de e1 és més petit que el temps de lliurament de e2. En altres casos, 
   retorna false.*/
  
  static bool millor(const Lliurament& e1, const Lliurament& e2);
  /* Pre: e1 i e2 han estat lliurats pel mateix estudiant.  */
  /* Post: Retorna true a algun dels casos següents: 1) e1 ha superat més 
   jocs de proves que e2; 2) e1 i e2 han superat el mateix nombre de jocs de 
   proves, i el temps de lliurament de e1 és més gran que el temps de lliurament 
   de e2. En altres casos, retorna false. */


  
  // Lectura i escriptura

  bool llegir();
  /* Pre: Hi ha preparat al canal estàndard d'entrada un enter no negatiu x. 
     Si x > 0, també hi ha preparats al canal d'entrada nombre_jps() enters 
     que representen els resultats d'avaluar un lliurament en cadascun dels 
     jocs de proves (1 si el joc de proves s'ha superat, i 0 en un altre cas), 
     i un enter positiu correspondent al temps de lliurament. */
  /* Post: Si x == 0, el resultat és false. En un altre cas, el resultat és true,  
     i el paràmetre implícit té els atributs llegits del canal d'entrada estàndard. */

  void escriure() const;
  /* Pre: cert */
  /* Post: S'han escrit els atributs del paràmetre implícit al canal
     estàndard de sortida. */
};

#endif
