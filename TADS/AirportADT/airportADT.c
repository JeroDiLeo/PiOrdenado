#define BLOQUE 10

typedef struct node * TList;

typedef struct node {
    char * matricula; /* matricula de cada avion */
    struct node * tail;
} TNode;

typedef struct pista {
    char flag; /* si flag esta en 0, esta pista no existe */
    TList first;
    TList last; /* puntero al ultimo nodo de la lista (facilita para agregar al final) */
    size_t cantAviones; /* cantidad de aviones por pista */
} pista;

typedef struct airportCDT {
    struct pista * pistas;
    size_t cantPistas; /* cantidad actual de pistas en el sistema */
    size_t dimMax; /* dimension actual de struct pista * pistas ( la uso para cuando quiero agregar una pista nueva y quiero ver si tengo espacio, tambien para cuando me pasan un runwayId y quiero ver si existe, ya que no puedo chequear basura) */
} airportCDT;

typedef airportCDT * airportADT;

/* Crea un sistema de administración de pistas y despegues de aviones
** de un aeropuerto.
** El sistema inicia sin pistas.
*/
airportADT newAirport(void) {
    airportADT new = calloc(1, sizeof(airportCDT));
    return new;
}

static char * copyAux(char * s) {
    int i;
    char * aux = NULL;
    for (i = 0; s[i]; i++) {
        if (!(i % BLOQUE))
            aux = realloc(aux, (i + BLOQUE) * sizeof(char));
        aux[i] = s[i];
    }
    aux = realloc(aux, (i + 1) * sizeof(char)); /* corrección aquí */
    aux[i] = 0;
    return aux;
}

/* Elimina al avión que se encuentra al principio de la pista de
** despegue con el identificador runwayId
** y retorna la matrícula del avión eliminado o NULL si falla.
** Falla si la pista no existe.
** Falla si no hay aviones en la pista.
*/
char * takeOff(airportADT airportAdt, size_t runwayId) {
    if (airportAdt->dimMax >= runwayId && airportAdt->pistas[runwayId - 1].flag) {
        if (airportAdt->pistas[runwayId - 1].first != NULL) {
            char * aux = airportAdt->pistas[runwayId - 1].first->matricula; /* correción aquí */
            TList aux2 = airportAdt->pistas[runwayId - 1].first->tail;
            free(airportAdt->pistas[runwayId - 1].first);
            airportAdt->pistas[runwayId - 1].first = aux2;
            airportAdt->pistas[runwayId - 1].cantAviones -= 1;
            return aux;
        }
    }
    return NULL;
}

static void pendingFlightsRec(TList list, char ** vec, size_t * cont) {
    if (list == NULL)
        return;
    pendingFlightsRec(list->tail, vec, cont);
    vec[*cont] = list->matricula;
    (*cont)++;
}

/* Retorna un arreglo con las matrículas de los aviones que se
** encuentran en la pista de despegue con el identificador
** runwayId en orden inverso al orden de despegue (el último elemento
** del arreglo debe coincidir con el valor de retorno de una
** invocación a la función takeOff sobre esa pista).
** El arreglo debe ** contar con una cadena vacía "" como marca de fin.
** Si la pista no existe retorna NULL.
*/
char ** pendingFlights(airportADT airportAdt, size_t runwayId) {
    if (airportAdt->dimMax >= runwayId && airportAdt->pistas[runwayId].flag) {
        char ** aux = malloc((airportAdt->pistas[runwayId].cantAviones + 1) * sizeof(char *)); /* el + 1 es por el "" */
        size_t cont = 0;
        pendingFlightsRec(airportAdt->pistas[runwayId].first, aux, &cont);
        aux[cont] = "";
        return aux;
    }
    return NULL;
}