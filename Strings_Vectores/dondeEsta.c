/*Escribir una función dondeEsta que, dado un arreglo ordenado de números enteros,su dimensión, y un número determinado, 
determine si el número está y en quéposiciones. El arreglo está ordenado en forma creciente y puede tener elementosrepetidos.
Ejemplo:
Vector: 3, 5,5, 5, 5,6, 7, 7, 8, 9, 12,15
Elemento a buscar: 5
Está en posiciones 1,2,3 y 4
*/
int dondeEsta(int vec[], int n, int val, int pos[]){
    int i, j = 0;
    for (i = 0; i < n && vec[i]<val; i++)
        ;
    for (; i < n && vec[i]==val; i++){
        pos[j++] = i;
    }
    
    return j;
}
