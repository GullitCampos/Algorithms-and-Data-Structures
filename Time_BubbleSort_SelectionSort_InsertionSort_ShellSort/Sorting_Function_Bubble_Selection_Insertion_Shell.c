#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Sorting_Function_Bubble_Selection_Insertion_Shell.h"

// Função para ordenar um vetor usando Bubble Sort
void bubbleSort(int arr[], int n) {
  int temp, i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Função para ordenar um vetor usando SelectionSort
void selectionSort(int vetor[], int n) {
  int temp;
  int menor, i, j;

  for (i = 0; i < n - 1; i++) {
    menor = i;
    for (j = i + 1; j < n; j++) {
      if (vetor[j] < vetor[menor]) {
        menor = j;
      }
    }
    temp = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = temp;
  }
}

// Função para ordenar um vetor usando InsertionSort
void insertionSort(int vet[], int n) {
  int i, j, tmp;

  for (i = 1; i < n; i++) {
    tmp = vet[i];
    // coloca o item no lugar apropriado na sequência destino
    for (j = i - 1; j >= 0 && vet[j] > tmp; j--)
      vet[j + 1] = vet[j];
    vet[j + 1] = tmp;
  }
}

// Função para ordenar um vetor usando ShellSort
void Shellsort(int vetor[], int n) {
  int i, j, h = 1;
  int aux;
  do {
    h = h * 3 + 1;
  } while (h < n); // determina o intervalo
  do {
    h /= 3;
    for (i = h; i < n; i++) { // insere o elemento na posição
      aux = vetor[i];         // correta no vetor
      j = i;
      while (vetor[j - h] > aux) {
        vetor[j] = vetor[j - h];
        j -= h;
        if (j < h)
          break;
      }
      vetor[j] = aux;
    }
  } while (h != 1);
}