#ifndef CLASS_LlistaIOParInt_HH
#define  CLASS_LlistaIOParInt_HH

#include "ParInt.hh"
#include <list>


void LlegirLlistaParInt(list<ParInt>& l);
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)



#endif
