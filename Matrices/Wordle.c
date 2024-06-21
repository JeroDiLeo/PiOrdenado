/*
Implementar una función wordle que resuelva un tablero del juego Wordle (también conocido como palabra del día). La función recibe:
Una palabra secreta de COLS caracteres (no es necesario validarlo)
Una matriz de caracteres de tamaño FILS x COLS donde cada fila es un intento del usuario para resolver la palabra secreta
La cantidad de intentos del usuario (un entero menor o igual a FILS)
La función debe dejar en otra matriz una marca V, A o G para cada letra de cada intento del usuario donde:
V: VERDE significa que la letra está en la palabra y en la posición CORRECTA.
A: AMARILLO significa que la letra está presente en la palabra pero en la posición INCORRECTA.
G: GRIS significa que la letra NO está presente en la palabra.
	hasta que se marque el primer intento correcto (todas las letras verdes) o se hayan analizado todos los intentos.
	La función debe retornar un entero con el número del primer intento correcto (todas las letras verdes) o -1 si ningún intento es correcto.
Notar que tanto la palabra oculta como las palabras de los intentos pueden contener letras repetidas. 
En ese caso, las pistas son independientes para cada letra y tienen prioridad: verde tiene mayor prioridad al amarillo.

Ejemplos:
	Con FILS = 6 y COLS = 5, donde la palabra secreta a adivinar es R O S A S y el usuario hace los siguientes 6 intentos: 
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
Para F A R O L se marcan las letras A, R y O que están en la palabra pero en la posición incorrecta y queda G A A A G
Para S A C O S se marca la primera S en amarillo y la segunda S en verde y queda A A G A V
Para R A T O S se marca en verde la S pues está en la posición correcta y no se avisa si hay una letra repetida y queda V A G A V
Para R O S A S como la palabra coincide con todas las letras se marcan como verdes y queda V V V V V
Para el quinto y sexto intento no se marca nada porque el cuarto fue correcto
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define FILS 6
#define COLS 5

enum Colors {GREEN='V', YELLOW='A', GREY='G'};

int wordle(const char *, const char [][COLS], int, char [][COLS]);
static int wordleRow(const char [COLS], const char *, char [COLS]);
static int wordleLetter(const char *, char, int);

int wordle(const char * secretWord, const char inputMatrix[][COLS], int inputDim, char outputMatrix[][COLS]) {
    int i, greenRow;
    for(i = 0, greenRow = 0; i < inputDim && !greenRow; i++) {
        greenRow = wordleRow(secretWord, inputMatrix[i], outputMatrix[i]);
    }
    return greenRow ? i : -1;
}

static int
wordleRow(const char * secretWord, const char inputRow[COLS], char outputRow[COLS]) {
    int i, greenLetter;
    for(i = 0, greenLetter = 1; i < COLS; i++) {
        outputRow[i] = wordleLetter(secretWord, inputRow[i], i);
        greenLetter &= outputRow[i] == GREEN;
    }
    return greenLetter;
}

static int wordleLetter(const char * secretWord, char inputLetter, int inputIndex) {
    if(secretWord[inputIndex] == inputLetter) {
        return GREEN;
    }
    if(strchr(secretWord, inputLetter) != NULL) {
        return YELLOW;
    }
    return GREY;
}



// Otra versión correcta, usando un vector de apariciones. Esta esta mucho mejor
//Este sirve si hay letras ASCII o si tengo que distinguir entre mayúsculas y minúsculas
#define LETTERS 255

int wordle2(const char * secretWord, const char inputMatrix[][COLS], int inputDim, char outputMatrix[][COLS]) {
    int i, j, greenCount;
    char secretWordLetters[LETTERS] = {0};
    for(int x = 0; secretWord[x]; x++)          // Cuento las letras de la palabra secreta y las marco como presentes en el vector de apariciones
        secretWordLetters[secretWord[x]] = 1;       

    for(i = 0; i < inputDim && greenCount != COLS; i++) {
        for(j = 0, greenCount = 0; j < COLS; j++) {

            char inputLetter = inputMatrix[i][j];

            if(secretWord[j] == inputLetter) {
                outputMatrix[i][j] = GREEN;
                greenCount++;
            } else if(secretWordLetters[inputLetter] == 1) {
                outputMatrix[i][j] = YELLOW;
            } else {
                outputMatrix[i][j] = GREY;
            }
        }
    }
    return greenCount == COLS ? i : -1;
}

//----------------------------------------------------------------------
//Este sirve si solo hay letras mayúsculas
#define LETTERS 26

int wordle2(const char *secretWord, const char inputMatrix[][COLS], int inputDim, char outputMatrix[][COLS]) {
    int i, j, greenCount;
    char secretWordLetters[LETTERS] = {0};

    for (int x = 0; secretWord[x]; x++) {
        secretWordLetters[secretWord[x] - 'A'] = 1; //
    }

    for (i = 0; i < inputDim; i++) {
        greenCount = 0;

        for (j = 0; j < COLS; j++) {
            char inputLetter = inputMatrix[i][j];

            if (secretWord[j] == inputLetter) {
                outputMatrix[i][j] = GREEN;
                greenCount++;
            } else if (secretWordLetters[inputLetter - 'A'] == 1) {
                outputMatrix[i][j] = YELLOW;
            } else {
                outputMatrix[i][j] = GREY;
            }
        }

        if (greenCount == COLS) {
            return i + 1; 
        }
    }

    return -1; 
}











int
main(void) {
    // La palabra del día a adivinar es R O S A S
    char * secretWord = "ROSAS";

    // El usuario hace 4 intentos:
    // F A R O L
    // S A C O S
    // R A T O S
    // R O S A S
    char inputMatrix[][COLS] = {
            {'F', 'A', 'R', 'O', 'L'},
            {'S', 'A', 'C', 'O', 'S'},
            {'R', 'A', 'T', 'O', 'S'},
            {'R', 'O', 'S', 'A', 'S'}
    };
    int inputDim = 4;

    char outputMatrix[FILS][COLS];
    // La función wordle deja en outputMatrix:
    // G A A A G
    // A A G A V
    // V A G A V
    // V V V V V
    // y retorna 4 porque el cuarto intento es el primero correcto.
    assert(wordle(secretWord, inputMatrix, inputDim, outputMatrix) == 4);

    // Para F A R O L el amarillo indica que las letras A, R y O están en la palabra pero en la posición incorrecta y queda
    //      G A A A G
    assert(outputMatrix[0][0] == GREY);
    assert(outputMatrix[0][1] == YELLOW);
    assert(outputMatrix[0][2] == YELLOW);
    assert(outputMatrix[0][3] == YELLOW);
    assert(outputMatrix[0][4] == GREY);

    // Para S A C O S se marca la primera S en amarillo y la segunda S en verde y queda
    //      A A G A V
    assert(outputMatrix[1][0] == YELLOW);
    assert(outputMatrix[1][1] == YELLOW);
    assert(outputMatrix[1][2] == GREY);
    assert(outputMatrix[1][3] == YELLOW);
    assert(outputMatrix[1][4] == GREEN);

    // Para R A T O S se marca en verde la S pues esta en la posición correcta y no se avisa si hay una letra repetida.
    //      V A G A V
    assert(outputMatrix[2][0] == GREEN);
    assert(outputMatrix[2][1] == YELLOW);
    assert(outputMatrix[2][2] == GREY);
    assert(outputMatrix[2][3] == YELLOW);
    assert(outputMatrix[2][4] == GREEN);

    // Para R O S A S como la palabra coincide con todas las letras se marcan como verdes y queda
    //      V V V V V
    assert(outputMatrix[3][0] == GREEN);
    assert(outputMatrix[3][1] == GREEN);
    assert(outputMatrix[3][2] == GREEN);
    assert(outputMatrix[3][3] == GREEN);
    assert(outputMatrix[3][4] == GREEN);

    printf("OK!\n");
    return 0;
}