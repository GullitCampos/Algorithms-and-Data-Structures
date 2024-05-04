#ifndef FUNCORD_H_INCLUDED
#define FUNCORD_H_INCLUDED

void troca(int v[], int i, int j);

// Função para ordenar um vetor usando Bubble Sort
void bubbleSort(int arr[], int n, int *comparacoes, int *trocas);

// Função para ordenar um vetor usando SelectionSort
void selectionSort(int vetor[], int n, int *comparacoes, int *trocas);

// Função para ordenar um vetor usando InsertionSort
void insertionSort(int vet[], int n, int *comparacoes, int *trocas);

// Função para ordenar um vetor usando ShellSort
void Shellsort(int vetor[], int n, int *comparacoes, int *trocas);

void merge(int vetor[], int aux[], int esq, int meio, int dir, int *comparacoes, int *trocas);

void m_sort(int vetor[], int aux[], int esq, int dir, int *comparacoes, int *trocas);

void mergesort(int *v, int n, int *comparacoes, int *trocas);

void ABC_SORT(int *v, int i, int j, int *comparacoes, int *trocas);

int particao(int vetor[], int esq, int dir);

void q_sort (int vetor[], int esq, int dir);

void quicksort (int vetor[], int n);

#endif // FUNCORD_H_INCLUDED
