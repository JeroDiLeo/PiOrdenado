/*Escribir una función numerosAmigos que acepte como parámetro dos númerosenteros y devuelva en su nombre:
● El valor 1 si los números son amigos, esto es si cada uno de ellos es igual lasuma de los divisores del otro (No se suma el mismo número)
● El valor 0 en caso contrario.

Ejemplos:
● numerosAmigos(220, 284) devuelve 1 (los divisores de 220 son 1, 2, 4, 5,10, 11, 20, 22, 44, 55 y 110, que suman 284,
 y los divisores de 284 son 1, 2, 4, 71 y142 que suman 220)

● numerosAmigos(10, 12) devuelve 0 (los divisores de 10 son1, 2 y 5 que suman 8)
*/


int numerosAmigos(int a, int b){            //Retorna 1 si x es igual a la suma de divisores de num

    return verificoAmistad(a, b) && verificoAmistad(b, a);
}
static int verificoAmistad(int x, int num){//
    int suma, d, sonAmigos;
    for (suma=0, d=1, sonAmigos=1; d < num && sonAmigos; d++){ 
        if (suma > x) {
            sonAmigos = 0;
        } else if (num % d == 0){ // d es un divisor de num
            suma += d;
        }
    }
    return (sonAmigos && suma==x);
}