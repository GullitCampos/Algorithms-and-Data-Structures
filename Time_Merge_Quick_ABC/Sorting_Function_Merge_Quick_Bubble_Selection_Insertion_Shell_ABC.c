#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Sorting_Function_Merge_Quick_Bubble_Selection_Insertion_Shell_ABC.h"

void troca(int v[], int i, int j) {
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

// Função para ordenar um vetor usando Bubble Sort
void bubbleSort(int arr[], int n, int *comparacoes, int *trocas) {

  int temp, i, j;
  for (i = 0; i < n - 1; i++) {
    (*comparacoes)++;
    for (j = 0; j < n - i - 1; j++) {
      (*comparacoes)++;
      if (arr[j] > arr[j + 1]) {
        (*comparacoes)++;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        (*trocas)++;
      }
    }
  }
}

// Função para ordenar um vetor usando SelectionSort
void selectionSort(int vetor[], int n, int *comparacoes, int *trocas) {
  int temp;
  int menor, i, j;

  for (i = 0; i < n - 1; i++) {
    (*comparacoes)++;
    menor = i;
    for (j = i + 1; j < n; j++) {
      (*comparacoes)++;
      if (vetor[j] < vetor[menor]) {
        (*comparacoes)++;
        menor = j;
      }
    }
    temp = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = temp;
    (*trocas)++;
  }
}

// Função para ordenar um vetor usando InsertionSort
void insertionSort(int vet[], int n, int *comparacoes, int *trocas) {
  int i, j, tmp;

  for (i = 1; i < n; i++) {
    (*comparacoes)++;
    tmp = vet[i];
    // coloca o item no lugar apropriado na sequência destino
    for (j = i - 1; j >= 0 && vet[j] > tmp; j--){
      *comparacoes += 2;
      vet[j + 1] = vet[j];
    }
    vet[j + 1] = tmp;
    (*trocas)++;
  }
}

// Função para ordenar um vetor usando ShellSort
void Shellsort(int vetor[], int n, int *comparacoes, int *trocas) {
  int i, j, h = 1;
  int aux;
  do {
    h = h * 3 + 1;
    (*comparacoes)++;
  } while (h < n); // determina o intervalo
  (*comparacoes)--;
  
  do {
    h /= 3;
    for (i = h; i < n; i++) { // insere o elemento na posição
      (*comparacoes)++;
      aux = vetor[i];         // correta no vetor
      j = i;
      while (vetor[j - h] > aux) {
        (*comparacoes)++;
        vetor[j] = vetor[j - h];
        j -= h;
        if (j < h){
          (*comparacoes)++;
          break;
        }
        (*comparacoes)++;
      }
      vetor[j] = aux;
      (*trocas)++;
    }
    (*comparacoes)++;
  } while (h != 1);
}

void merge(int vetor[], int aux[], int esq, int meio, int dir, int *comparacoes, int *trocas) {

  int i, esq_fim, n;
  esq_fim = meio - 1;
  n = dir - esq + 1;
  i = esq;

  while (esq <= esq_fim && meio <= dir) {
    *comparacoes+=2;
    if (vetor[esq] <= vetor[meio]) {
      aux[i++] = vetor[esq++];
    } else {
      aux[i++] = vetor[meio++];
    }
    (*trocas)++;
  }

  while (esq <= esq_fim) {
    (*comparacoes)++;
    aux[i++] = vetor[esq++];
  }

  while (meio <= dir) {
    (*comparacoes)++;
    aux[i++] = vetor[meio++];
  }

  for (i = 0; i < n; i++) {
    (*comparacoes)++;
    vetor[dir] = aux[dir];
    dir--;
  }
}

void m_sort(int vetor[], int aux[], int esq, int dir, int *comparacoes, int *trocas) {
  int meio;

  if (dir > esq) {
    meio = (dir + esq) / 2;

    m_sort(vetor, aux, esq, meio, comparacoes, trocas);
    m_sort(vetor, aux, meio + 1, dir, comparacoes, trocas);
    merge(vetor, aux, esq, meio + 1, dir, comparacoes, trocas);
    
  }
}



void mergesort(int *v, int n, int *comparacoes, int *trocas) {

  int aux[n];
  m_sort(v, aux, 0, n - 1, comparacoes, trocas);
  
}

void ABC_SORT(int *v, int i, int j, int *comparacoes, int *trocas) {

  int temp = 0, k = 0;
  if (v[i] > v[j]) {

    (*comparacoes)++;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    (*trocas)++;
  }

  if (i + 1 >= j)
    return;
  
  k = (j - i + 1) / 3;
  ABC_SORT(v, i, j - k, comparacoes, trocas);
  ABC_SORT(v, i + k, j, comparacoes, trocas);
  ABC_SORT(v, i, j - k, comparacoes, trocas);
}

int particao(int vetor[], int esq, int dir) {
  
  int i, j, pivo, temp;

  pivo = vetor[(esq + dir) / 2];
  i = esq - 1;
  j = dir + 1;

  while (i < j) {
    do { i++; } while (vetor[i] < pivo);

    do { j--; } while (vetor[j] > pivo);

    if (i < j) { troca(vetor, i, j); }
    
  }

  return (j);
}

void q_sort (int vetor[], int esq, int dir) {

  int meio;
  if (esq < dir) {
    
    meio = particao (vetor, esq, dir);
    q_sort (vetor, esq, meio);
    q_sort (vetor, meio + 1, dir);

  }

}

void quicksort (int vetor[], int n) {

  q_sort (vetor, 0, n-1);

}
