#include "Estudiant.hh"

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
  //amb_nota = false;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  this->dni = dni;
  //amb_nota = false;
}

Estudiant::Estudiant(const Estudiant& est)
{
	dni = est.dni;
	nota = est.nota;
	
}  
  
Estudiant::~Estudiant(){}

void Estudiant::afegir_nota(double nota)
{
  if (this->nota != -1) 
    throw PRO2Excepcio(ER3);
  if (nota<0 or nota>MAX_NOTA) {
    throw PRO2Excepcio(ER2); 
    this->nota = -1; 
  }
  else this->nota = nota; 
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (nota == -1) 
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA) {
    throw PRO2Excepcio(ER2);
    this->nota = -1;
  }
  else this->nota = nota;
}

bool Estudiant::te_nota() const
{
  return (nota != -1);
}

double Estudiant::consultar_nota() const
{
  if (nota == -1) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

void Estudiant::llegir()
{
  cin >> dni;
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
  }
  else nota = -1;
}

void Estudiant::escriure() const
{
  if (nota != -1)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}
