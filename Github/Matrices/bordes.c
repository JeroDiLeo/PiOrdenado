#include <stdio.h>
#define M 6


int suma( int m[M][M], int borde){
    int suma=0;
    for( int i=0; i<M-borde-1; i++){
        suma += m[borde][i] + m[i][M-borde-1];
        suma += m[M-borde-1][i+1] + m[i+1][borde];
    }
return suma;
}

void bordes( int m[M][M], int sumas[]){
    for( int i=0; i<M/2; i++)
        sumas[i] = suma(m,i);
return;
}

int main(void)
{
  const int mat[M][M] = {
      {1, 1, 1, 1, 1, 1},
      {1, 2, 2, 2, 2, 1},
      {1, 2, 3, 3, 2, 1},
      {1, 2, 3, 3, 2, 1},
      {1, 2, 2, 2, 2, 1},
      {1, 1, 1, 1, 1, 1}
  };
  int borders[M / 2];

  sum_borders(mat, borders);

  for (unsigned int i = 0; i < M / 2; i++)
  {
    printf("Border %d: %d\n", i, borders[i]);
  }

  return 0;
}