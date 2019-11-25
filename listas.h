//
// Created by MARCOSHSC on 22/11/2019.
//

#ifndef EXERCICIOSPROVA_LISTAS_H
#define EXERCICIOSPROVA_LISTAS_H
#include "complementares.h"

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
} TLista;

typedef struct {
    TCelula2* primeiro;
    TCelula2* ultimo;
    int tamanho;
} TListaDouble;

void FLVazia(TLista *Lista);

int isListaVazia(TLista Lista);

void Inserir(TipoItem x, TLista *Lista);

void Retirar(TCelula* p, TLista *Lista, TipoItem *Item);

void Imprimir(TLista Lista);

void FLVaziaDouble(TListaDouble* lista);

int isListaVaziaDouble(TListaDouble lista);

void InserirDouble(TListaDouble* lista, TipoItem item);

void RetirarDouble(TListaDouble* lista, TCelula2* celula, TipoItem* item);

void ImprimirDouble(TListaDouble lista);

TCelula2* pesquisarDouble(TListaDouble lista, TipoItem item);

#endif //EXERCICIOSPROVA_LISTAS_H
