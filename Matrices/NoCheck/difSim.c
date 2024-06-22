/*
Dados dos conjuntos A y B, su diferencia simétrica, A Δ B, es un conjunto que contiene los elementos de A y los de B, excepto los que son comunes a ambos:

Se define: A Δ B = {x/x ∈ (A ∪ B) ∧ x ∉ (A ∩ B)}

Ejemplo: Sean A = {1, 2, 3, 4} y B = {3, 4, 5, 6, 7} entonces 
A Δ B = {1, 2, 5, 6, 7}

Para este ejercicio se debe asumir que los conjuntos contienen únicamente números positivos sin repetir y ordenados 
ascendentemente, con el valor -1 como marca de final.
Como trabajaremos con varios conjuntos, los mismos se almacenan en una "matriz".

Se pide: escribir la función difSim que reciba:

tres matrices enteras m1, m2 y m3 de COLS columnas (COLS es una constante simbólica previamente definida). Cada 
fila i de m1 y m2 contendrá un conjunto de enteros mayor o igual a cero, ordenados ascendentemente y sin repetir, 
con el valor -1 como marca de final
un valor entero filas que representa la cantidad de conjuntos en cada matriz

La función deberá dejar en cada fila i de m3 la diferencia simétrica entre las filas i de m1 y de m2, con 
i ∈ [0, filas)


Ejemplo, asumiendo que COLS es igual a 5 y filas es 6:


m1:
 1  2  3  4 -1
 3  4  5 -1
10 15 20 -1
-1
-1
 5  6  7 -1


m2:
 3  4  5 6 -1
 3  4  5 -1
10 20 -1
 1  2  3 4 -1
-1
 1  2  7 -1




el resultado (m3) deberá ser

 1 2 5 6 -1
-1
15 -1
 1 2 3 4 -1
-1
 1 2 5 6 -1

Se asegura que todas las diferencias simétricas a calcular entrarán en la fila correspondiente (no se debe validar)

*/

#define COLS 5

void difSim(int m1[][COLS],int m2[][COLS],int m3[][COLS],int filas){ 
    for(int i=0;i<filas,i++){
        int j=0,t=0,k=0;
        while(m1[i][j]!=-1||m2[i][k]!=-1){

            if(m1[i][j]>m2[i][k]|| m1[i][j]==-1){
                m3[i][t++]=m2[i][k];
                k++;        //Tengo que avanzar el mas chico
            }

            else if(m1[i][j]<m2[i][k]||m2[i][k]==-1){   //si llego al final de la seg matriz o m1 es mas chico copio m1
                m3[i][t++]=m1[i][j];
                j++;        //Avanzo el mas chico
            }

            else{
                //No copio nada y avanzo los dos
                j++;
                k++;
            }
        }
        m3[i][t]=-1;
    }
}