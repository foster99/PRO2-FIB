/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
node_llista* copia_node_llista_it (node_llista* m, node_llista* oact,
         node_llista* &u, node_llista* &a)
{
	if (m == NULL)
	{
		a = NULL;
		u = NULL;
		return NULL;
	}
	else
	{
		node_llista* resultat;
		node_llista* aux1;
		node_llista* aux2;
		resultat = new node_llista;
		resultat->info = m->info;
		resultat->ant = NULL;
		
		aux1 = resultat;
		m = m->seg;
		a = NULL;

		while (m != NULL)
		{
			if (oact == m) a = oact;
			
			aux2 = new node_llista;
			aux2->info = m->info;
			aux2->ant = aux1;
			
			aux1->seg = aux2;
			aux1 = aux2;
			
			m = m->seg;
		}
		
		aux1->seg = NULL;
		u = aux1;
		
		return resultat; 
	}
	
	
	
}


    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
Llista& operator=(const Llista& original) 
{
	if (this != &original)
	{
		node_llista* m;
		node_llista* aux;
		m = primer_node;
		
		while (m != NULL)
		{
			aux = m->seg;
			delete m;
			m = aux;
		}
		
		this->longitud = original.longitud;
		this->primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
	}
	return *this;
}
