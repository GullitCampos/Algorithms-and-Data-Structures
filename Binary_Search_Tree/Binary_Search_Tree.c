/*

    Program: Algorithms-and-Data-Structures

    Description: 
    
    Suponha um arquivo contendo entradas desordenadas para um conjunto de 
    CEPs de cidades brasileiras seguindo o formato: 
    
    CEP – sigla do estado – nome da cidade – endereço

    Exemplo do arquivo (.txt) contendo as entradas para o conjunto de CEPs:
    
    O exercício prático consiste na implementação de um programa em linguagem C 
    capaz de ler o arquivo texto, e preencher uma árvore binária de pesquisa 
    contendo estruturas de dados baseada em um TAD a partir dos códigos discutidos
     em aula.50


    ExercícioFaça um programa que implemente uma ÁRVORE BINÁRIA DE PESQUISA (ABB) 
    em linguagem C, com tipo abstrato de dados e alocação dinâmica, que tenha as seguintesfuncões:CriaçãoInserçãoRemoçãoPesquisa: Verificar se uma árvore 
    contém uma dada chave, retornando o endereçodo registro que contém a chave, 
    caso encontrada, ou null, caso contrário.Percursos: Exibir todos os valores
     de chaves de uma árvore considerando cada um dos tipos: central, pré-fixado 
     e pós-fixado.Altura: Para determinar a altura de uma ABB.Menor: Para encontrar
      o menor valor de chave. Deve retornar o endereço do registro que contém a chave, 
      ou null, caso contrário.Maior: Para encontrar o maior valor de chave. 
      Deve retornar o endereço do registroque contém a chave, ou null, caso contrário.51

    ExercícioNo programa principal: 1. Leia o arquivo texto completo e preencha uma ABB.

    Apresente pesquisas por CEP. Para cada CEP encontrado, deve-se exibir 
    na tela a respectiva entrada completa: CEP, sigla do estado, nome da cidade e endereço.
    
    Apresente a altura da ABB, a entrada completa do maior CEP e a entrada completa do 
    menor CEP.2. Leia as primeiras 20 linhas do arquivo texto e preencha uma ABB.
    
    Exiba os CEPs considerando os percursos central, pré-fixado e pós-fixado
    
    Author: Gullit Damião Teixeira de Campos.
    Author: Rafael Rande Silva

    Date: 19/02/2024

  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Binary_Search_Tree.h"

struct cep{
    char cep[25], cidade[25], sigla[255], endereco[255];
};

typedef struct no{
    Cep info;
    struct no *esq;
    struct no *dir;
    struct no *pai;
} No;

void criarArvore(Apont *x){
    *x = NULL;
}

void insereArvore(Apont *p) {
    FILE *fp = fopen("cep.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo cep.txt\n");
        return;
    }

    char linha[500]; 
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char cep[15], sigla[15], cidade[255], endereco[255];
        if (sscanf(linha, "%14[^;]; %14[^;]; %254[^;]; %254[^\n]", cep, sigla, cidade, endereco) != 4) {
            printf("Erro ao ler linha do arquivo\n");
            continue;
        }

        No *novo = (No*)malloc(sizeof(No));
        if (novo == NULL) {
            printf("Erro ao alocar memória\n");
            break;
        }

        strcpy(novo->info.cep, cep);
        strcpy(novo->info.sigla, sigla);
        strcpy(novo->info.cidade, cidade);
        strcpy(novo->info.endereco, endereco);
        novo->esq = NULL;
        novo->dir = NULL;

        Apont pai = NULL;
        Apont atual = *p;
        int encontrado = 0;
        while (atual != NULL) {
            pai = atual;
            if (strcmp(cep, atual->info.cep) < 0)
                atual = atual->esq;
            else if (strcmp(cep, atual->info.cep) > 0)
                atual = atual->dir;
            else {
                free(novo);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            if (pai == NULL)
                *p = novo;
            else if (strcmp(cep, pai->info.cep) < 0)
                pai->esq = novo;
            else
                pai->dir = novo;
        }
    }

    fclose(fp);
}


void insereArvore20(Apont *p){
    FILE *fp = fopen("cep.txt", "r");
    char cep[15], sigla[15], cidade[255], endereco[255];
    int count = 0;
    while (count < 20 && fscanf(fp, "%[^;]; %2[^;]; %[^;]; %[^;\n]\n", cep, sigla, cidade, endereco) != EOF){
        No *novo = (No*)malloc(sizeof(No));
        strcpy(novo->info.cep, cep);
        strcpy(novo->info.sigla, sigla);
        strcpy(novo->info.cidade, cidade);
        strcpy(novo->info.endereco, endereco);
        novo->esq = NULL;
        novo->dir = NULL;

        Apont pai = NULL;
        Apont atual = *p;
        while (atual != NULL) {
            pai = atual;
            if (strcmp(cep, atual->info.cep) < 0)
                atual = atual->esq;
            else if (strcmp(cep, atual->info.cep) > 0)
                atual = atual->dir;
            else {
                printf("Erro! Registrador ja existe\n");
                free(novo);
                break;
            }
        }

        if (pai == NULL)
            *p = novo;
        else if (strcmp(cep, pai->info.cep) < 0)
            pai->esq = novo;
        else
            pai->dir = novo;

        count++;
    }
    fclose(fp);
}

void retiraArvore(Cep x, Apont *p){
    Apont aux;
    if ((*p) == NULL) {
        printf("Erro! Registro nao encontrado na arvore\n");
        return;
    }

    if (strcmp(x.cep, (*p)->info.cep) < 0) {
        retiraArvore(x, &((*p)->esq));
        return;
    }

    if (strcmp(x.cep, (*p)->info.cep) > 0) {
        retiraArvore(x, &((*p)->dir));
        return;
    }

    if ((*p)->esq != NULL && (*p)->dir != NULL) {
        Antecessor(&(*p), &((*p)->esq));
        return;
    }

    aux = *p;
    if ((*p)->esq != NULL)
        *p = (*p)->esq;
    else
        *p = (*p)->dir;
    free(aux);
}


void Antecessor(Apont *q, Apont *r){
    if((*r)->dir != NULL){
        Antecessor(q, &((*r)->dir));
        return;
    }
    (*q)->info = (*r)->info;
    *q = *r;
    *r = (*r)->esq;
    free(*q);
}

Cep* pesquisaArvore(const char* x, Apont *p) {
    if ((*p) == NULL) {
        printf("Erro! Registro nao esta na arvore\n");
        return NULL;
    }
    int comparison = strcmp(x, (*p)->info.cep);
    if (comparison < 0) {
        return pesquisaArvore(x, &(*p)->esq);
    }
    if (comparison > 0) {
        return pesquisaArvore(x, &(*p)->dir);
    }
    else {
        return &((*p)->info);
    }
}

void Central(Apont *p){
    if((*p) == NULL)
        return;
    Central(&((*p)->esq)); 
    printf("%s\n",(*p)->info.cep);
    Central(&((*p)->dir)); 
}

void PreFixado(Apont *p){
    if((*p) == NULL)
        return;
    printf("%s\n",(*p)->info.cep);
    Central(&((*p)->esq));
    Central(&((*p)->dir));
}

void PosFixado(Apont *p){
    if((*p) == NULL)
        return;
    PosFixado(&((*p)->esq));
    PosFixado(&((*p)->dir));
    printf("%s\n",(*p)->info.cep);
}

int achaAltura(Apont *p){
    if(*p == NULL)
        return -1;
    int esq = achaAltura(&(*p)->esq);
    int dir = achaAltura(&(*p)->dir);
    if(esq > dir)
        return esq + 1;
    else
        return dir + 1;
}

Cep* maiorElemArvore(Apont *p){
    Cep *maior, *atual, *esquerda, *direita;

    atual = &((*p)->info);

    maior = atual;
    if ((*p)->esq != NULL) {
        esquerda = maiorElemArvore(&(*p)->esq);

        if (strcmp(esquerda->cep, maior->cep) > 0) {
            maior = esquerda;
        }
    }
    if ((*p)->dir != NULL) {
        direita = maiorElemArvore(&(*p)->dir);

        if (strcmp(direita->cep, maior->cep) > 0) {
            maior = direita;
        }
    }
    return maior;
}


Cep* menorElemArvore(Apont *p){
    Cep *menor, *atual, *esquerda, *direita;

    atual = &((*p)->info);

    menor = atual;
    if ((*p)->esq != NULL) {
        esquerda = menorElemArvore(&(*p)->esq);
        if (strcmp(esquerda->cep, menor->cep) < 0) {
            menor = esquerda;
        }
    }
    if ((*p)->dir != NULL) {
        direita = menorElemArvore(&(*p)->dir);

        if (strcmp(direita->cep, menor->cep) < 0) {
            menor = direita;
        }
    }
    return menor;
}


