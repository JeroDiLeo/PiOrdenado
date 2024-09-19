/*
Una fila es amiga de otra si todos los elementos de una fila están incluidos en otra. Por ejemplo:
F1= 1 2 2 3 
F2= 0 1 2 3 
F3= 1 2 3 4 
F1 es amiga de F2 pues todos los elementos de F1 están incluidos en F2
F2 no es amiga de F1 pues el número 0 presente en F2 no está incluido en F1
F1 es amiga de F3 pues todos los elementos de F1 están incluidos en F3
F3 no es amiga de F1 porque el número 4 presente en F3 no está incluido en F1

Una matriz es amiga de otra si todas las filas de la primera matriz son amigas de alguna fila de la segunda matriz. Es decir, siendo:

M1 es amiga de M2 pues
la fila 0 1 2 3   de M1 es amiga de la fila 0 1 2 3  de  M2
la fila 4 4 5 6   de M1 es amiga de la fila 4 5 6 8  de  M2
la fila 7 8 8 9   de M1 es amiga de la fila -3 7 8 9  de  M2
M2 no es amiga de M1 pues la fila -3 7 8 9   de M2 no es amiga de ninguna de las filas de  M1
M1 no es amiga de M3 pues la fila 0 1 2 3   de M1 no es amiga de ninguna de las filas de  M3
M3 no es amiga de M1 pues la fila 2 3 3 7   de M3 no es amiga de ninguna de las filas de  M1



Se pide escribir la función sonAmigas que reciba los siguientes parámetros:
m1: la primera matriz de enteros 
fils1: la cantidad de filas de la primera matriz de enteros
m2: la segunda matriz de enteros
fils2: la cantidad de filas de la segunda matriz de enteros

Nota 1: Se cuenta con la constante simbólica COLS que indica la cantidad de columnas de la primera y segunda matriz de enteros.
Nota 2: Todas las filas tienen sus elementos ordenados de manera no descendente (cada elemento es menor o igual al siguiente)


La función debe retornar:
1: si la primera matriz es amiga de la segunda
2: si la segunda matriz es amiga de la primera
0: en cualquier otro caso

Si ambas son amigas, la función puede retornar 1 ó 2.
*/

#define COLS 4

// Nota: ver los comentarios a las funciones "de abajo hacia arriba" (comenzando con sonAmigas y terminando con contieneOrden)
// para entender cuál fue el razonamiento

// La idea es la misma que la interseccion de vectores ordenados, solo que debemos
// verificar que todos los elementos de v1 esten en v2, pero la forma de 
// recorrer los vectores es muy similar a la interseccion
static int contieneOrden(const int v1[], const int v2[], unsigned int dim) {
  int i, j;
  for (i=0, j=0; i < dim && j < dim; ) {
    if ( v1[i] < v2[j] )  // Si es menor, no va a estar despues
      return 0;
    if ( v1[i] == v2[j]) {
      i++; // no incrementamos j, porque puede haber elementos repetidos en v1
    }
    else // v1[i] > v2[j]  -> puede estar mas adelante
      j++;
  }
  // Si llegue al final, quiere decir que todos los elementos estaban
  return i==dim;
}

static int vecEnMatriz(const int v[], const int (m[])[COLS], unsigned int fils) {
  // Debemos ver si v esta contenido dentro de alguna de las filas de m
  // Apenas encontramos que v "pertenece" a m retornamos 1. El razonamiento es
  // muy parecido al de buscar un elemento en un vector
  for(int i=0; i < fils; i++) {
    if ( contieneOrden(v, m[i], COLS))
       return 1;
  }
  return 0;
}

static int esAmiga(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 ) {
  // Verificar que todas las filas de m1 esten en m2
  for(int i=0; i < fils1; i++) {
    if ( ! vecEnMatriz(m1[i], m2, fils2))
      return 0;
  }
  return 1;

}

int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 ) {

  // Como hay que verificar m1 contra m2 y luego m2 contra m1, realizamos una funcion auxiliar que haga todo el trabajo, y la llamamos primero para m1.
  if ( esAmiga(m1, fils1, m2, fils2))
    return 1;   // Si esAmiga no hace falta hacer nada mas
  if ( esAmiga(m2, fils2,m1, fils1))
    return 2;
  return 0;

}