#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

void troca(int *a, int *b);

int esquerda(int i);

int direita(int i);

void shellSort(int vetor[], int n);

void refazHeapMax(int V[], int i, int compHeap);

void constroiHeapMax(int V[], int tamanho);

void heapSort(int V[], int tamanho);

#endif // HEAP_H_INCLUDED
