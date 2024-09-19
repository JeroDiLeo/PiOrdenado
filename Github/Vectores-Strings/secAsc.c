/*
secuenciaASC recibe un vector de enteros(desordenados) y su dim.
Almacena en dos parametros de salida:
-Comienzo:Donde comienza la secuencia de numeros ordenados en forma ascendente
            (Cada elemento debe ser mayor al anterior) de mayor longitud
-Longitud: Longitud de esa secuencia

En caso de haber mas de una secuencia con la mayor longitud debe almacenar en comienzo donde comienzan la primera de ellas

Pensamiento:
    comienzo recibe vec[i]
preguntar como hacer lo de comienzo, no se me ocurre nada


*/

#include <stdio.h>

void secuenciaAsc(int v[],unsigned int dim, int comienzo, int longitud){
    int anterior=v[0];
    comienzo=0;
    longitud=1;
    int maxLongitud=1;
    for(int i=1;i<dim;i++){

        if(anterior<v[i]){
            anterior=v[i];
            longitud++
        }else{
            if(maxLongitud<longitud){
                maxlongitud=longitud;
                comienzo=i;
            }
            longitud=1;
            
        }

    }
}