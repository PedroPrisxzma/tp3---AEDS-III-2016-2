#include <stdio.h>
#include <stdlib.h>
#include "monta.h"

//alocação dinâmica do grid
void aloca_grid(int ***grid, int m, int n){
  int i;
  *grid = (int **) calloc(m, sizeof(int *));
  for(i = 0; i < m; i++){
    (*grid)[i] = (int *) calloc(n+2, sizeof(int));
  }
}

//libera a memoria do grid
void desaloca_grid(int **grid, int m){
  int i;
  for(i = 0; i < m; i++){
    free(grid[i]);
  }
  free(grid);
}

//Monta a matriz inicial do programa, contendo duas colunas extras com 0s
void monta_grid(int **grid, int m, int n){
  int i, j;
  int pop;
  for(i = 0; i < m; i++){
    for(j = 0; j < n+2;j++){
      if(j == 0 || j == 1 ){
        grid[i][j] = 0;
      }
      else{
        scanf("%d", &pop);
        grid[i][j] = pop;
//        printf("grid[%d][%d] = %d\n", i,j,pop);
      }
    }
  }
}
