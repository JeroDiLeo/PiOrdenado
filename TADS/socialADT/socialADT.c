    #include <stdlib.h>
#include "tp11_ej12.h"
#include <string.h>
#include <stdio.h>

// Función auxiliar que crea una copia en el heap
static char * copyStr(const char * s) {
    return strcpy(malloc(strlen(s)+1), s);
}

// Como el enunciado dice que hay un máximo, entonces podemos definir la constante
// Si el enunciado no dijera que hay un límite, entonces no podemos asumirlo
#define MAX 21 

struct related {
    char name[MAX];             // Usamos un vector estático porque hay un límite y es pequeño.
                                // También se podría usar char*, y no tener un límite.
    struct related * next;
};

struct person {
    char name[MAX];
    struct related * firstR;
    struct person * next;
    size_t sizeR;
};

typedef struct person * TPerson;
typedef struct related * TRelated;

struct socialCDT {
    struct person * people;     // puntero a la primera persona
    size_t sizeP;
};

 
/* Crea un nuevo TAD vacío */
socialADT newSocial() {
    return calloc(1, sizeof(struct socialCDT));     // calloc porque están todos inicializados en 0 
}

static void freeRelated(struct related * first) {
    if ( first == NULL)
        return;
    freeRelated(first->next);
    free(first);
}

static void freeSocialP(struct person * first) {
    if ( first == NULL)
        return;
    freeSocialP(first->next);
    freeRelated(first->firstR);
    free(first);
}

/* Libera todos los recursos reservados por el TAD */
void freeSocial(socialADT soc) {
    freeSocialP(soc->people);
    free(soc);
}

static TPerson addPersonRec(TPerson first, const char * name, int *ok){
    int c;
    if ( first == NULL || ( c = strcmp(first->name, name)) > 0) {
        TPerson aux = malloc(sizeof(struct person));
        aux->firstR = NULL;
        aux->sizeR = 0;
        // si usaban char *, debían hacer aux->name = malloc(strlen(name)+1);
        strncpy(aux->name, name, MAX-1);        // Programación defensiva: usamos strncpy para no pisar memoria
        aux->name[MAX-1] = 0;                   // si strncpy copia la cantidad justa, no agrega ceros
        aux->next = first;
        *ok=1;
        return aux;
    }
    if ( c < 0)
        first->next = addPersonRec(first->next, name, ok);
    return first;
}
 
/* Almacena una nueva persona. Si la persona existe, no hace nada
** Guarda una copia del nombre y no simplemente el puntero
*/
void addPerson(socialADT soc, const char * name) {
    int ok=0;
    soc->people = addPersonRec(soc->people, name, &ok);
    if ( ok )
        soc->sizeP ++;
}

static TPerson findPerson(TPerson first, const char * name) {
    TPerson aux = first;
    while ( aux != NULL) {
        int c = strcmp(aux->name, name);
        if ( c == 0) {
            return aux;
        }
        if ( c > 0)
            return NULL;
        aux = aux->next;
    }
    return NULL;
}

static TRelated addRelatedRec(TRelated first, const char * name){
    int c;
    if ( first == NULL || ( c = strcmp(first->name, name)) >= 0) {
        TRelated aux = malloc(sizeof(struct related));
        strncpy(aux->name, name, MAX-1);
        aux->name[MAX-1] = 0;                   // si strncpy copia la cantidad justa, no agrega ceros
        aux->next = first;
        return aux;
    }
    if ( c < 0)
        first->next = addRelatedRec(first->next, name);
    return first;
}
void addRelated(socialADT soc, const char * name, const char * related) {
    TPerson aux = findPerson(soc->people, name);
    if ( aux != NULL) {
        aux->firstR = addRelatedRec(aux->firstR, related);
        aux->sizeR++;
    }
}

/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como elemento
 */
char ** related(const socialADT soc, const char * person) {
    char ** ans;
    TPerson p = findPerson(soc->people, person);
    int k=0;
    if ( p != NULL) {
        ans = malloc((p->sizeR+1) * sizeof(char *));
        TRelated auxR = p->firstR;
        while ( auxR != NULL) {
            ans[k++] =  copyStr(auxR->name);
            auxR = auxR->next;
        }
    } else
        ans = malloc(sizeof(char *));
    ans[k] = NULL;
    return ans;
}




/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como
** elemento
 */
char ** persons(const socialADT soc) {
    char ** ans = malloc((soc->sizeP+1) * sizeof(char *));
    TPerson aux = soc->people;
    int k=0;
    while ( aux != NULL) {
        ans[k++] = copyStr(aux->name);
        aux = aux->next;
    }

    ans[k] = NULL;
    return ans;
}