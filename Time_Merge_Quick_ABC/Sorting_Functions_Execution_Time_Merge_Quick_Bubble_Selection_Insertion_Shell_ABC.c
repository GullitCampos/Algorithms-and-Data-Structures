/*

    Program: Algorithms-and-Data-Structures

    Description: 
    
        Dados os métodos de ordenação estudados para organizar vetores de 
        números inteiros, o objetivo do exercício é construir uma tabela 
        de referência contendo o tempo obtido para cada método de ordenação, 
        considerando entrada de dados aleatória (usar geração aleatória de 
        números inteiros) e vetor de tamanho 10.000.

        Incrementar a tabela com os tempos para vetores de números inteiros com 
        os tamanhos 50.000 e 100.000, ainda considerando entrada de dados aleatória.
        
        Construir uma segunda tabela de referência contendo o número médio de 
        comparações e o número médio de trocasconsiderando entrada aleatória e 
        vetor de tamanho 10.000.
        
        Para esse experimento, utilize 10 vetores distintos.

        Exemplo
        Método ------------------Tempo
        BubbleSort               
        InsertionSort            
        SelectionSort            
        ShellSort                
        MergeSort
        QuickSort
        ABCSort
    
    Author: Gullit Damião Teixeira de Campos.
    Author: Rafael Rande Silva

    Date: 03/02/2024

  */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Sorting_Function_Merge_Quick_Bubble_Selection_Insertion_Shell_ABC.h"

int main(void) {

  int i = 0, N = 10000;
  int algoritmo = -1;
  float tempBubble = 0, tempSelection = 0, tempInsertion = 0, tempShell = 0;
  float tempMerge = 0, tempABC = 0, tempQuick = 0;
  int compBubble = 0, compSelection = 0, compInsertion = 0, compShell = 0, compMerge = 0, compABC = 0;
  int trocaBubble = 0, trocaSelection = 0, trocaInsertion = 0, trocaShell = 0, trocaMerge = 0, trocaABC = 0;
  float mediaTrocas = 0.0, mediaComparacoes = 0.0;

  int *v = (int *)malloc(N * sizeof(int));
  int *aux = (int *)malloc(N * sizeof(int));

  // Gerando valores aleatórios para o vetor
  srand(time(NULL));
  for (i = 0; i < N; i++) {
    v[i] = rand() % 100000;
  }

  for (i = 0; i < N; i++) {
    aux[i] = v[i];
  }

  while (algoritmo != 0) {

    printf("Escolha o algoritmo para ordenacao:\n\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Shell Sort\n");
    printf("5 - Merge Sort\n");
    printf("6 - ABC Sort\n");
    printf("7 - Quick Sort\n");
    printf("8 - Imprimir a tabela atualizada\n");
    printf("9 - Imprimir a tabela de comparacoes e trocas\n");
    printf("10 - Alterar o tamanho do vetor\n");
    printf("11 - Finalizar o programa\n");

    scanf("%d", &algoritmo);

    switch (algoritmo) {

    case 1:
      printf("Bubble Sort\n");
      // Medidor de tempo
      clock_t start_time = clock();

      bubbleSort(aux, N, &compBubble, &trocaBubble);

      clock_t end_time = clock();
      double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempBubble = execution_time;

      printf("Vetor organizado:");
      for (i = 0; i < N; i++) {
        printf("%d ", v[i]);
      }
      printf("\n");

      printf("Tempo de execução BubbleSort: %f segundos\n\n", execution_time);

      execution_time = 0;

      for (i = 0; i < N; i++) {
        v[i] = rand() % 100000;
      }

      
      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

      break;

    case 2:

      printf("Selection Sort\n");

      start_time = clock();

      selectionSort(aux, N, &compSelection, &trocaSelection);

      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempSelection = execution_time;

      printf("Vetor organizado:");
      for (i = 0; i < N; i++) {
        printf("%d ", aux[i]);
      }
      printf("\n");

      printf("Tempo de execução SelectionSort: %f segundos\n\n",
             execution_time);

      execution_time = 0;

      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

      break;

    case 3:

      printf("Insertion Sort\n");

      start_time = clock();

      insertionSort(aux, N, &compInsertion, &trocaInsertion);

      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempInsertion = execution_time;

      printf("Vetor organizado:");
      for (i = 0; i < N; i++) {
        printf("%d ", aux[i]);
      }
      printf("\n");

      printf("Tempo de execução InsertionSort: %f segundos\n\n", execution_time);

      execution_time = 0;

      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

      break;

    case 4:

      printf("Shell Sort\n");
      start_time = clock();

      Shellsort(aux, N, &compShell, &trocaShell);

      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempShell = execution_time;

      printf("Vetor organizado:");
      for (i = 0; i < N; i++) {
        printf("%d ", aux[i]);
      }
      printf("\n");

      printf("Tempo de execucao ShellSort: %f segundos\n\n", execution_time);

      execution_time = 0;

      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

      break;

    case 5:

      printf("Merge Sort\n");

      start_time = clock();

      mergesort(aux, N, &compMerge, &trocaMerge);

      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempMerge = execution_time;

      printf("Vetor organizado:");
      for (i = 0; i < N; i++) {
        printf("%d ", aux[i]);
      }

      printf("\n");

      printf("Tempo de execução MergeSort: %f segundos\n\n", execution_time);

      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

      break;

    case 6:

      printf("ABC Sort\n");

      start_time = clock();

      ABC_SORT(aux, 0, N - 1, &compABC, &trocaABC);

      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempABC = execution_time;

      printf("Vetor organizado:");
      for (i = 0; i < N; i++) {
        printf("%d ", aux[i]);
      }

      printf("\n");

      printf("Tempo de execução ABCSort: %f segundos\n\n", execution_time);

      for (i = 0; i < N; i++) {
        v[i] = rand() % 100000;
      }

      break; 

    case 7:

      printf("Quick Sort\n");

      start_time = clock();

      quicksort(aux, N);

      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempQuick = execution_time;

      printf("Vetor organizado:");
      for (i = 0; i < N; i++) {
        printf("%d ", aux[i]);
      }

      printf("\n");

      printf("Tempo de execução Quick Sort: %f segundos\n\n", execution_time);

      for (i = 0; i < N; i++) {
        v[i] = rand() % 100000;
      }

      break; 

    case 8:

      printf("\n\nTabela com vetor de %d elementos:\n", N);
      printf("\n\n");
      printf("Metodo \t\t Tempo \n\n");
      printf("BubbleSort: \t %f \n\n", tempBubble);
      printf("SelectionSort: \t %f \n\n", tempSelection);
      printf("InsertionSort: \t %f \n\n", tempInsertion);
      printf("ShellSort: \t\t %f \n\n", tempShell);
      printf("MergeSort: \t\t %f \n\n", tempMerge);
      printf("ABCSort: \t\t %f \n\n", tempABC);
      printf("QuickSort: \t\t %f \n\n", tempQuick);

      break;

    case 9:

      mediaTrocas = (trocaBubble + trocaSelection + trocaInsertion + trocaShell + trocaMerge + trocaABC) / 6;
      mediaComparacoes = (compBubble + compSelection + compInsertion + compShell + compMerge + compABC) / 6;
      
      printf("\n\nTabela com comparações e trocas com %d elementos:\n", N);
      printf("\n\n");
      printf("Metodo \t\t Comparacoes \t Trocas \n\n");
      printf("BubbleSort: \t %d \t %d \n\n", compBubble, trocaBubble);
      printf("selectionSort: \t %d \t %d \n\n", compSelection, trocaSelection);
      printf("insertionSort: \t %d \t %d \n\n", compInsertion, trocaInsertion);
      printf("ShellSort: \t\t %d \t %d \n\n", compShell, trocaShell);
      printf("MergeSort: \t\t %d \t %d \n\n", compMerge, trocaMerge);
      printf("ABCSort: \t\t %d \t %d \n\n", compABC, trocaABC);
      printf("Media de comparações: %.2f\n", mediaComparacoes);
      printf("Media de trocas: %.2f\n", mediaTrocas);
   
      break;

    case 10:

      printf("Informe o novo tamanho do vetor que deseja ordenar:");
      scanf("%d", &N);

      v = (int *)realloc(v, N * sizeof(int));

      // Gerando valores aleatórios para o vetor
      srand(time(NULL));
      for (i = 0; i < N; i++) {
        v[i] = rand() % 100000;
      }

      tempBubble = 0;
      tempSelection = 0;
      tempInsertion = 0;
      tempShell = 0;
      tempMerge = 0;
      tempABC = 0;

      break;

    case 11:
      printf("Programa Finalizado.");
      break;

    default:
      printf("Escolha invalida.");
      break;
    }
  }

  free(v);
  return 0;
}