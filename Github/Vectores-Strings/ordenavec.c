/*
 Escribir la función ordena que recibe un vector de enteros donde cada
 elemento es mayor o igual a cero,y el valor -1 como marca de final.La función debe
 dejar en el vector únicamente los elementos que son mayores que el anterior,
 considerando que el primer elemento debe quedar en el vector.
*/

//---------------------------CHEQUEADO---------------------------------
#include <stdio.h>
#include <assert.h>
#define FIN -1


// Función que modifica el vector para que solo queden los elementos mayores que el anterior
int ordena(int vec[]) {
    int k = 1;  // 'k' indica la posición para el siguiente elemento válido
    int current = vec[0];  // Mantiene el valor del último elemento agregado al vector
    
    // Empezamos desde el segundo elemento
    for (int i = 1; vec[i] != FIN; i++) {
        if (vec[i] > current) {  // Si el elemento actual es mayor que el último agregado
            vec[k++] = vec[i];  // Agregar al vector
            current = vec[i];  // Actualizar el último valor agregado
        }
    }
    vec[k] = FIN;  // Marcamos el final del vector
    
    return k;  // Devolvemos el número de elementos válidos
}

