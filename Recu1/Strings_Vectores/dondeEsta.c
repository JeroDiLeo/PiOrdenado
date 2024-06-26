/*Escribir una función dondeEsta que, dado un arreglo ordenado de números enteros,su dimensión, y un número determinado, 
determine si el número está y en quéposiciones. El arreglo está ordenado en forma creciente y puede tener elementosrepetidos.
Ejemplo:
Vector: 3, 5,5, 5, 5,6, 7, 7, 8, 9, 12,15
Elemento a buscar: 5
Está en posiciones 1,2,3 y 4
*/

#include <stdio.h>
#define N 12
int dondeEsta(int vec[], int dim, int num, int pos[]){
    int cont=0;
    for(int i=0; i<dim && vec[i]<=num; i++){    
        if(vec[i]==num){
            pos[cont]=i;    //guardo la posicion en el vector de posiciones
            cont++;       //aumento el contador de posiciones o apariciones
        }
    }
    return cont;            //devuelvo la cantidad de apariciones
}











