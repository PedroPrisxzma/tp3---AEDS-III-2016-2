#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "monta.h"
#include "resolve.h"

int main(int argc, char *argv[]){
  int m, n, pt;
  int **grid;
  int *rlinhas;//vetor que com os máximos de cada linha
  scanf("%d %d", &m, &n);
  pt = argc;//uso para o argc, evita um erro de compilação do -Werror
  pt = atoi(argv[1]);//número de threads, agora num valor inteiro
  rlinhas = (int *) calloc(m+2, sizeof(int));
  aloca_grid(&grid, m, n);
  monta_grid(grid, m, n);
  paralelo(grid, rlinhas, m, n, pt);
  desaloca_grid(grid, m);
  free(rlinhas);
  return 0;
}
