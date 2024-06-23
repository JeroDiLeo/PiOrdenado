/* Dada una matriz cuadrada de dimensión M -donde M es una constante simbólica par
mayor a cero previamente definida (por ejemplo 2, 4, 6, etc.)-, se desea calcular la suma de
cada uno de sus bordes. Se considera como un borde a un contorno de la matriz.
El primer borde estaría conformado por la primer y última fila junto a la primer y
última columna, el segundo borde por la segunda y anteúltima fila junto a la segunda y
anteúltima columna, y continuando así hasta llegar al centro de la matriz, formado por un
cuadrado de 2x2.
Ejemplo: Con M = 6, la siguiente matriz tiene 3 bordes, el primero formado por
números 1, el segundo por números 2 y el tercero por números 3.
1 1 1 1 1 1
1 2 2 2 2 1
1 2 3 3 2 1
1 2 3 3 2 1
1 2 2 2 2 1
1 1 1 1 1 1
Escribir la función bordes que reciba:
● una matriz mat de enteros de dimensión M (no se debe validar que M sea par positivo,
asumir que cumple con esa condición)
● un vector sumas de enteros no inicializado con al menos M/2 posiciones reservadas
La función debe dejar en sumas[i] la suma del borde i, para todo i en [0, M/2).
En el ejemplo anterior el vector sumas debe quedar con los valores { 20, 24, 12 },
ya que el primer borde está formado por 20 celdas con el valor 1, el segundo borde por 12
celdas con el valor 2 y el tercer borde (el centro) por 4 celdas con el valor 3.
Si M = 4 y se recibe la siguiente matriz:
-2 2 -2 2
4 1 2 -4
0 1 2 0
-2 -2 2 2
en el vector sumas se deben dejar los valores { 0, 6 }
Si M = 2 y se recibe la siguiente matriz:
1 2
3 3
en el vector sumas se debe dejar el valor { 9 }
*/


#define M 4





//Primera forma: suma filas y columnas siempre con un elemento menos para evitar sumar esquinas dos veces.
static int sumarBorde(int mat[M][M], int b){
    int suma = 0;
    //Cada fila o columna del borde se suma sin el último elemento
    //para evitar sumar las esquinas dos veces.
    for(int i = b; i < M - b - 1;i++){
        suma+= mat[b][i] + mat[i][M - b - 1];//primera fila, última columna
        suma+= mat[M - b - 1][i + 1] + mat[i + 1][b];//última fila //primera columna
    }
    return suma;
}
void bordes(int mat[M][M], int sumas[] ){
    for(int i=0; i < M/2;i++){
        sumas[i]=sumarBorde(mat,i);
    }
}




/***************************************************************************************/
//Segunda forma suma las columnas completas, y las filas las suma sin los extremos.
int sumaCols(int m[][M], int borde){
  int suma=0;
  for(int i=borde; i < M-borde; i++ ){
    suma += m[i][borde];  // Suma elementos de la columna izquierda del borde
    suma += m[i][M-1-borde];  // Suma elementos de la columna derecha del borde
  }
  return suma;
}
int sumaFilas( int m[][M], int borde){
  int suma=0;
  for(int i=borde+1; i< M-borde-1; i++){    
//desde borde +1 hasta M-borde -1 por los extremos
     suma += m[borde][i];       // Suma elementos de la fila superior del borde
     suma += m[M-1-borde][i];   // Suma elementos de la fila inferior del borde
  }
  return suma;
}
 
int sumBorde(const int m[][M], int borde){
  int suma=0;
  suma += sumaFilas(m, borde);
  suma += sumaCols(m, borde);
  return suma;
} 

void bordes(int mat[][M], int sumas[]){
  for(int i=0; i<M/2 ; i++){
    sumas[i]=sumBorde(mat, i);  // Calcula y guarda la suma del borde i en sumas[i]
  }
}


/***************************************************************************************/
//Tercera forma: suma las filas superior e inferior completas, y si son otra fila sólo suma las puntas.



static int sumaFila(int fila[], int b){
    int suma = 0;
    for(int j = b; j < M - b; j++)
            suma+= fila[j];
    return suma;
}
static int sumarBorde(int mat[M][M], int b){
    int suma = 0;
    for(int i = b; i < M - b; i++){
        if (i == b || i == M - b - 1)//bordes inferior y superior
            suma+= sumaFila(mat[i], b);
        else
            suma+= mat[i][b] + mat[i][M - b - 1];//bordes izquierdo y derecho
    }
    return suma;
}
void bordes(int mat[M][M], int sumas[] ){
    for(int i=0; i < M/2;i++){
        sumas[i]=sumarBorde(mat,i);
    }
}




