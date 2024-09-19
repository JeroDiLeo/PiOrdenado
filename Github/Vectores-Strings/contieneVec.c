/*
Armar una funcion contiene que reciba 2 vectores y sus dim
retorna 1 si todos los elementos del primer vector están en el segundo
retorna 2 si todos los elementos del segundo vector están en el primero
retorna 0 caso contrario
Los vectores no estan ordenados necesariamente*/

//Armo una sola funcion y la llamo dos veces
//Tengo que usar un vector de apariciones
#include <stdio.h>
#include <assert.h>


int estaEnVec(const int v[],unsigned int dim,int elem);
int contieneTodos(const int v1[],unsigned int dim1, const int v2[],unsigned int dim2);
int contiene(const int v1[],unsigned int dim1,const int v2[], unsigned int dim2);

int main(void) {

  int v1[] = {1,6,5,3,2};
  int v2[] = {1,2};
  assert(contiene(v1, 5, v2, 2)==2);
  assert(contiene(v2, 2, v1, 5)==1);
  assert(contiene(v1, 1, v2, 2)==1);
  assert(contiene(v1, 0, v2, 2)==1);
  assert(contiene(v1, 5, v2, 0)==2);
  
  int v3[] = {1,2,3,4,5,6};
  assert(contiene(v1, 5, v3, 6)==1);

  int cnt = contiene(v1, 0, v3, 0);
  assert(cnt ==1 || cnt==2);

  int v4[] = { 10, 20, 30, 1, 2};
  assert(contiene(v2, 2, v4, 4)==0);
  assert(contiene(v2, 2, v4, 5)==1);
  assert(contiene(v4, 5, v2, 2)==2);

  int v5[] = {1,1,1,1,1,2,1,2};
  int v6[] = {1,2,3};
  assert(contiene(v5, 8, v6, 3)==1);
  assert(contiene(v6, 3, v5, 8 )==2);

  printf("OK!\n");
  return 0;
}

int contiene(const int v1[],unsigned int dim1,const int v2[], unsigned int dim2){
if(contieneTodos(v1,dim1,v2,dim2)){
    return 1;
}else if(contieneTodos(v2,dim2,v1,dim1)){
    return 2;
}else{
    return 0;
}

}

int contieneTodos(const int v1[],unsigned int dim1, const int v2[],unsigned int dim2){
    for(int i=0;i<dim1;i++){
        if(!estaEnVec(v2,dim2,v1[i])){
            return 0;
        }
    }
    return 1;
}

int estaEnVec(const int v[],unsigned int dim,int elem){
    for(int i=0;i<dim;i++){
        if(v[i]==elem){
            return 1;
        }
    }
    return 0;
}








/*
//Este codigo sirve SI no hubiesen elementos repetidos
int contiene(const int v1[],unsigned int dim1, const int v2[],unsigned int dim2){
    int contador=0;
    for(int i=0;i<dim1;i++){
        int encontrado=0;
        for(int j=0;j<dim2 && encontrado==0;j++){
            if(v1[i]==v2[j]){
                contador++;
                encontrado=1;
            }
        }
    }
    return(contador==dim1)
}
*/