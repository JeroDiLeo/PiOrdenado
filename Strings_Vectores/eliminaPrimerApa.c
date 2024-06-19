/*
Ejercicio 1
a) Escribir una función elimina que recibe un string y elimina las primeras apariciones de los
caracteres repetidos, dejando sólo la última aparición.
Ejemplos de uso
char s[] = "abcbc.cba";
elimina(s); // s es ahora ".cba"
char t[] = "123456654321";
elimina(t); // t es ahora "654321"
elimina(t); // t no cambia
char u[] = "Abc123aBC";
elimina(u); // u no cambia
b) Escribir un ejemplo de invocación que asegure que el programa aborta en ejecución. Explicar por
qué aborta.
*/


void elimina(char s[]){

  int vecAp[MAX_CHAR] = {0};  // Inicializo el vector de apariciones en 0

  for (int i=0; s[i]!='\0'; i++)
    vecAp[s[i]]++;          // Cuento las apariciones de cada caracter. Por ejemplo, si s[i] es 'a' (cuyo valor ASCII es 97), entonces vecAp[97] se incrementa.

  int t=0;

  for (int i=0; s[i]!='\0'; i++){

    if (vecAp[s[i]] > 1){       // Si el caracter se repite más de una vez
      vecAp[s[i]]--;            // Decremento la cantidad de apariciones
    }else if (vecAp[s[i]] == 1){    // Si es la última aparición del caracter la copio al nuevo string y avanzo

      s[t++] = s[i];

    }
  }

  s[t] = '\0';

}
//Un ejemplo de invocación que podría hacer que el programa aborte en ejecución es:

char *p = NULL;
elimina(p);
/*
En este caso, p es un puntero nulo (NULL).
 Si se pasa este puntero a la función elimina, se intentará acceder a memoria a través de un puntero nulo,
  lo que causará un fallo de segmentación y, por tanto, abortará el programa.*/
