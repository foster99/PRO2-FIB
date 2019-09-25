/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; en cas contrari, el
   resultat apunta al primer node d'una cadena de nodes que són
   còpia de de la cadena que té el node apuntat per m com a primer */
node_pila* copia_node_pila_it(node_pila* m)
{
	node_pila* copia;
	node_pila* ultimo;
	
	if (m != NULL)
	{
		copia = ultimo = new node_pila;

		ultimo->info = m->info;
		m = m->seguent;
		
		while (m != NULL)
		{
			ultimo->seguent = new node_pila;
			ultimo = ultimo->seguent;
			ultimo->info = m->info;
			m = m->seguent;
		}
		
		ultimo->seguent = NULL;

	}
	else copia = NULL;
	
	return copia;
}



/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
   contingut anterior del p.i. ha estat esborrat (excepte si el
   p.i. i original ja eren el mateix objecte) */ 
Pila& operator=(const Pila& original) 
{
	if (this != &original)
	{
		altura = original.altura;
		esborra_node_pila(primer_node);
		primer_node = copia_node_pila_it(original.primer_node);
	}
	return *this;
}
  
