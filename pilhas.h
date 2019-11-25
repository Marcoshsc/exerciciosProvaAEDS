//
// Created by MARCOSHSC on 22/11/2019.
//

#ifndef EXERCICIOSPROVA_PILHAS_H
#define EXERCICIOSPROVA_PILHAS_H
#include "complementares.h"

typedef struct {
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

int isPilhaVazia(TPilha Pilha);

void Empilha(TipoItem x, TPilha *Pilha);

void Desempilha(TPilha *Pilha, TipoItem *Item);

int Tamanho(TPilha Pilha);

void imprimirPilha(TPilha* pilha);

#endif //EXERCICIOSPROVA_PILHAS_H
