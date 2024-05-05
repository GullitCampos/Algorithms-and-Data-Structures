#include <stdio.h>
#include <stdlib.h>
#include "Variations_QuickSort.h"

void troca(int v[], int a, int b) {
  
  int temp = v[a];
  v[a] = v[b];
  v[b] = temp;
  
}

int* inverteVetor(int v[], int n){

  int i = 0, j = n-1;
  int *aux = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {

    aux[j] = aux[i];
    j--;

  }

  return aux;
  
}

int particao(int vetor[], int esq, int dir) {
  int i, j, pivo;

  pivo = esq;
  for(i=esq+1; i<=dir; i++){
    if(vetor[i] < vetor[esq]){
      pivo++;
      troca(vetor, pivo, i);
    }
  }
  troca(vetor, esq, pivo);
  return (pivo);
  
}

void quickSort(int vetor[], int esq, int dir) {

  int i;
  if(esq>=dir) return;
  i = particao(vetor, esq, dir);
  quickSort (vetor, esq, i-1);
  quickSort (vetor, i+1, dir);

}

int pivo_aleatorio(int esq, int dir) {
  
  double r;
  
  r = (double) rand()/RAND_MAX;
  return (int)(esq + r*(dir-esq));

}

/* A função rand() gera um número pseudo-aleatório entre Dea
constante RAND_MAX. A constante RAND_MAX é 32762. */

  void quicksort_aleatorizado (int *v, int esq, int dir) {

    int i = 0;
    int pivo = 0;
    pivo = pivo_aleatorio(esq, dir);

    if (dir <= esq) return;
    troca(v, pivo, esq);
    i  = particao(v, esq, dir);
    quicksort_aleatorizado (v, esq, i-1);
    quicksort_aleatorizado (v, i+1, dir);

  }

void quicksort_mediana_tres (int v[], int esq, int dir){

  int i = 0;
  if(dir<=esq) return;
  
  troca(v, (esq+dir)/2, esq+1);
  
  if(v[esq] > v[esq+1]) 
    troca(v, esq, esq+1);

  if(v[esq] > v[dir]) 
    troca(v, esq, dir);

  if(v[esq+1] > v[dir]) 
    troca(v, esq+1, dir);

  i = particao(v, esq+1, dir-1);
  quicksort_mediana_tres(v, esq, i-1);
  quicksort_mediana_tres(v, i+1, dir);
    
}

void quickSort_tres_partes(int a[], int l, int r){
    
    int k, i=l-1,j=r,p=l-1, q = r;
    int v = a[r];
    if (r <= l) return;
    for (;;){
        
      while (a[++i] < v) ;
      while (v < a[--j])
        if (j == 1) break;
      if (i >= j) break;
      troca(a,i,j);
      if (a[i] == v) { p++; troca(a,p,i); }
      if (v == a[j]) { q--; troca(a,j,q); }
      
    }
        
    troca(a,i,r);
    j = i-1;
    i++;
    for (k = 1; k <= p; k++, j--) troca(a,k,j);
    for (k = r-1; k >= q; k--, i++) troca(a,i,k);
    quickSort_tres_partes(a, l, j);
    quickSort_tres_partes(a, i, r);

}
