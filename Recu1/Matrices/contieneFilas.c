/*Escribir una función contieneFilas que reciba dos matrices de enteros de NxN, donde N es una constante previamente definida.
Se dice que una fila A está contenida en la fila B si todos los elementos de A (sin importar el orden y repetición) están en la fila B. 
Por ejemplo la fila {1,3,1,4} está contenida en la fila {2,3,4,1}, la fila {1,1,1,1} está contenida en la fila {3,1,4,5}
Se dice que una fila A está contenida en una matriz M si la fila A está contenida en alguna de las filas de M.
Se dice que una matriz M1 está contenida en la matriz M2 si todas las filas de M1 están contenidas en M2.
La función debe retornar:
●	1 si la primera matriz está contenida en la segunda
●	2 si la segunda matriz está contenida en la primera matriz
●	0 si no se cumple ninguna de las condiciones anteriores

Ejemplos:
Si N es 4 y las matrices son las siguientes

1	1	2	3
3	3	3	3
9	8	1	2
1	8	1	8

1	8	9	2
1	3	2	4
7	7	7	7
4	5	65	7

Debe retornar 1, ya que tanto la fila 0 como la fila 1 están contenidas en la fila 1 de la segunda matriz, la 
fila 2 está contenida en la fila 0 y la fila 3 también está contenida en la fila cero.
*/



#include <stdio.h>
#define N 4

int contieneFilas(const int m1[][N], const int m2[][N]);
int aux(const int m1[][N], const int m2[][N], size_t fila);

int contieneFilas(const int m1[][N], const int m2[][N]){
    int contTotal = 0;
    int contm1 = 0;
    int contm2 = 0;
    for(int i = 0; i < N; i++){
        contm1 += aux(m1, m2, i);
        contm2 += aux(m2,m1,i);
    }
    if(contm1 == N){ //LA MATRIZ 1 ESTA CONTENIDA EN LA 2
        contTotal=1;
    }
    if(contm2 == N){
        contTotal=2;
    }
    return contTotal;
}

//MI FUNCION AUXILIAR ES LA QUE CHEQUEA UNA FILA CON TODA LA OTRA MATRIZ, Y LUEGO LA LLAMO CON LOS PARAMETROS AL REVES
//DEVUELVE 0 SI LA MATRIZ NO ESTA INCLUIDA
//DEVUELVE 1 SI LA MATRIZ ESTA INCLUIDA

int aux(const int m1[][N], const int m2[][N], size_t fila){
    int cont;
    for(int i = 0; i < N; i++){ //este es el for que se mueven entre las filas de m2
        cont = 0;
        for(int j = 0; j < N; j++){ //este es el for que se mueve entre los numeros del vector de m1
            for(int k = 0; k < N; k++){ //este es el for que se mueve entre los numeros del vector de m2
                if(m1[fila][j] == m2[i][k]){
                    cont++;
                }
            }
        if(cont == N)
            return 1;
        }
    }
    return 0;
}



int main(){
    int m1[][N] = {{1,1,2,3},{3,3,3,3},{9,8,1,2},{1,8,1,0}};
    int m2[][N] = {{1,8,9,2},{1,3,2,4},{7,7,7,7},{4,5,65,7}};
    printf("%d\n", contieneFilas(m1,m2));
    return 0;
}



