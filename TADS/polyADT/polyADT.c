typedef struct polyCDT {
    int degree;
    float coef;
    struct polyCDT *tail;   //El siguiente termino
} polyCDT;




//Primero veo si el polinomio esta vacio, si lo esta, retorno 0
//Comparo los grados de los polinomios, si es mas grande el grado de p, agrego el termino de p al polinomio resultante, avanzo solo el mas grande
//Si los grados son iguales, agrego la suma de los coeficientes al polinomio resultante y avanzo los dos polinomios
/*  Ej:
    p1 =(100, -3)->(10, 5)-> NULL
    p2=(100, 6)->(20, -7)-> NULL
    p3=(100, 3)->(20, -7)->(10, 5)-> NULL
*/
polyADT newPolynomial(void) {
    return NULL;
}

int isEmpty(polyADT poly) {
    return poly == NULL;
}



//Esta hace la suma de polinomios nomas
polyADT addPolynomial(polyADT p, polyADT q) {   //Sumo la lista p con la lista q
    if(p==NULL && q==NULL) 
        return NULL; //Si ambos polinomios son nulos, retorno NULL

    if(q==NULL){
        return addPolynomial(q, p); //Lo doy vuelta para ver que siempre voy a tener algo en el segundo parametro
    }
    polyADT newterm = malloc(sizeof(polyCDT)); //Creo un nuevo termino
    if(p==NULL|| q->degree > p->degree){
        newterm->degree = q->degree;
        newterm->coef = q->coef;
        newterm->tail = addPolynomial(p, q->tail);
        return newterm;
    }
    if(q->degree < p->degree){
        newterm->degree = p->degree;
        newterm->coef = p->coef;
        newterm->tail = addPolynomial(p->tail, q);
        return newterm;
    }
    newterm->degree = p->degree;
    newterm->coef = p->coef + q->coef;
    newterm->tail = addPolynomial(p->tail, q->tail);
    return newterm;
}

//Agrego un termino al polinomio
int addTerm(polyADT *poly, float NewCoef, int NewDegree) {
    if(*poly == NULL || (*poly)->degree < degree) {     //Si el polinomio esta vacio o el grado del polinomio es menor al grado del termino que quiero agregar
        polyADT newterm = malloc(sizeof(polyCDT));
        if(newterm == NULL) {
            return 0;
        }
        newterm->coef = NewCoef;
        newterm->degree = NewDegree;
        newterm->tail = *poly;
        *poly = newterm;
        return 1;
    }
    if((*poly)->degree == degree) {
        return 0;
    }
    return addTerm(&(*poly)->tail, coef, degree);
}


//--------Otra Version(Hecha por Gero))--------


static polyADT addTermRec(polyADT poly, float coef, int degree, int *exists) {
    if (isEmpty(poly) || poly->degree < degree) {
        polyADT newCoef = malloc(sizeof(polyCDT));
        newCoef->degree = degree;
        newCoef->coef = coef;
        newCoef->tail = poly;
        return newCoef;
    }
    if (poly->degree == degree) {
        *exists = 1;
        return poly;
    }
    poly->tail = addTermRec(poly->tail, coef, degree, exists);
    return poly;
}

int addTerm(polyADT *poly, float coef, int degree) {
    int exists = 0;
    *poly = addTermRec(*poly, coef, degree, &exists);
    return !exists;
}