//
// Created by MARCOSHSC on 22/11/2019.
//

#ifndef EXERCICIOSPROVA_FILAS_H
#define EXERCICIOSPROVA_FILAS_H
#include "complementares.h"

typedef struct TipoFila{
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila);

int isFilaVazia(TipoFila Fila);

void Enfileirar(TipoItem x, TipoFila *Fila);

void Desenfileirar(TipoFila *Fila, TipoItem *Item);

void imprimirFila(TipoFila* fila);

#endif //EXERCICIOSPROVA_FILAS_H
