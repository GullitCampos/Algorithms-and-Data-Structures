/*

    Program: Algorithms-and-Data-Structures

    Description: 
    
        
    
    Author: Gullit Damião Teixeira de Campos.
    Author: Rafael Rande Silva

    Date: 03/02/2024

  */



#include <stdio.h>
#include <stdlib.h>
#include "Sorting_Function_Heap_Shell.h"


int esquerda(int i) {
    return 2 * i + 1;
}

int direita(int i) {
    return 2 * i + 2;
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

void refazHeapMax(int V[], int i, int compHeap){

    int esq, dir, maior, temp;
    esq = esquerda(i);
    dir = direita(i);

    if(esq < compHeap && V[esq] > V[i]) {
        maior = esq;
    } else {
        maior = i;
    }
    if(dir < compHeap && V[dir] > V[maior]) {
        maior = dir;
    }
    if(maior != i) {
        temp = V[i];
        V[i] = V[maior];
        V[maior] = temp;
        refazHeapMax(V, maior, compHeap);
    }
}

void constroiHeapMax(int V[], int tamanho) {
    int compHeap = tamanho;
    for(int i = tamanho / 2 - 1; i >= 0; i--)
        refazHeapMax(V, i, compHeap);
}

void heapSort(int V[], int tamanho) {
    int i, compHeap, temp;
    compHeap = tamanho;
    constroiHeapMax(V, tamanho);
    for(i = tamanho - 1; i > 0; --i) {
        temp = V[0];
        V[0] = V[i];
        V[i] = temp;
        compHeap--;
        refazHeapMax(V, 0, compHeap);
    }
}


