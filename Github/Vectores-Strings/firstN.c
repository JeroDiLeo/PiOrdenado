/*
Escribir la funcion firstN que recibe un vector de unsigned chars, su dim y un valor entero no negativo N
La funcion debe dejar en el vector las primeras N apariciones de cada valor
Y devolver en dos parametros de salida:
-la dim del nuevo vector
-cuantos elementos elimino
*/
//--------------------------CHEQUEADO(Javi)-------------------------------
#include <stdio.h>
#define MAX 256

void firstN(unsigned char v[],unsigned int dim, unsigned int N,unsigned int *newDim, unsigned int *del){
    unsigned char vecAp[MAX]={0};
    *newDim=0;
    for(int i=0;i<dim;i++){
        if(vecAp[v[i]]<N){      
            v[(*newDim)++]=v[i];    //Copio el valor al "nuevo vector" y aumento el tamano del mismo
            vecAp[v[i]]++;          //Incremento el conteo de apariciones de ese valor
        }
    }
    *del=(dim-(*newDim));
    
}

//Tambien podria haber ido incrementando *del si habia que eliminar dicho caracter
