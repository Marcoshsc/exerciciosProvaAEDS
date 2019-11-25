#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#define MAX 10

void FLVazia(TLista *Lista)
{ Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> primeiro;
  Lista -> primeiro -> prox = NULL;
  Lista -> tamanho = 0;
}

int isListaVazia(TLista Lista)
{ return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TipoItem x, TLista *Lista)
{ Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> ultimo -> prox;
  Lista -> ultimo -> item = x;
  Lista -> ultimo -> prox = NULL;
  Lista->tamanho++;
}

void Retirar(TCelula* p, TLista *Lista, TipoItem *Item)
{ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  TCelula* q;
  if (isListaVazia(*Lista) || p == NULL || p -> prox == NULL)
  { printf(">>>>> ERROR: Lista vazia ou posicao nao existe!!! <<<<<\n");
    return;
  }
  q = p -> prox;
  *Item = q -> item;
  p -> prox = q -> prox;
  Lista->tamanho--;
  if (p -> prox == NULL)
    Lista -> ultimo = p;
  free(q);
}

void Imprimir(TLista Lista)
{ TCelula* Aux;
  Aux = Lista.primeiro -> prox;
  while (Aux != NULL){
    printf("%d\n", Aux -> item.chave);
    Aux = Aux -> prox;
  }
}

void FLVaziaDouble(TListaDouble* lista) {
    lista->primeiro = (TCelula2*)malloc(sizeof(TCelula2));
    lista->primeiro->ant = NULL;
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
    lista->tamanho = 0;
}

int isListaVaziaDouble(TListaDouble lista) {
    return lista.primeiro == lista.ultimo;
}

void InserirDouble(TListaDouble* lista, TipoItem item) {
    lista->ultimo->prox = (TCelula2*)malloc(sizeof(TCelula2));
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
    lista->ultimo->item = item;
    lista->tamanho++;
}

void RetirarDouble(TListaDouble* lista, TCelula2* celula, TipoItem* item) {
    celula->ant->prox = celula->prox;
    if(celula->ant->prox == NULL)
        lista->ultimo = celula->ant;
    else
        celula->prox->ant = celula->ant;
    *item = celula->item;
    lista->tamanho--;
    free(celula);
}

void ImprimirDouble(TListaDouble lista) {
    for(TCelula2* current = lista.primeiro->prox; current != NULL; current = current->prox) {
        printf("%d\n", current->item.chave);
    }
}

TCelula2* pesquisarDouble(TListaDouble lista, TipoItem item) {
    if(isListaVaziaDouble(lista))
        return NULL;
    for(TCelula2* current = lista.primeiro; current->prox != NULL; current = current->prox) {
        if(current->prox->item.chave == item.chave)
            return current->prox;
    }
    return NULL;
}

