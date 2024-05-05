/*

    Program: Algorithms-and-Data-Structures

    Description: 
    
    Implementar os algoritmos: Quicksort básico, Quicksort aleatorizado, 
    Quicksort com mediana de três, Quicksort com partição em três vias
    Criar quatro vetores (Sequência aleatória, Sequência ordenada, Sequência
    invertida, Sequência com muitas repetições) de números inteiros com
     tamanhos 5.000 e 50.000.

     Medir os tempos de execução para cada algoritmo e tipo/tamanho de vetor.
    
    Author: Gullit Damião Teixeira de Campos.
    Author: Rafael Rande Silva

    Date: 19/02/2024

  */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variations_QuickSort.h"

int main(void) {

  int N = 0;
  printf ("Digite o tamanho do vetor desejado:\n");
  scanf("%d", &N);

  float tempQuickBasico = 0, tempQuickAleatorizado = 0, tempQuickMediana = 0, tempQuickTresPartes = 0;
  int i = 0;
  int j = N-1;
  int algoritmo = -1, tpEntrada = -1;
  clock_t start_time, end_time;
  double execution_time = 0;

  int *v = (int *)malloc(N * sizeof(int));
  int *aux = (int *)malloc(N * sizeof(int));

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
  printf("2 - Ordenar vetor com Quick Sort basico\n");
  printf("3 - Ordenar vetor com Quick Sort Aleatorizado\n");
  printf("4 - Ordenar vetor com Quick Sort mediana de tres\n");
  printf("5 - Ordenar vetor com Quick Sort tres vias\n");
  printf("6 - Imprimir a tabela de tempo\n");
  printf("7 - Alterar o tamanho do vetor\n");
  printf("8 - Finalizar o programa\n");

  scanf("%d", &algoritmo);

  switch(algoritmo){

    case 1:

        printf("\nEscolha uma das opcoes de entrada:\n");
        printf("1 - Aleatoria\n");
        printf("2 - Ascendente\n");
        printf("3 - Descendente\n");
        printf("4 - Vetor com muitas repetições\n");

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

              //ordenando vetor para ficar em ordem crescente
              quickSort_tres_partes(aux, 0, N-1);

              break;

            case 3:

              srand(time(NULL));
              for (int i = 0; i < N; i++) {
                v[i] = rand() % (N * 10);
              };

              for (i = 0; i < N; i++) {
                aux[i] = v[i];
              }

              //ordenando o vetor
              quickSort_tres_partes(aux, 0, N-1);

              //invertendo o vetor para ficam em ordem decrescente
              aux = inverteVetor(aux, N);

              //imprimindo vetor para confirmar que foi invertido
              for (i = 0; i < N; i++) {

                printf("%d ", aux[i]);

              }

              system("pause");

              break;

            case 4:

              srand(time(NULL));
              for (int i = 0; i < N; i++) {
                v[i] = rand() % (N / 10);
              };

              for (i = 0; i < N; i++) {
                aux[i] = v[i];
              }

              break;

            default:
              printf("Opcao invalida\n");
              break;

          }
      break;

    case 2:

      //Execucao Quick Sort básico
      start_time = clock();

      quickSort(aux, 0, N-1);

      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempQuickBasico = execution_time;

      /*for (i = 0; i < N; i++) {

          printf("Vetor ordenado pelo Quick Sort basico:");
          printf("%d ", aux[i]);

        }

      system("pause");*/

      printf("\nTempo de execução Quick Sort basico: %f segundos\n", tempQuickBasico);


      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

      break;

    case 3:

      //Execucao Quick Sort aleatorizado
      start_time = clock();
  
      quicksort_aleatorizado(aux, 0, N-1);
  
      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempQuickAleatorizado = execution_time;
  
      /*for (i = 0; i < N; i++) {
  
          printf("Vetor ordenado pelo Quick Sort aleatorizado:");
          printf("%d ", aux[i]);
  
        }
  
      system("pause");*/
  
      printf("\nTempo de execução Quick Sort aleatorizado: %f segundos\n", tempQuickAleatorizado);
  
  
      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }
  
      break;

    case 4:

      //Execucao Quick Sort mediana de tres
      start_time = clock();
  
      quicksort_mediana_tres(aux, 0, N-1);
  
      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempQuickMediana = execution_time;
  
      /*for (i = 0; i < N; i++) {
  
          printf("Vetor ordenado pelo Quick Sort mediana de tres:");
          printf("%d ", aux[i]);
  
        }
  
      system("pause");*/
  
      printf("\nTempo de execução Quick Sort mediana de tres: %f segundos\n", tempQuickMediana);
  
  
      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }
  
      break;

    case 5:

      //Execucao Quick Sort tres partes
      start_time = clock();
  
      quickSort_tres_partes(aux, 0, N-1);
  
      end_time = clock();
      execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
      tempQuickTresPartes = execution_time;
  
      /*for (i = 0; i < N; i++) {
  
          printf("Vetor ordenado pelo Quick Sort tres partes:");
          printf("%d ", aux[i]);
  
        }
  
      system("pause");*/
  
      printf("\nTempo de execução Quick Sort tres partes: %f segundos\n", tempQuickTresPartes);
  
  
      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }
  
      break;

    case 6:

      printf("\n\nTabela com vetor de %d elementos:\n", N);
      printf("\n\n");
      printf("Metodo \t\t Tempo \n\n");
      printf("Quick Sort basico: \t\t %f \n\n", tempQuickBasico);
      printf("Quick Sort aleatorizado: \t\t %f \n\n", tempQuickAleatorizado);
      printf("Quick Sort mediana de tres: \t %f \n\n", tempQuickMediana);
      printf("Quick Sort tres partes: \t\t %f \n\n", tempQuickTresPartes);
      break;

    case 7:

      printf("Informe o novo tamanho do vetor que deseja ordenar:");
      scanf("%d", &N);

      v = (int *)realloc(v, N * sizeof(int));
      aux = (int *)realloc(aux, N * sizeof(int));

      // Gerando valores aleatórios para o vetor
      srand(time(NULL));
      for (i = 0; i < N; i++) {
        v[i] = rand() % (N * 10);
      }

      for (i = 0; i < N; i++) {
        aux[i] = v[i];
      }

      tempQuickBasico = 0, tempQuickAleatorizado = 0, tempQuickMediana = 0, tempQuickTresPartes = 0;
      
      break;

    case 8:

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

  return 0;

}
