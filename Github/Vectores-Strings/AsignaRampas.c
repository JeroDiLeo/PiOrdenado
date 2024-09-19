/*
Un aeropuerto tiene una cantidad fija de rampas, donde cada rampa se asigna en
forma temporal a una aerolínea.
Cada aerolínea es identificada con un número entero, por ejemplo Aerolíneas
Argentinas es la 44, Aeroflot 556, American Airlines 1, etc.
Cada rampa se identifica con un número entero consecutivo, siendo la primera
rampa la número cero.
Se busca asignar rampas libres a una aerolínea pero además optimizar la
distribución de las mismas, de forma que sólo queden rampas libres al final.
Escribir la función asignaRampas que reciba:
● rampas: un vector de enteros mayores o iguales a cero, donde si
rampas[i] es cero indica que la rampa i está libre, sinó tendrá el código de
la aerolínea que la tiene asignada
● dim: entero sin signo, con la dimensión del vector rampas
● aerolinea: código de la aerolínea que está solicitando rampas
● cant: cantidad de rampas que solicita la aerolínea
La función debe reasignar las primeras rampas libres a las aerolíneas que ya
tienen rampas reservadas preservando el orden, y asignarle cant rampas libres a la
aerolínea. En caso de no haber suficientes rampas libres le asigna todas las libres.
La función retorna cuántas rampas se le asignaron
int main(void) {
int v[] = {0, 44, 44, 0, 0, 0, 1};
int n = asignaRampas(v, 7, 56, 2); // 2 rampas libres para la
56
// n vale 2
// v = { 44, 44, 1, 56, 56, 0, 0};
n = asignaRampas(v, 7, 1, 3}; // 3 rampas más para la 1
// n vale 2 (no hay 3 libres)
// v = { 44, 44, 1, 56, 1, 1};
n = asignaRampas(v, 7, 88, 3};
// n vale 0
// v no cambia
int v2[] = {44, 0, 1, 44, 44, 1, 0, 44};
n = asignaRampas(v2, 8, 56, 1);
// n vale 1
// v2 = { 44, 1, 44, 44, 1, 44, 56, 0};
}
*/
#include <assert.h>
#include <stdio.h>

int eliminaCeros(unsigned int vec[],unsigned int dim);
int asignaRampas(unsigned int rampas[],unsigned int dim ,int aerolinea,int cant);

int main(void) {
  int v[] = {0, 44, 44, 0, 0, 0, 1};
  int n = asignaRampas(v, 7, 56, 2); // 2 rampas libres para la 56
  // n vale 2
  // v = { 44, 44, 1, 56, 56, 0, 0};
  assert(n==2);
  assert(v[0]==44 && v[1]==44 && v[2]==1);

  n = asignaRampas(v, 7, 1, 3); // 3 rampas más para la 1
  // n vale 2 (no hay 3 libres)
  // v = { 44, 44, 1, 56, 1, 1}; 
  assert(n==2);
  assert(v[0]==44 && v[1]==44 && v[2]==1 && v[4]==56);

  n = asignaRampas(v, 7, 88, 3); 
  // n vale 0
  // v no cambia
  assert(n==0);
  assert(v[0]==44 && v[1]==44 && v[2]==1 && v[4]==56);

}



int asignaRampas(unsigned int rampas[],unsigned int dim,int aerolinea,int cant){
    int i;
    int rampasAsignadas=0;
    int libres=eliminaCeros(rampas,dim);
    for(i=libres;i<dim && rampasAsignadas<cant;i++){
        rampas[i]=aerolinea;
        rampasAsignadas++;
    }
    for(int j=libres+rampasAsignadas;j<dim;j++){
        rampas[j]=0;
    }
    return rampasAsignadas;
}


int eliminaCeros(unsigned int vec[],unsigned int dim){
    int k=0;
    for(int i=0;i<dim;i++){
        if(vec[i]!=0){
            vec[k++]=vec[i];
        }
    }
    return k;
}
