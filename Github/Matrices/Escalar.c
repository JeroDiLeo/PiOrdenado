/*Se dice que una matriz de enteros de dimensión NxN es escalar si se cumple que:
a) A lo sumo dos filas coinciden en la suma de sus elementos
b) Todas las sumas están entre N y 2*N inclusive
Escribir la función escalar que reciba los siguientes parámetros:
● dim: la dimensión de la matriz
● m: la matriz de dim x dim
y retorne 1 si es escalar y 0 si no lo es*/
#define ERROR -1
#define MAX 2
int escalar(unsigned int dim,int m[][dim]){
    int sumaDeFila;
    int vecSumas[dim]={0};
    int indice;

    for(int i=0;i<dim;i++){
        sumaDeFila=sumaFila(m[i],dim);
        if(sumaDeFila<dim ||sumaDeFila >(2*dim)){
            return 0;
        }else{
            indice=sumaDeFila-dim;
            vecSumas[indice]++;
            if(vecSumas[indice]>MAX){
                return 0;
            }
        }

    }
    return 1;

}

int sumaFila(int fila[],unsigned int dim){
    int suma=0;
    for(int i=0;i<dim;i++){
        suma+=fila[i];
    }
    return suma;
}



/*
preguntar que tanto afecta la eficiencia de recursos
hacer un vecAp de 2*dim
*/