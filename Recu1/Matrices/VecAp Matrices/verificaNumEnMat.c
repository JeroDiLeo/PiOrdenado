/*
Escribir una función que reciba dos matrices cuadradas de enteros de dimensión DIM (DIM es una constante 
previamente definida) y determine si entre las dos matrices contienen todos los números entre 1 y 2 * N * N 
inclusive, sin repetir. En caso de cumplir con esa condición debe retornar 1, de lo contrario retorna 0 (cero).
Ejemplos:

Si N es 4, se debe cumplir que entre las dos matrices tengan los números
entre 1 y 32, por ejemplo si recibe las dos matrices siguientes retorna 1 (colocamos los números con cierto orden 
para que se vea más claro, pero podrían estar en cualquier otro orden)


 1  2  3  4
20 19 18 17
 9 10 11 12
21 22 23 24


 8  7  6  5
29 30 31 32
25 26 27 28
13 14 15 16



Si N es 4 y recibe las siguientes matrices retorna 0 (el 33 no debe estar):


 1  2  3  4
20 33 18 17
 9 10 11 12
21 22 23 24


 8  7  6  5 
29 30 31 32 
25 26 27 28 
13 14 15 16


Si N es 4 y recibe las siguientes matrices retorna 0 (falta el 19 y se repite el 5):


 1  2  3  4
20  5 18 17
 9 10 11 12
21 22 23 24


 8  7  6  5
29 30 31 32
25 26 27 28
13 14 15 16

Si N es 1, una de las matrices debe contener el 1 y la otra el 2
*/
#define DIM 4
#define CONDICION (2*DIM*DIM)

int cumpleRequisitos(int m1[][DIM],int m2[][DIM]){
    int vecAp[CONDICION]={0};
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            int num1=m1[i][j];
            int num2=m2[i][j];

            if(vecAp[num1-1]>1||vecAp[num2-1]>1){   //Si esta repetido
                return 0;
            }            
            if(num1>CONDICION || num2>CONDICION){
                return 0;
            }
            else{
                vecAp[num1-1]++;
                vecAp[num2-1]++;
            }
        }
    }
    // Verificar que todos los números aparezcan exactamente una vez
    for (int i = 0; i < CONDICION; i++) {
        if (vecAp[i] != 1) {
            return 0;
        }
    }
    
    return 1;
}



int verifica(int m1[][DIM],int m2[][DIM]){
    return cumpleRequisitos;
}
