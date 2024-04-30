#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Binary_Search_Tree.h"


struct cep {
    char cep[25], cidade[25], sigla[255], endereco[255];
};

int main() {
    int num;
    char busca[25];
    Cep *k;
    Dic arv, arv2;
    criarArvore(&arv);

    insereArvore(&arv);
    do {
        printf("1-Pesquisar por CEP\n");
        printf("2-Apresentar Maior, Menor, Percurso e encerrar.\n");
        scanf("%d", &num);
        getchar();

        if (num == 1) {
            printf("Digite o CEP pelo qual deseja procurar: ");
            fgets(busca, sizeof(busca), stdin);
            busca[strcspn(busca, "\n")] = '\0'; 

            k = pesquisaArvore(busca, &arv);
            if (k != NULL) {
              printf("Dados do CEP: %s, %s, %s, %s\n\n", k->cep, k->cidade, k->endereco, k->sigla);
            } else {
              printf("CEP não encontrado na árvore.\n");
            }
        }
    } while (num != 2);

  
    printf("Altura da árvore é: %d\n", achaAltura(&arv));

    Cep *c = maiorElemArvore(&arv);
    Cep *v = menorElemArvore(&arv);
    printf("O maior cep é o de CEP %s\n", c->cep);
    printf("O menor cep é o de CEP %s\n", v->cep);
  

    criarArvore(&arv2);
    insereArvore20(&arv2);
    Central(&arv2);
    printf("prefixado\n");
    PreFixado(&arv2);
    printf("posfixado\n");
    PosFixado(&arv2);

    return 0;
}
