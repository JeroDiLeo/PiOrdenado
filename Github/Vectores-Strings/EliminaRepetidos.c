// Retorna 1 si el elemento esta en el vector, cero sino
int pertenece(const int v[], int dim, int elem) {
    for(int i=0; i<dim; i++)
        if ( v[i] == elem)
            return 1;
    return 0;
}

int eliminaRepetidos( const int original[], int dimOrig, int resultado[]) {
	int dimResult=0;

	/* Para cada elemento del vector original recorrer los elementos ya
	** insertados en el vector final, si no estaba entonces agregarlo.
 	*/
	for (int i = 0; i < dimOrig; i++) {
		if (!pertenece(resultado, dimResult, original[i])) {
			resultado[dimResult++] = original[i];
		}
	}
	return dimResult;
}