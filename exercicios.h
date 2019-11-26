#ifndef EXERCICIOSPROVA_EXERCICIOS_H
#include "listas.h"
#include "pilhas.h"
#include "filas.h"
#define EXERCICIOSPROVA_EXERCICIOS_H

typedef struct {

    TPilha pilha;

} FilaPilhada;

int isListsEqual(TLista lista1, TLista lista2);

void inserirOrdemCrescente(TLista* lista, TipoItem item);

TipoItem* searchByIndex(TLista lista, int index);

void removeByIndex(TLista* lista, int index, TipoItem* item);

void intercalar(TLista lista1, TLista lista2, TListaDouble* listaDouble);

void removeByLinkedList(TLista listaChaves, TListaDouble* listaDouble);

void dequeueByIndex(TipoFila* fila, int n, TipoItem* x);

void intersection(TipoFila* fila1, TipoFila* fila2, TipoFila* fila3);

void moveNode(TipoFila* fila, TCelula* p, int n);

void inverterFila(TipoFila* fila);

void ordemCrescente(TipoFila* fila);

float mediana(TipoFila* fila);

void diferenca(TipoFila* fila1, TipoFila* fila2, TipoFila* fila3);

void inverterPilha2Aux(TPilha* pilha);

void inverterPilhaFila(TPilha* pilha);

void inverterPilha1Aux(TPilha* pilha);

void ordemDecrescentePilha(TPilha* pilha);

void transfere(TPilha* pilha1, TPilha* pilha2);

void organizaMaiorMenor(TPilha* pilha);

void FazFilaAlteradaVazia(FilaPilhada* fila);

void DesenfileirarAlterada(FilaPilhada* fila, TipoItem* item);

void EnfileirarAlterada(TipoItem item, FilaPilhada* fila);

int tamanhoFilaAlterada(FilaPilhada fila);

int vaziaFilaAlterada(FilaPilhada fila);

void imprimeFilaAlterada(FilaPilhada* fila);

#endif //EXERCICIOSPROVA_EXERCICIOS_H
