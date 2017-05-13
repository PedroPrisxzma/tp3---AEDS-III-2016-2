#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "resolve.h"

//função que é executada em cada pthread, para achar o máximo de cada linha
void* func_paralela(void *x){
  int i = 0, j = 2;
  pacotinho *pacote;
  pacote = (pacotinho*)x;
  while(j < pacote->colunas+2){//Faz a parte dos máximos v[i] = max(v[i]+v[i-2], v[i-1])
    if(pacote->linha[j] + pacote->linha[i] > pacote->linha[j-1]){
      pacote->linha[j] = pacote->linha[j] + pacote->linha[i];
    }
    else{
      pacote->linha[j] = pacote->linha[j-1];
    }
    i++;
    j++;
  }
  pacote->max_linha[pacote->number+2] = pacote->linha[pacote->colunas+1];

  return 0;
}

//Organiza o paralelismo do código
void paralelo(int **grid, int *rlinhas, int m, int n, int pt){
  int i = 0, j = 0;
  int num;//número atual de threads
  int resp;//máximo da matriz
  pacotinho pacotinhos[pt];//cria-se estruturas que serão usadas junto das pthreads.
  pthread_t threads[pt];
  while(j < m){//certifica que olharemos todas linhas
    num = 0;
    for(i = 0; i < pt; i++){//aloca uma pthread para uma linha respeitando o limite de pthreads
      if(j >= m){
        break;
      }
      pacotinhos[i].linha = grid[j];
      pacotinhos[i].max_linha = rlinhas;
      pacotinhos[i].colunas = n;
      pacotinhos[i].number = j;
      pthread_create(&threads[i], NULL, func_paralela, &pacotinhos[i]);
      num++;
      j++;
    }
    for(i = 0; i < num; i++){//garante a finalização das threads
      pthread_join(threads[i], NULL);
    }
  }
  i = 0;
  j = 2;
  while(j < m+2){//acha o máximo póssivel do vetor contendo o máximo de cada linha
    if(rlinhas[j] + rlinhas[i] > rlinhas[j-1]){
      rlinhas[j] = rlinhas[j] + rlinhas[i];
    }
    else{
      rlinhas[j] = rlinhas[j-1];
    }
    i++;
    j++;
  }
  resp = rlinhas[m+1];
  printf("%d\n", resp);
}
