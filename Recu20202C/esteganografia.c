#include <stdio.h>
#include <assert.h>

void hideArray(const int * vIn, size_t dim, size_t salto, int * vOut) {
	if(salto == 0) {
		salto = 1;
	}
	for(int i = 0, k = 0; i < salto && k < dim; i++) { // k < dim o i < dim
		for(int j = i; j < dim; j += salto) {
			vOut[k++] = vIn[j];
		}
	}
}

/**
 * Tester
 */
static void
assertArrayEquals(const int * expected, const int * actual, size_t dim) {
	for(int i = 0; i < dim; i++) {
		assert(expected[i] == actual[i]);
	}
}

int
main(void) {
	int v1[] = {1,2,3,4,5,6,7,8,9};
	int dim1 = sizeof(v1)/sizeof(v1[0]);

	/**
	 * Arreglo = [1,2,3,4,5,6,7,8,9]
	 * salto = 2
	 * Nuevo = [1,3,5,7,9,2,4,6,8]
	**/
	int ex1Actual[dim1];
	int ex1Expected[] = {1,3,5,7,9,2,4,6,8};
	hideArray(v1, dim1, 2, ex1Actual);
	assertArrayEquals(ex1Expected, ex1Actual, dim1);

	/**
	 * Arreglo = [1,2,3,4,5,6,7,8,9]
	 * salto = 3
	 * Nuevo = [1,4,7,2,5,8,3,6,9]
	**/
	int ex2Actual[dim1];
	int ex2Expected[] = {1,4,7,2,5,8,3,6,9};
	hideArray(v1, dim1, 3, ex2Actual);
	assertArrayEquals(ex2Expected, ex2Actual, dim1);

	int v2[] = {1,2,3,4,5,6,7,8};
	int dim2 = sizeof(v2)/sizeof(v2[0]);

	/**
	 * Arreglo = [1,2,3,4,5,6,7,8]
	 * salto = 3
	 * Nuevo = [1,4,7,2,5,8,3,6]
	**/
	int ex3Actual[dim2];
	int ex3Expected[] = {1,4,7,2,5,8,3,6};
	hideArray(v2, dim2, 3, ex3Actual);
	assertArrayEquals(ex3Expected, ex3Actual, dim2);

	/**
	 * Si el salto fuera cero o mayor a la dimensión,
	 * el vector de salida será igual al vector de entrada
	**/
	int ex4Actual[dim1];
	hideArray(v1, dim1, 0, ex4Actual);
	assertArrayEquals(v1, ex4Actual, dim1);
	int ex5Actual[dim2];
	hideArray(v2, dim2, 0, ex5Actual);
	assertArrayEquals(v2, ex5Actual, dim2);

	int ex6Actual[dim1];
	hideArray(v1, dim1, 10, ex6Actual);
	assertArrayEquals(v1, ex6Actual, dim1);
	int ex7Actual[dim2];
	hideArray(v2, dim2, 9, ex7Actual);
	assertArrayEquals(v2, ex7Actual, dim2);

	printf("OK!");
}