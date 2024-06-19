/*
Escribir una función que, dada una matriz de enteros de N filas y M columnas, arme los números que se
forman con cada fila y retorne cuál es el máximo. Para poder armar un número con los elementos de una fila,
todos sus elementos deben contener un número entero entre 0 y 9 inclusive.
Si hubiera números negativos o de más de una cifra, no se completa el armado del número.
Si no se pudo armar ningún número, retorna -1.
Ejemplos

Dada la siguiente matriz, la función retorna -1
16 3 2 13
5 10 11 8
9  6 7 12
4 15 14 1

Dada la siguiente matriz, retorna 9672
1 3 2 5
5 0 1 8
9 6 7 2
4 5 4 1

Dada la siguiente matriz, retorna 4541
1 3  2 5
5 4 11 8
9 6 -7 2
4 5  4 1
*/

int verifica(int mat[][M]){
	if(mat == NULL|| N<=0 || M<=0){
		return -1;
	}
	int aux = armaFila(mat, 0);	 	//inicializo aux con el primer numero de la matriz o -1 si no se puede armar(Me sirve para ir comparando con los demas)
	for(int i=1; i<N; i++){
		int suma = armaFila(mat, i); 
		if(aux<suma){				//Si el nuevo numero es mayor que el que tenia, lo reescribo. Sino mantengo
			aux = suma;
		}
	}

	return aux;

}

int armaFila(int mat[][M], size_t fila){

	int numero = 0;

	for(int i = 0; i<M; i++){
		if( mat[fila][i]<0 || mat[fila][i]>9){
			return -1;
		}
		numero = (numero*10 + mat[fila][i]);

	}

	return numero;
}
