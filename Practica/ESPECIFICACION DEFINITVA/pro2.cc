/** @mainpage

    El programa principal se encuentra en el módulo pro2.cc.
	
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos dos
	módulos: un módulo para representar el almacén y otro para representar una
	sala.
	
	La simulacion se plantea como un almacén contenedor de un conjunto de salas 
	y un registro de productos global (incluido en el almacén).

    

*/

/** @file pro2.cc

    @brief Programa principal

    El programa incluye, para una serie de datos incorrectos específicos, un detector de error.
    Esto implica que si el usuario intenta realizar ciertas operaciones que no cumplan unas determinadas
    condiciones (como por ejemplo introducir productos no registrados) el programa informará de la
    existencia de un error.
    
    Pese a lo previamente citado, suponemos que el usuario introduce datos correctos relativos al acceso a
    salas ya que no hay control respecto a si accedemos a salas inexistentes o se introducen cantidades negativas.
*/

#include "Almacen.hh"

int main() {

	int N;								// Cantidad de salas.
	cin >> N;
	
	Almacen A(N);						// Creación y lectura en preorden de la estructura del almacén (con identificadores de sala).
	
	A.lectura_dimensiones_salas();		// Lectura de las dimensiones de cada una de las salas.
	
	string op;							// Código de operación.
	
	while (cin >> op and op != "fin") {
		
		cout << op;
		
		if (op == "poner_prod") {
			string prod;
			cin >> prod;
			
			cout <<' ' << prod << endl;
			A.poner_prod(prod);
		}
		else if (op == "quitar_prod") {
			string prod;
			cin >> prod;
			
			cout <<' ' << prod << endl;
			A.quitar_prod(prod);
		}
		else if (op == "poner_items") {
			int sala, cant;
			string prod;
			cin >> sala >> prod >> cant;
			
			cout <<' ' << sala << prod << cant << endl;
			
			int result = A.poner_items(sala, prod, cant);
			if (result == -1) cout << "  error" << endl;
			else cout <<"  " << result << endl;
		}
		else if (op == "quitar_items") {
			int sala, cant;
			string prod;
			cin >> sala >> prod >> cant;
			
			cout <<' ' << sala << prod << cant << endl;
			
			int result = A.quitar_items(sala, prod, cant);
			if (result == -1) cout << "  error" << endl;
			else cout <<"  " << result << endl;
			
		}
		else if (op == "distribuir") {
			int cant;
			string prod;
			cin >> prod >> cant;
			
			cout <<' ' << prod << cant << endl;
			
			int result = A.distribuir(prod, cant);
			if (result == -1) cout << "  error" << endl;
			else cout <<"  " << result << endl;
			
		}
		else if (op == "compactar") {
			int sala;
			cin >> sala;
			
			cout <<' ' << sala << endl;
			A.compactar(sala);
		}
		else if (op == "reorganizar") {
			int sala;
			cin >> sala;
			
			cout <<' ' << sala << endl;
			A.reorganizar(sala);
		}
		else if (op == "redimensionar") {
			int sala, fil, col;
			cin >> sala >> fil >>col;
			
			cout <<' ' << sala << fil << col << endl;
			if (not A.redimensionar(sala, fil, col)) cout << "  error" << endl;
		}
		else if (op == "inventario") {
			
			A.inventario();
		}
		else if (op == "escribir") {
			int sala;
			cin >> sala;
			
			cout <<' ' << sala << endl;
			A.escribir(sala);
		}
		else if (op == "consultar_pos") {
			int sala, fil, col;
			cin >> sala >> fil >>col;
			
			cout <<' ' << sala << fil << col << endl;
			cout <<"  " << A.consultar_pos(sala, fil, col) << endl;
		}
		else if (op == "consultar_prod") {
			string prod;
			cin >> prod;
			
			cout <<' ' << prod << endl;
			int result = A.consultar_prod(prod);
			
			if (result == -1) cout << "  error" << endl;
			else cout <<"  " << result << endl;
		}
	}
	
	cout << op << endl;
}
