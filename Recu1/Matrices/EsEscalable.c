/*Se dice que una matriz de números enteros es "escalable" si para cada fila (excepto la primera) la suma de sus
elementos es igual a 1 + la suma de los elementos de la fila anterior, y para cada columna (excepto la primera)
se cumple que la suma de sus elementos es igual a la suma de la columna anterior + 1.
Escribir una función que reciba una matriz de enteros y retorne 1 si es escalable y 0 sinó. Agregar los
parámetros que sean necesarios.*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#define COL 3

int isScal(const int mat[][COL], size_t fil);



int main(){

  int fil = 4;

 const int m1[][COL] = {{1,1,1},
                         {1,1,2},
                         {1,2,2},
                         {2,2,2}};

  assert(isScal(m1, fil) == 1);
  
 const int m2[][COL] = {{1,1,1},
                         {1,3,2},
                         {1,2,2},
                         {2,2,2}};

  assert(isScal(m2, fil) == 0);

   const int m3[][COL] = {{1,1,1},
                         {'a',1,2},
                         {1,2,2},
                         {2,2,2}};

  assert(isScal(m3, fil) == 0);

   puts("OK!");
}

int isScal(const int mat[][COL], size_t fil){


  int modelo = 0;
  int sumFil = 0;
  int sumCol = 0;

  //fila
  for (int i=0; i<fil; i++){
    for (int j=0; j<COL; j++){          
      if (!i)                       //Si i es 0 sumo los elementos de la primera fila
        modelo += mat[i][j];          
      else
        sumFil += mat[i][j];        //Si i es distinto de 0 sumo los elementos de la fila
    }
  
    if (i && modelo+i != sumFil )       // si la suma de los elementos de la fila no coincide con la progresión aritmética esperada. 
      return 0;
    
    sumFil = 0;
    
  }

  modelo=0;

  //columna
  for (int i=0; i<COL; i++){
    for (int j=0; j<fil; j++){
      if (!i)
        modelo += mat[j][i];
      else
        sumCol += mat[j][i]; 
    }
  
    if (i && modelo+i != sumCol )
      return 0;
    
    sumCol = 0;
    
  }

  return 1;

}