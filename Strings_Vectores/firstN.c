/*Escribir la función firstN que recibe un vector de unsigned chars, su
dimensión y un valor entero no negativo n. La función debe dejar en el vector las
primeras n apariciones de cada valor y devolver en dos parámetros de salida:
● la dimensión del nuevo vector
● cuántos elementos eliminó

Ejemplo de uso:
int main(void) {
unsigned char v[] = {1, 2, 1, 3, 1, 4, 5, 2};
int dim, del;
firstN(v, 8, 3, &dim, &del); // dim es 8, del es 0, v no cambia
firstN(v, 8, 8, &dim, &del); // dim es 8, del es 0, v no cambia
firstN(v, 8, 4, &dim, &del); // dim es 8, del es 0, v no cambia
firstN(v, 8, 1, &dim, &del); // dim=5, del=3, v = {1, 2, 3, 4, 5};
unsigned char w[] = {1, 2, 1, 3, 1, 4, 5, 2};
firstN(w, 8, 0, &dim, &del); // dim=0, del=8, w = {}
unsigned char t[] = {1, 2, 1, 3, 1, 4, 5, 2};
firstN(t, 8, 2, &dim, &del); // dim=7, del=1, t = {1, 2, 1, 3, 4, 5, 2}
return 0;
}
*/
#define MAX 256
#include <assert.h>
#include <stdio.h>

void firstN(unsigned char v[], int dim, unsigned int N, int *newDim, int *del){
  
  // Si N es cero hay que eliminar todo
  if(N<=0){
    *del = dim;
    *newDim = 0;
    return;
  } 
  
  // Si N es mayor o igual a dim no se va a poder borrar nada
  if(N>=dim){ 
    *newDim = dim;
    *del=0;
    return;
  }
 
  unsigned char aux[MAX] = {0};
  int j=0;
  
  for(int i=0 ; i<dim ; i++){
    if(aux[v[i]] < N){  
      aux[v[i]]++;
      v[j++] = v[i]; 
    }
  }
  *newDim = j;
  *del = dim - j;
}
