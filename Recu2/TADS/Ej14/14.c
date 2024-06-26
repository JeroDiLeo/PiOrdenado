#include <stdlib.h>
#include "tp11_ej14.h"
#include <stdio.h>

// Mantenemos dos listas, una ascendente y otra por orden de inserción (una cola)
typedef struct listCDT {
    struct node * firstAsc;     // primero en orden ascendente
    struct node * firstInsert;
    struct node * lastInsert;
    struct node * iterAsc;      // para iterar en orden ascendente
    struct node * iterInsert;
    int (*compare) (elemType e1, elemType e2);  // almacenamos la función de comparación
} listCDT;

typedef struct node {
  elemType elem;
  struct node * tail;
} node;

listADT newList(int (*compare) (elemType e1, elemType e2)) {
  listADT ans = calloc(1, sizeof(listCDT));
  ans->compare = compare;
  return ans;
}

static node * addRec(node * first, elemType elem, int *ok, int (*compare) (elemType e1, elemType e2)) {
  int c;
  if ( first == NULL ||  ( c =  compare(elem, first->elem)) < 0) {
    node * aux = malloc(sizeof(node));
    aux->elem = elem;
    aux->tail = first;
    *ok = 1;
    return aux;
  }
  if ( c > 0 )
    first->tail = addRec(first->tail,  elem, ok, compare);
  return first;
}

void add(listADT list, elemType elem) {
  // primero insertarmos en orden, y que nos diga si estaba o no
  int added = 0;
  list->firstAsc = addRec(list->firstAsc, elem, &added, list->compare);
  if ( added ) {    // Si no estaba, entonces lo agregamos directamente al final de la otra lista
    node * aux = malloc(sizeof(node));
    aux->elem = elem;
    aux->tail = NULL;
    if ( list->firstInsert == NULL)
      list->firstInsert = aux;
    else
      list->lastInsert->tail = aux;
    list->lastInsert = aux;
  }
}

/* Elimina un elemento. */
// void remove(listADT list, elemType elem)

void toBegin(listADT list) {
  list->iterInsert = list->firstInsert;
}

int hasNext(listADT list) {
  return list->iterInsert != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en el orden de inserción. 
** Si no hay un elemento siguiente o no se invocรณ a toBegin aborta la ejecución.
*/
elemType next(listADT list) {
  if ( !hasNext(list)) {
    fprintf(stderr, "Invalid use of iterator\n");
    exit(1);
  }
  elemType toReturn = list->iterInsert->elem;
  list->iterInsert = list->iterInsert->tail;
  return toReturn;
}

void toBeginAsc(listADT list) {
  list->iterAsc = list->firstAsc;
}

int hasNextAsc(listADT list) {
  return list->iterAsc != NULL;
}

elemType nextAsc(listADT list) {
  if ( !hasNextAsc(list)) {
    fprintf(stderr, "Invalid use of ordered iterator\n");
    exit(1);
  }
  elemType toReturn = list->iterAsc->elem;
  list->iterAsc = list->iterAsc->tail;
  return toReturn;
}

void freeRec(node * first) {
  if ( first == NULL)
    return;
  freeRec(first->tail);
  free(first);
}

void freeList(listADT list) {
  freeRec(list->firstAsc);
  freeRec(list->firstInsert);
  free(list);
}