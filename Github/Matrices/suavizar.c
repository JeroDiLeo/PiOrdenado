/*
Una imagen bmp se almacena en un archivo como una matriz de píxeles.
Si la imagen es de escala de grises, cada píxel ocupa un solo byte. 
Así, si la imagen tiene 20x30 píxeles, ocupa 600 bytes donde un byte con el valor 0x00 corresponde al negro y un byte con el valor 0xFF corresponde al blanco.
Cualquier valor entre 0x00 y 0xFF será una tonalidad de gris.

Realizar una función suavizar que, dada una imagen, la suavice aplicando un filtro de media de valor W, con W impar.
Esto significa que cada píxel (i, j) de la nueva imagen se obtiene a partir de la media aritmética de los píxeles que se encuentran en la imagen original de la submatriz de tamaño WxW centrada en (i,j).
La función suavizar recibe como únicos parámetros la matriz y W. Si W es menor que 3 o no es impar, la función no altera la imagen. 
El ancho y alto de la imagen son las constantes simbólicas ANCHO y ALTO respectivamente.
*/




#define ALTO 6
#define ANCHO 5

#define MIN(x,y)  ((x) < (y) ? (x) : (y))
#define MAX(x,y)  ((x) > (y) ? (x) : (y))

// Asumimos w es al menos 1
// Al ser una funcion auxiliar, ya sabemos que los parametros son validos
static int promedio(unsigned char m[ALTO][ANCHO], int i, int j, int w ) {
   int sum = 0, cant = 0;
   for ( int i2 = MAX(0,i-w); i2 <= MIN(ALTO-1,i+w); i2++ ) {
       for ( int j2 = MAX(0,j-w); j2 <= MIN(ANCHO-1,j+w); j2++ ) {
         cant++;
         sum += m[i2][j2];
       }
   }
   // cant no puede ser cero
   return sum / cant;
}

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w ) {
  if ( w < 3 || w % 2 == 0)
    return;
  // Debemos definir una matriz auxiliar, no se puede hacer sobre la misma matriz
  unsigned char aux[ALTO][ANCHO];

  for (int i=0; i < ALTO; i++) {
    for (int j=0; j < ANCHO; j++)
      aux[i][j] = promedio(imagen, i, j, w / 2);
  }

  // Ahora copiamos la auxiliar a la original
  for (int i=0; i < ALTO; i++) {
    for (int j=0; j < ANCHO; j++)
      imagen[i][j] = aux[i][j];
  }