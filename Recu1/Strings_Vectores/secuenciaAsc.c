/*

Escribir una función secuenciaAsc que reciba un vector de enteros (sin orden) y su dimensión y almacene en dos 
parámetros de salida:
comienzo: Dónde comienza la secuencia de números ordenados en forma ascendente (cada elemento debe ser mayor al 
anterior) de mayor longitud
longitud: Longitud de esa secuencia

En caso de haber más de una secuencia con la mayor longitud debe almacenar en comienzo donde comienza la primera 
de ellas.

Ejemplos:

Para el vector {1, 1, 3, 4, 4, 7, 10, 9, 11} el comienzo es 1 y su longitud es 3

Para el vector vacío comienzo y longitud son 0 (cero)

Para los vectores {3}, {2, 2, 2} y  {3, 2, 1, 0, -1}  el comienzo es 0 y la longitud es 1

Para el vector {1, 2, 3, 4, 5, 7, 10, 90, 111}  el comienzo es 0 y la longitud 9

*/



#include <stdio.h>

void secuenciaAsc(int vector[], int dimension, int *comienzo, int *longitud) {
    if (dimension == 0) {  // Vector vacío
        *comienzo = 0;
        *longitud = 0;
        return;
    }

    int maxComienzo = 0;  // Posición de inicio de la secuencia más larga encontrada
    int maxLongitud = 1;  // Longitud de la secuencia más larga encontrada
    int currentComienzo = 0;  // Posición de inicio de la secuencia actual
    int currentLongitud = 1;  // Longitud de la secuencia actual

    for (int i = 1; i < dimension; i++) {
        if (vector[i] > vector[i - 1]) {
            currentLongitud++;
        } else {
            if (currentLongitud > maxLongitud) {
                maxComienzo = currentComienzo;
                maxLongitud = currentLongitud;
            }
            currentComienzo = i;
            currentLongitud = 1;
        }
    }

    // Verificar si la última secuencia encontrada es la más larga
    if (currentLongitud > maxLongitud) {
        maxComienzo = currentComienzo;
        maxLongitud = currentLongitud;
    }

    *comienzo = maxComienzo;
    *longitud = maxLongitud;
}

int main() {
    int vector1[] = {1, 1, 3, 4, 4, 7, 10, 9, 11};
    int dimension1 = sizeof(vector1) / sizeof(vector1[0]);
    int comienzo1, longitud1;
    secuenciaAsc(vector1, dimension1, &comienzo1, &longitud1);
    printf("Para el vector {1, 1, 3, 4, 4, 7, 10, 9, 11} el comienzo es %d y su longitud es %d\n", comienzo1, longitud1);

    int vector2[] = {};
    int dimension2 = sizeof(vector2) / sizeof(vector2[0]);
    int comienzo2, longitud2;
    secuenciaAsc(vector2, dimension2, &comienzo2, &longitud2);
    printf("Para el vector vacío comienzo y longitud son %d (cero)\n", comienzo2);

    int vector3[] = {3};
    int dimension3 = sizeof(vector3) / sizeof(vector3[0]);
    int comienzo3, longitud3;
    secuenciaAsc(vector3, dimension3, &comienzo3, &longitud3);
    printf("Para el vector {3} el comienzo es %d y la longitud es %d\n", comienzo3, longitud3);

    int vector4[] = {2, 2, 2};
    int dimension4 = sizeof(vector4) / sizeof(vector4[0]);
    int comienzo4, longitud4;
    secuenciaAsc(vector4, dimension4, &comienzo4, &longitud4);
    printf("Para el vector {2, 2, 2} el comienzo es %d y la longitud es %d\n", comienzo4, longitud4);

    int vector5[] = {3, 2, 1, 0, -1};
    int dimension5 = sizeof(vector5) / sizeof(vector5[0]);
    int comienzo5, longitud5;
    secuenciaAsc(vector5, dimension5, &comienzo5, &longitud5);
    printf("Para el vector {3, 2, 1, 0, -1} el comienzo es %d y la longitud es %d\n", comienzo5, longitud5);

    int vector6[] = {1, 2, 3, 4, 5, 7, 10, 90, 111};
    int dimension6 = sizeof(vector6) / sizeof(vector6[0]);
    int comienzo6, longitud6;
    secuenciaAsc(vector6, dimension6, &comienzo6, &longitud6);
    printf("Para el vector {1, 2, 3, 4, 5, 7, 10, 90, 111} el comienzo es %d y la longitud es %d\n", comienzo6, longitud6);

    return 0;
}

