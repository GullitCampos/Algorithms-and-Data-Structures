/*

    Program: Algorithms-and-Data-Structures

    Description: 
    
    Dados os métodos de ordenação estudados para organizar vetores de 
    números inteiros, o objetivo do exercício é construir uma tabela 
    de referência contendo o tempo obtido para cada método de ordenação, 
    considerando entrada de dados aleatória (usar geração aleatória de 
    números inteiros) e vetor de tamanho 10.000.
    
        Exemplo
        Método ------------------Tempo
        BubbleSort               0.0020 
        InsertionSort            0.0018
        SelectionSort            0.0026
        ShellSort                0.0001
    
    Author: Gullit Damião Teixeira de Campos.
    Author: Rafael Rande Silva

    Date: 26/01/2024

  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Sorting_Function_Bubble_Selection_Insertion_Shell.h"

#define N 10000

int main(void) {
  int i;
  float tempBubble = 0, tempSelection = 0, tempInsertion = 0, tempShell = 0;
  int *v = (int *)malloc(N * sizeof(int));

  // Gerando valores aleatórios para o vetor
  srand(time(NULL));
  for (i = 0; i < N; i++) {
    v[i] = rand() % 10000;
  }

  // Medidor de tempo
  clock_t start_time = clock();

  bubbleSort(v, N);

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
    v[i] = rand() % 10000;
  }

  for (i = 0; i < N; i++) {
    v[i] = rand() % 10000;
  }

  start_time = clock();

  selectionSort(v, N);

  end_time = clock();
  execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  tempSelection = execution_time;

  printf("Vetor organizado:");
  for (i = 0; i < N; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  printf("Tempo de execução SelectionSort: %f segundos\n\n", execution_time);

  execution_time = 0;

  for (i = 0; i < N; i++) {
    v[i] = rand() % 10000;
  }

  start_time = clock();

  insertionSort(v, N);

  end_time = clock();
  execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  tempInsertion = execution_time;

  printf("Vetor organizado:");
  for (i = 0; i < N; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  printf("Tempo de execução InsertionSort: %f segundos\n\n", execution_time);

  execution_time = 0;

  for (i = 0; i < N; i++) {
    v[i] = rand() % 10000;
  }

  start_time = clock();

  Shellsort(v, N);

  end_time = clock();
  execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  tempShell = execution_time;

  printf("Vetor organizado:");
  for (i = 0; i < N; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  printf("Tempo de execucao ShellSort: %f segundos\n\n", execution_time);

  printf("\n\n");

  printf("Metodo \t\t Tempo \n\n");
  printf("BubbleSort: \t %f \n\n", tempBubble);
  printf("SelectionSort: \t %f \n\n", tempSelection);
  printf("InsertionSort: \t %f \n\n", tempInsertion);
  printf("ShellSort: \t\t %f \n\n", tempShell);
}