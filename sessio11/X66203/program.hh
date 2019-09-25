public:

/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */

T maxim() const
{
	return max(primer_node);
}

private:

T max(node_arbreNari* m) const
{	
	int maximo = m->info;
	for (int i=0; i<N; ++i)
	{
		if (m->seg[i] != NULL)
		{
			int aux = max(m->seg[i]);
			if(aux > maximo) maximo = aux;
		}
	}
	return maximo;
}
