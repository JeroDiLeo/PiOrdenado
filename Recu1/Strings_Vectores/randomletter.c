/*Hacer un programa que genere una letra mayúscula aleatoria y un númeroaleatorio N entre 1 y 256.
● Luego, deberá invocar a una función que lea un texto hasta N caracteres comomáximo (si aparece antes EOF, termina la lectura)
 y retorne la cantidad deveces que dicha letra aparece en mayúscula o en minúscula.
 ● Ejemplos para cuando el texto es: 
 “Había una vez un avestruz muy vivo,vivísimo que se llamaba Victor”
 ○ Si se genera letra ‘V’ y N =101 la función retornaría: 7.
 ○ Si se genera letra ‘A’ y N=5 la función retornaría 2.*/

 #include <stdio.h>
 #include "rand.h"
 int contarEnTexto(int letra, int N);
 
 
 int main(){
    randomize();
    int letra=randInt('A','Z');
    int N=randInt(1,256);
    int cant=contarEnTexto(letra,N);
    
    printf("Cantidad de apariciones de %c (hasta %d símbolos):%d\n",letra,N,cant);
    
        return 0;
}
    
    

intcontarEnTexto(int letra, int N){
    int c,i=0, cant = 0;
    while ((c=getchar())!=EOF && i < N){
        if (c==letra || c==letra-'A'+'a')
        cant++;
        i++;
    }
    return cant;
    
}