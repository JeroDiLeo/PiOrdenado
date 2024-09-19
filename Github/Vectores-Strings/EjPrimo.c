/*Escribir un programa que determine si un numero entero positivo es primo o no*/
#include <stdio.h>
#include "Bibliotecas/getnum.h"


int main(){

int EsPrimo(int numero);
    
    int numero;
    //Chequeo que el numero que me pasan sea positivo
    do{
        numero=getint("Ingrese un numero entero positivo: \n");
    }while(numero<0);

    printf("Es primo?:%d\n",EsPrimo(numero));

}
//Devuelve 0 si no ES primo, 1 si   ES primo
//Asumo 1 primo
int EsPrimo(int numero){
    int esprimo=1;
    if((numero!=2)&&((numero%2)==0)){
        esprimo=0;
    }else{
    //Arranco contando desde impares, salteandome los pares ya que el unico par que es primo es 2
    //corto cuando la flag se vuelve 0
    for(int divisor=3;((divisor*divisor)<=numero)&&esprimo;divisor+=2){
        if((numero%divisor)==0){
            esprimo=0;
        }
        
    }
    }

    return esprimo;
}






//Solucion catedra
//Casos Especiales
int Primo=1;//Asumo que es Primo
if(numero==2||numero==3){
    return 1;
}
if(n%2==0){
    return 0;
}
//El mismo for
for(int i=3 )


    
        




