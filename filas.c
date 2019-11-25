#include <stdlib.h>
#include <stdio.h>
#include "filas.h"

void FFVazia(TipoFila *Fila){
    Fila->frente = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int isFilaVazia(TipoFila Fila){
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TipoItem x, TipoFila *Fila){
    Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TipoFila *Fila, TipoItem *Item){
    TCelula* aux;
    if (!isFilaVazia(*Fila)){
    	aux = Fila->frente->prox;
    	Fila->frente->prox = aux->prox;
    	*Item = aux->item;
    	free(aux);
	if (Fila->frente->prox == NULL)
	    Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
}

void imprimirFila(TipoFila* fila) {
    TipoItem item;
    TipoFila aux;
    FFVazia(&aux);
    while(!isFilaVazia(*fila)) {
        Desenfileirar(fila, &item);
        Enfileirar(item, &aux);
        printf("%d\n", item.chave);
    }
    while(!isFilaVazia(aux)) {
        Desenfileirar(&aux, &item);
        Enfileirar(item, fila);
    }
}


