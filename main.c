#include <stdio.h>
#include "exercicios.h"

int main() {
    TLista lista1, lista2;
    TipoItem item;
    FLVazia(&lista1);
    FLVazia(&lista2);
    TListaDouble listaDouble;
    FLVaziaDouble(&listaDouble);
    TipoFila fila1, fila2, fila3;
    FFVazia(&fila1);
    FFVazia(&fila2);
    FFVazia(&fila3);
    TPilha pilha1, pilha2;
    FPVazia(&pilha1);
    FPVazia(&pilha2);
    for (int i = 0; i < 10; ++i) {
        item.chave = i;
        Empilha(item, &pilha1);
    }
    transfere(&pilha1, &pilha2);
    imprimirPilha(&pilha2);
    return 0;
}