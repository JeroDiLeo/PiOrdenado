/*Escribir la función interseccion que recibe dos arreglos y sus dimensiones y obtiene en un tercer arreglo la intersección de los dos primeros. 
Asumir que losarreglos no están ordenados, y que no hay elementos repetidos dentro del mismoarreglo.
¿Conviene que la función retorne algún valor?
Ejemplo:
● Vector A: 7,9,3,5,15
● Vector B: 5,6,7,9,8
● Intersección: 7,9,5 */
int interseccion(const int v1[], int dim1, const int v2[], int dim2, int res[]){
    int dimRes=0;
    for(int i = 0; i < dim1; i++){
        int encontrado = 0;
        
        for(int j = 0; j < dim2 && !encontrado; j++){
            if(v1[i] == v2[j]){
                encontrado = 1;
            }
        }
        
        if(encontrado){
            res[dimRes++] = v1[i];
        }
    }
    return dimRes;
}
//---------------------------------------------------------------------------------------------------------
/*Version Modularizada*/

int belongs(int v1[], int DIM, int elem){
    for(int i=0; i<DIM;i++){
        if(v1[]==elem){
            return 1;
        }
    }
    return 0;
}

int interseccion(const int v1[],int DIM1, const int v2[], int DIM2, int v3[]){
    int dim3=0;
    for(int i=0; i<DIM1; i++){
        if(belongs(v2,DIM2,v1[i])){
            v3[DIM3++]==v1[i];

        }
    }
    return DIM3;
}








//---------------------------------------------------------------------------------------------------------
/*Reescribir la función anterior para el caso de que los arreglos estén ordenados enforma creciente.
Ejemplo:
● Vector A: 3,5,7,9,15
● Vector B: 5,6,7,8,9
● Intersección: 5,7,9
*/
int interseccion(const int v1[], int dim1, const int v2[], int dim2, int res[]){
    int i, j, dimRes;
    i = j = dimRes = 0;
    while (i < dim1 && j < dim2){
        if (v1[i] < v2[j]){
            i++;
        } 
        else if (v1[i] > v2[j]){
            j++;
        } 
        else {
            res[dimRes++] = v1[i++];
            j++;
        }
    }
    return dimRes;
}