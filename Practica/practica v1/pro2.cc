/** @mainpage

    Ejemplo de práctica resuelta, con documentación <b> completa</b>
    (incluyendo elementos privados y código).

    El programa principal se encuentra en el módulo pro2.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
    módulo para representar el Sistema en el que se desarrollarán los
    experimentos, otro para el tipo Organismo y otro para el tipo 
    Celula.

    Comentarios:

    - En una resolución normal, comenzaríamos por considerar las operaciones
    necesarias para el programa principal y las clasificaríamos en los
    diferentes módulos. Al pasar a su implementación, quizá descubriésemos que
    algún módulo necesita alguna operación adicional y la incorporaríamos en
    ese momento (sólo si es pública, es decir, si se usa en un módulo distinto
    al que pertenece). Sin embargo, en un documento de estas características,
    se presentan los módulos completamente acabados, sin necesidad de reflejar
    el proceso que ha dado lugar a su especificación final.

    - En cuanto a los diagramas modulares que aparecen en este proyecto, notad
    que la relación de uso entre Organismo y Celula no se obtiene a partir de
    la especificación de los elementos públicos del primero, sino de la de sus
    elementos privados.

*/

/** @file pro2.cc

    @brief Programa principal

    Estamos suponiendo que los datos leídos siempre son correctos, ya que
    no incluímos comprobaciones al respecto. Por último, puesto que los datos de
    los organismos y células son naturales (identificadores, ...) usaremos números
    negativos para las opciones.
*/

#include "Almacen.hh"

int main() {
	
	lectura_almacen();		//lectura de la estructura del almacen
	
	string op;			//codigo de operacion
	
	while (cin >> op and op != "fin") {
		
		cout << op;
		
		if (op == "poner_prod") {
			string prod;
			cin >> prod;
			
			poner_prod(prod);
		}
		else if (op == "quitar_prod") {
			string prod;
			cin >> prod;
			
			quitar_prod(prod);
		}
		else if (op == "poner_items") {
			int sala, cant;
			string prod;
			cin >> sala >> prod >> cant;
			
			poner_items(sala, prod, cant);
		}
		else if (op == "quitar_items") {
			int sala, cant;
			string prod;
			cin >> sala >> prod >> cant;
			
			quitar_items(sala, prod, cant);
		}
		else if (op == "distribuir") {	//hay que modificar la interpretacion
			int cant;
			string prod;
			cin >> prod >> cant;
			
			distribuir(prod, cant);
		}
		else if (op == "compactar") {
			int sala;
			cin >> sala;
			
			compactar(sala);
		}
		else if (op == "reorganizar") {
			int sala;
			cin >> sala;
			
			reorganizar(sala);
		}
		else if (op == "redimensionar") {
			int sala, fil, col;
			cin >> sala >> fil >>col;
			
			redimensionar(sala, fil, col);
		}
		else if (op == "inventario") {
			
			inventario();
		}
		else if (op == "escribir") {
			int sala;
			cin >> sala;
			
			escribir(sala);
		}
		else if (op == "consultar_pos") {
			int sala, fil, col;
			cin >> sala >> fil >>col;
			
			consultar_pos(sala, fil, col);
		}
		else if (op == "consultar_prod") {
			string prod;
			cin >> prod;
			
			consultar_prod
		}
	}
	
	cout << op << endl;
}
