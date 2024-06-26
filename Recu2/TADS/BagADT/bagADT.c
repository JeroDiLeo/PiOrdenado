#include "bagADT.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node * TList;

typedef struct node{

  elemType head;
  struct node * tail;
  size_t count;
}TNode;

typedef struct bagCDT{

  TList first;
  size_t size;      
}bagCDT;


bagADT newBag(){

  bagADT bag = calloc(1, sizeof(bagCDT));

  return bag;
}


static TList addRec(TList list, elemType elem, size_t * cant){


  if ( list == NULL || ( !(list->count) && (compare(list->head, elem) > 0) ) ){


    TList aux = malloc(sizeof(TNode));
    aux->head = elem;
    aux->tail = list;
    aux->count = 1;
    return aux;
  }

  if (!compare(list->head, elem)){
    (*cant)++;
    (list->count)++;
  }

  list->tail = addRec(list->tail, elem, cant);
  return list;

}

size_t add(bagADT bag, elemType elem){

  size_t cant = 1;

  bag->first = addRec(bag->first, elem, &cant);

  if (cant == 1)
    (bag->size)++;
  
  return cant;

}

void countRec(TList list, elemType elem, size_t * cant){

  if (list == NULL || compare(list->head, elem) > 0)
    return;
  
  if (!compare(list->head, elem)){
    (*cant) = list->count;
    return;
  }

  countRec(list->tail, elem, cant);
}

size_t count(const bagADT bag, elemType elem){

  size_t cant = 0;

  countRec(bag->first, elem, &cant);

  return cant;

}

size_t size(const bagADT bag){
  
  return bag->size;
  
}


TList mostPopRec(TList list){

   if (list->tail == NULL)
    return list;

  TList ret = mostPopRec(list->tail);

  if ( list->count > ret->count ){
    ret = list;
  }

  return ret;

}


elemType mostPopular(bagADT bag){

  if (bag->first == NULL){ 
    fprintf(stderr, "Error: La bolsa no puede estar vacia.\n");
    exit(1);
  }
  
  TList ret = mostPopRec(bag->first);

  return ret->head;
  
}


void freeBag(bagADT bag){
  
  TList actual = bag->first;
  TList next;

  while (actual != NULL){
    next = actual->tail;  
    free(actual);
    actual = next;
  }

  free(bag);


}