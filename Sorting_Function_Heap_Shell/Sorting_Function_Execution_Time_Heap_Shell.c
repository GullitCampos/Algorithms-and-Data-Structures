/*

    Program: Algorithms-and-Data-Structures

    Description: 
    
        Implemente o algoritmo heapsort discutido em sala de aula para 
        organizar vetores de números inteiros e compare o seu desempenho 
        com o algoritmo shellsort. Para realizar essa comparação, construa 
        uma tabela de referência contendo o tempo obtido para cada método 
        de ordenação, considerando:
        
        a)três tipos de entrada de dados: aleatória, em ordem ascendente e em 
        ordem descendente
        b)para cada tipo de entrada de dados, use pelo menos três tamanhos de 
        entrada iniciando com vetor de tamanho 10.000.Deve ser possível escolher 
        o tipo de entrada de dados e o tamanho do vetor por meio de um menu de opções. 
        
        Na comparação dos métodos, discuta as vantagens e desvantagens observadas. 
        
    
    Author: Gullit Damião Teixeira de Campos.
    Author: Rafael Rande Silva

    Date: 10/02/2024

  */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorting_Function_Heap_Shell.h"

int main(void) {

  int N = 0;
  printf ("Digite o tamanho do vetor desejado:\n");
  scanf("%d", &N);

  float tempShell = 0, tempShellAleatorio = 0, tempShellAscendente = 0, tempShellDescendente = 0, tempHeap = 0, tempHeapAleatorio = 0, tempHeapAscendente = 0, tempHeapDescendente = 0;
  int i = 0;
  int j = N-1;
  int algoritmo = -1, tpEntrada = -1;
  clock_t start_time, end_time;
  double execution_time = 0;

  int *v = (int *)malloc(N * sizeof(int));
  int *aux = (int *)malloc(N * sizeof(int));
  int *descendente = (int *)malloc(N * sizeof(int));

  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    v[i] = rand() % (N * 10);
  };

  for (i = 0; i < N; i++) {
    aux[i] = v[i];
  }

  while (algoritmo != 0) {

  printf("\nEscolha a opcao do menu:\n\n");
  printf("1 - Escolha o tipo de entrada\n");
  printf("2 - Ordenar vetor com Heap e Shell\n");
  printf("3 - Imprimir a tabela de tempo\n");
  printf("4 - Alterar o tamanho do vetor\n");
  printf("5 - Finalizar o programa\n");

  scanf("%d", &algoritmo);

  switch(algoritmo){

    case 1:

        printf("\nEscolha uma das opcoes de entrada:");
        printf("\n1 - Aleatoria\n");
        printf("2 - Ascendente\n");
        printf("3 - Descendente\n");

        scanf("%d", &tpEntrada);

          switch(tpEntrada){

            case 1:

              srand(time(NULL));
              for (int i = 0; i < N; i++) {
                v[i] = rand() % (N * 10);
              };

              for (i = 0; i < N; i++) {
                aux[i] = v[i];
              }

              break;

            case 2:

              srand(time(NULL));
              for (int i = 0; i < N; i++) {
                v[i] = rand() % (N * 10);
              };

              for (i = 0; i < N; i++) {
                aux[i] = v[i];
              }

              heapSort(aux, N);

              break;

            case 3:

              srand(time(NULL));
              for (int i = 0; i < N; i++) {
                v[i] = rand() % (N * 10);
              };

              for (i = 0; i < N; i++) {
                aux[i] = v[i];
              }

              heapSort(aux, N);

              for (i = 0; i < N; i++) {
                descendente[j] = aux[i];
                j--;
              }

              break;

            default:
              printf("Opcao invalida\n");
              break;

          }
      break;

    case 2:

      if(tpEntrada==3){

          //Execucao Shell Sort
            start_time = clock();

            shellSort(descendente, N);

            end_time = clock();
            execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            tempShell = execution_time;


            for (i = 0; i < N; i++) {
              aux[i] = v[i];
            }

            //Execucao Heap Sort
            start_time = clock();

            heapSort(descendente, N);

            end_time = clock();
            execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            tempHeap = execution_time;

      } else{

            //Execucao Shell Sort
            start_time = clock();

            shellSort(aux, N);

            end_time = clock();
            execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            tempShell = execution_time;


            for (i = 0; i < N; i++) {
              aux[i] = v[i];
            }

            //Execucao Heap Sort
            start_time = clock();

            heapSort(aux, N);

            end_time = clock();
            execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            tempHeap = execution_time;

      }

      if(tpEntrada==1){
        tempShellAleatorio = tempShell;
        tempHeapAleatorio = tempHeap;
        printf("\nTempo de execução Shell Sort com vetor aleatorio: %f segundos\n", tempShellAleatorio);
        printf("\nTempo de execução Heap Sort com vetor aleatorio: %f segundos\n", tempHeapAleatorio);
      }else if(tpEntrada==2){
        tempShellAscendente = tempShell;
        tempHeapAscendente = tempHeap;
        printf("\nTempo de execução Shell Sort com vetor Ascendente: %f segundos\n", tempShellAscendente);
        printf("\nTempo de execução Heap Sort com vetor Ascendente: %f segundos\n", tempHeapAscendente);
      } else if(tpEntrada==3){
        tempShellDescendente = tempShell;
        tempHeapDescendente = tempHeap;
        printf("\nTempo de execução Shell Sort com vetor Descendente: %f segundos\n", tempShellDescendente);
        printf("\nTempo de execução Heap Sort com vetor Descendente: %f segundos\n", tempHeapDescendente);
      } else{
        printf("\nOpcao invalida\n");
      }

      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

    break;

    case 3:

      printf("\n\nTabela com vetor de %d elementos:\n", N);
      printf("\n\n");
      printf("Metodo \t\t Tempo \n\n");
      printf("Shell Sort aleatorio: \t\t %f \n\n", tempShellAleatorio);
      printf("Shell Sort ascendente: \t\t %f \n\n", tempShellAscendente);
      printf("Shell Sort descendente: \t %f \n\n", tempShellDescendente);
      printf("Heap Sort aleatorio: \t\t %f \n\n", tempHeapAleatorio);
      printf("Heap Sort ascendente: \t\t %f \n\n", tempHeapAscendente);
      printf("Heap Sort descendente: \t\t %f \n\n", tempHeapDescendente);
      break;

    case 4:

      printf("Informe o novo tamanho do vetor que deseja ordenar:");
      scanf("%d", &N);

      v = (int *)realloc(v, N * sizeof(int));
      aux = (int *)realloc(aux, N * sizeof(int));
      descendente = (int *)realloc(descendente, N * sizeof(int));

      // Gerando valores aleatórios para o vetor
      srand(time(NULL));
      for (i = 0; i < N; i++) {
        v[i] = rand() % (N * 10);
      }

      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

      tempShell = 0, tempShellAleatorio = 0, tempShellAscendente = 0, tempShellDescendente = 0, tempHeap = 0, tempHeapAleatorio = 0, tempHeapAscendente = 0, tempHeapDescendente = 0;

      break;

    case 5:

      printf("Programa finalizado");
      algoritmo = 0;
      break;

    default:

      printf("Opcao invalida\n");
      break;

    }

  }

      free(v);
      free(aux);
      free(descendente);

  return 0;

}
