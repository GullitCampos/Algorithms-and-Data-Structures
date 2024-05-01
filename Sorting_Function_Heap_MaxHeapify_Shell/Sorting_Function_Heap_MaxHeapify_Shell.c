#include <stdio.h>
#include <stdlib.h>
#include "Sorting_Function_Heap_MaxHeapify_Shell.h"

void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int esquerda(int i) {
    return 2 * i;
}

int direita(int i) {
    return 2 * i + 1;
}

void shellSort(int vetor[], int n) {
  int i, j, h = 1;
  int aux;
  do {
    h = h * 3 + 1;
  } while (h < n);

  do {
    h /= 3;
    for (i = h; i < n; i++) {

      aux = vetor[i];
      j = i;
      while (vetor[j - h] > aux) {

        vetor[j] = vetor[j - h];
        j -= h;
        if (j < h){
          break;
        }
      }
      vetor[j] = aux;
    }
  } while (h != 1);
}

void refazHeapMax(int V[], int i, int tamanho) {

  int esq, dir, maior;

  esq = esquerda(i);
  dir = direita(i);

  while ((i >= 0) && ((esq < tamanho && V[esq] > V[i]) || (dir < tamanho && V[dir] > V[i]))) {

    esq = esquerda(i);
    dir = direita(i);

    maior = i;

    if (esq < tamanho && V[esq] > V[i]) {
      maior = esq;
    }
    if (dir < tamanho && V[dir] > V[maior]) {

      maior = dir;

    }

    if (maior != i) {

      troca(&V[i], &V[maior]);
      i = maior;

    }
  }
}

void constroiHeapMax(int V[], int tamanho) {
  for(int i = tamanho / 2 - 1; i >= 0; i--)
    refazHeapMax(V, i, tamanho);
}

void heapSort(int V[], int tamanho) {
  constroiHeapMax(V, tamanho);
  for (int i = tamanho - 1; i > 0; --i) {
    troca(&V[0], &V[i]);
    refazHeapMax(V, 0, i);
  }
}




