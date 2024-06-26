#ifndef PI_POLYADT_H
#define PI_POLYADT_H

/*
 * Se cuenta con un TAD polinomio el cual implementa cada polinomio como una lista simplemente
 * encadenada sin header ordenada en forma descendente por el grado de la variable. El contrato para el TAD
 * poliniomio es el siguiente:
 *
 *   polinomio: (10, 5) -> (3, 6) -> (0, 1)
 *   polinomio: sum(a_i * x^i)_0^i
 *
 * Se pide:
 *  1) Definir struct polyCDT
 *  2) Implementar la funcion addPolynomial
 * */

typedef struct polyCDT * polyADT;

/*
 *  Retorna un polinomio vacio ( NULL )
 * */
polyADT newPolynomial(void);


/*
 *  Retorna 1 si el polinomio esta vacio
 *          0 en caso contrario
 * */
int isEmpty(polyADT poly);

/*
 *  Agrega un término al polinomio con el coeficiente y grado.
 *  Se inserta ordenado por grado, en forma decreciente.
 *  Si ya existe un termino con ese grado o no se pudo agregar retorna cero.
 *  Si no existia y se pudo agregar, retorna uno.
 * */
int addTerm(polyADT *poly, float coef, int degree);

/*
 * Suma los polinomios enviados como parametro y obtiene un nuevo polinomio.
 * En caso de error retorna NULL
 * */
polyADT addPolynomial(polyADT p, polyADT q);

#endif //PI_POLYADT_H