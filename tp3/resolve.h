//Definido uma estrutura auxiliar
//Utilizada como parâmetro para função das pthreads
typedef struct pacotinho{
  int *linha; //Representa a linha da matriz
  int *max_linha; //Representa o vetor que contém os máximos de cada linha
  int colunas; //Num de colunas da matriz
  int number; //Número que identifica a linha que estamos olhando
}pacotinho;

//função que organiza/administra o paralelismo
void paralelo(int **grid, int *rlinhas, int m, int n, int pt);
//função auxiliar das pthreads
void* func_paralela(void *x);
