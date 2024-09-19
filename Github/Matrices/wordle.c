/*
Implementar una función wordle que resuelva un tablero del juego Wordle
(también conocido como palabra del día). La función recibe:
● Una palabrasecretade COLS caracteres (no es necesario validarlo)
● Una matrizdecaracteresde tamaño FILS x COLS donde cada fila es un intento del usuario para resolver la palabra secreta
● La cantidaddeintentosdel usuario (un entero menor o igual a FILS)

La función debe dejar en otramatrizuna marca V, A o G para cada letra de
cada intento del usuario donde:
● V: VERDE significa que la letra está en la palabra y en la posición
CORRECTA.
● A: AMARILLO significa que la letra está presente en la palabra pero en la
posición INCORRECTA.
● G: GRIS significa que la letra NO está presente en la palabra.
hasta que se marque el primer intento correcto (todas las letras verdes) o se
hayan analizado todos los intentos.

La función debe retornar un entero con el número del primer intento correcto
(todas las letras verdes) o -1 si ningún intento es correcto.
Notar que tanto la palabra oculta como las palabras de los intentos pueden
contener letras repetidas. En ese caso, las pistas son independientes para cada letra
y tienen prioridad: verde tiene mayor prioridad al amarillo.
Ejemplos:
Con FILS = 6 y COLS = 5, donde la palabra secreta a adivinar es R O S A S
y el usuario hace los siguientes 6 intentos:
F A R O L
S A C O S
R A T O S
R O S A S
C O S A S
T E C L A
la función retorna 4 porque el cuarto intento es correcto y se obtiene:
G A A A G
A A G A V
V A G A V
V V V V V
? ? ? ? ?
? ? ? ? ?
● Para F A R O L se marcan las letras A, R y O que están en la palabra pero
en la posición incorrecta y queda G A A A G
● Para S A C O S se marca la primera S en amarillo y la segunda S en verde y
queda A A G A V
● Para R A T O S se marca en verde la S pues está en la posición correcta y
no se avisa si hay una letra repetida y queda V A G A V
● Para R O S A S como la palabra coincide con todas las letras se marcan
como verdes y queda V V V V V
● Para el quinto y sexto intento no se marca nada porque el cuarto fue correcto
*/
#include <stdio.h>
#define COLS 5
#define FILS 6
#define V 1
#define G 2
#define A 3

int belongs( char * palabra, char c){
    for( int i=0; i<COLS; i++){
        if( palabra[i] == c)
            return 1;
    }
return 0;
}

int chequeo(char m[], char out[], const char *palabra){
    int cont=0;
    for( int i=0; i<COLS; i++){
        if( m[i] == palabra[i]){
            cont++;
            out[i] = V;
        }else if( belongs(palabra, m[i]) ){
            out[i] = A;
        }else 
            out[i] = G;
    }
    return (cont == COLS);
}

int wordle(const char palabra[], const char m[][COLS], const int intentos, char out[][COLS]){
    int flag=0,i;
    if( intentos < 0 || intentos > FILS)
        return -1;
    for( i=0; i<=intentos && !flag; i++){ // !flag = 1 -> entra en el for; si es 1 -> encontra y se va al return
        flag = chequeo(m[i], out[i], palabra);
    }
    return flag ? i : -1;
}

int main(){
    char m[FILS][COLS] = {{'F','A','R','O','L'},{'S','A','C','O','S'},{'R','A','T','O','S'},{'R','O','S','A','S'},{'C','O','S','A','S'},{'T','E','C','L','A'}};
    char secreta[] = "ROSAS" ;
    char out[FILS][COLS] = {0};
    int intentos = 6;
    printf("%d\n", wordle(secreta, m, intentos, out));




    for(int i=0; i<FILS; i++){
        for(int  j=0; j<COLS; j++){
            printf("%-5s", out[i][j] == V ? "V":(out[i][j] == G ? "G":(out[i][j] == A ? "A":"?")));
        }
        printf("\n");
    }
}
