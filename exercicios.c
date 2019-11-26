#include <stdio.h>
#include <stdlib.h>
#include "exercicios.h"

int isListsEqual(TLista lista1, TLista lista2) {
    if(lista1.tamanho != lista2.tamanho)
        return 0;
    if(isListaVazia(lista1) && isListaVazia(lista2))
        return 1;
    for(TCelula *current1 = lista1.primeiro->prox, *current2 = lista2.primeiro->prox; current1 != NULL; current1 = current1->prox,
            current2 = current2->prox) {
        if(current1->item.chave != current2->item.chave)
            return 0;
    }
    return 1;
}

void inserirOrdemCrescente(TLista* lista, TipoItem item) {
    if(isListaVazia(*lista)) {
        Inserir(item, lista);
        return;
    }
    else if(item.chave >= lista->ultimo->item.chave) {
        Inserir(item, lista);
        return;
    }
    for(TCelula* current = lista->primeiro; current->prox != NULL; current = current->prox) {
        if(item.chave <= current->prox->item.chave) {
            TCelula* aux = current->prox;
            current->prox = (TCelula*)malloc(sizeof(TCelula));
            current->prox->item = item;
            current->prox->prox = aux;
            break;
        }
    }
}

TipoItem* searchByIndex(TLista lista, int index) {
    if(lista.tamanho < index)
        return NULL;
    TCelula* current = lista.primeiro;
    for(int i = 0; i < index; i++) {
        current = current->prox;
    }
    return &current->item;
}

void removeByIndex(TLista* lista, int index, TipoItem* item) {
    if(lista->tamanho < index)
        printf("indice invalido");
    TCelula* current = lista->primeiro;
    for(int i = 0; i < index - 1; i++) {
        current = current->prox;
    }
    Retirar(current, lista, item);
}

void intercalar(TLista lista1, TLista lista2, TListaDouble* listaDouble) {
    if(lista1.tamanho > lista2.tamanho) {
        for(TCelula* current1 = lista1.primeiro, *current2 = lista2.primeiro; current1->prox != NULL;
        current1 = current1->prox) {
            if(current2->prox != NULL) {
                InserirDouble(listaDouble, current1->prox->item);
                InserirDouble(listaDouble, current2->prox->item);
                current2 = current2->prox;
            }
            else {
                InserirDouble(listaDouble, current1->prox->item);
            }
        }
    }
    else {
        for(TCelula* current1 = lista1.primeiro, *current2 = lista2.primeiro; current2->prox != NULL;
            current2 = current1->prox) {
            if(current1->prox != NULL) {
                InserirDouble(listaDouble, current1->prox->item);
                InserirDouble(listaDouble, current2->prox->item);
                current1 = current1->prox;
            }
            else {
                InserirDouble(listaDouble, current2->prox->item);
            }
        }
    }
}

void removeByLinkedList(TLista listaChaves, TListaDouble* listaDouble) {
    for(TCelula* current = listaChaves.primeiro; current->prox != NULL; current = current->prox) {
        if(current->prox->item.chave > listaDouble->tamanho)
            continue;
        TipoItem item;
        TCelula2* found;
        int i = 1;
        for(found = listaDouble->primeiro; i <= current->prox->item.chave; found = found->prox, i++);
        printf("%d", found->item.chave);
        RetirarDouble(listaDouble, found, &item);
    }
}

void dequeueByIndex(TipoFila* fila, int n, TipoItem* x) {
    if(n > fila->tamanho) {
        printf("Invalid Index");
        return;
    }
    TipoFila aux;
    FFVazia(&aux);
    TipoItem item;
    int i = 1;
    while(!isFilaVazia(*fila)) {
        Desenfileirar(fila, &item);
        if(i != n)
            Enfileirar(item, &aux);
        else
            *x = item;
        i++;
    }
    while(!isFilaVazia(aux)) {
        Desenfileirar(&aux, &item);
        Enfileirar(item, fila);
    }
}

void intersection(TipoFila* fila1, TipoFila* fila2, TipoFila* fila3) {
    TipoItem item1, item2, item3;
    TipoFila aux1, aux2, aux3;
    FFVazia(&aux1);
    FFVazia(&aux2);
    FFVazia(&aux3);
    while(!isFilaVazia(*fila1)) {
        Desenfileirar(fila1, &item1);
        Enfileirar(item1, &aux1);
        while(!isFilaVazia(*fila2)) {
            Desenfileirar(fila2, &item2);
            Enfileirar(item2, &aux2);
            if(item1.chave == item2.chave) {
                int contains = 0;
                while(!isFilaVazia(*fila3)) {
                    Desenfileirar(fila3, &item3);
                    Enfileirar(item3, &aux3);
                    if(item2.chave == item3.chave) {
                        contains = 1;
                        break;
                    }
                }
                while(!isFilaVazia(aux3)) {
                    Desenfileirar(&aux3, &item3);
                    Enfileirar(item3, fila3);
                }
                if(!contains)
                    Enfileirar(item2, fila3);
            }
        }
        while(!isFilaVazia(aux2)) {
            Desenfileirar(&aux2, &item2);
            Enfileirar(item2, fila2);
        }
    }
    while(!isFilaVazia(aux1)) {
        Desenfileirar(&aux1, &item1);
        Enfileirar(item1, fila1);
    }
}

void moveNode(TipoFila* fila, TCelula* p, int n) {
    if(fila->tamanho < n) {
        printf("Invalid position");
        return;
    }
    if(n == 0 || p == NULL)
        return;
    TipoFila aux;
    TipoItem *found = NULL, item, achado, chave = p->item;
    FFVazia(&aux);
    int enqueued = 0;
    int i = fila->tamanho;
    int j = 1;
    while(!isFilaVazia(*fila)) {
        Desenfileirar(fila, &item);
        if(item.chave == chave.chave && !enqueued) {
            found = &item;
            achado = item;
            enqueued = 1;
            i = j;
        }
        else {
            Enfileirar(item, &aux);
        }
        j++;
    }
    if(found && (i + n <= aux.tamanho)) {
        n = n + i;
        i = 1;
        while(!isFilaVazia(aux)) {
            Desenfileirar(&aux, &item);
            if(i == n) {
                Enfileirar(achado, fila);
            }
            Enfileirar(item, fila);
            i++;
        }
    }
    else {
        printf("Node not found");
        while(!isFilaVazia(aux)) {
            Desenfileirar(&aux, &item);
            Enfileirar(item, fila);
        }
    }
}

void inverterFila(TipoFila* fila) {
    TipoFila aux1, aux2;
    int tamanho = fila->tamanho;
    TipoItem item;
    FFVazia(&aux1);
    FFVazia(&aux2);
    while(aux2.tamanho != tamanho) {
        while (!isFilaVazia(*fila)) {
            Desenfileirar(fila, &item);
            if (isFilaVazia(*fila))
                Enfileirar(item, &aux2);
            else
                Enfileirar(item, &aux1);
        }
        while(!isFilaVazia(aux1)) {
            Desenfileirar(&aux1, &item);
            Enfileirar(item, fila);
        }
    }
    while(!isFilaVazia(aux2)) {
        Desenfileirar(&aux2, &item);
        Enfileirar(item, fila);
    }
}

void ordemCrescente(TipoFila* fila) {
    TipoFila aux1, aux2;
    TipoItem item1, item2;
    FFVazia(&aux1);
    FFVazia(&aux2);
    while(!isFilaVazia(*fila)) {
        Desenfileirar(fila, &item1);
        if(isFilaVazia(aux1)) {
            Enfileirar(item1, &aux1);
        }
        else {
            int position = aux1.tamanho;
            for(int i = 1; i <= aux1.tamanho; i++) {
                Desenfileirar(&aux1, &item2);
                Enfileirar(item2, &aux1);
                if(item2.chave > item1.chave)
                    position = i;
            }
            int i = 1;
            while(!isFilaVazia(aux1)) {
                Desenfileirar(&aux1, &item2);
                if(i == position) {
                    Enfileirar(item2, &aux2);
                    Enfileirar(item1, &aux2);
                }
                else
                    Enfileirar(item2, &aux2);
                i++;
            }
            while(!isFilaVazia(aux2)) {
                Desenfileirar(&aux2, &item2);
                Enfileirar(item2, &aux1);
            }
        }
    }
    while(!isFilaVazia(aux1)) {
        Desenfileirar(&aux1, &item1);
        Enfileirar(item1, fila);
    }
}

float mediana(TipoFila* fila) {
    if(isFilaVazia(*fila))
        return 0;
    ordemCrescente(fila);
    TipoItem item;
    TipoFila aux;
    FFVazia(&aux);
    if(fila->tamanho % 2 == 0) {
        int i = 1, tam = fila->tamanho;
        float med = 0;
        while(!isFilaVazia(*fila)) {
            Desenfileirar(fila, &item);
            if(i == tam / 2 || i == (tam / 2) + 1) {
                med += (float)item.chave;
            }
            Enfileirar(item, &aux);
            i++;
        }
        while(!isFilaVazia(aux)) {
            Desenfileirar(&aux, &item);
            Enfileirar(item, fila);
        }
        return med / 2;
    }
    else {
        int i = 1, tam = fila->tamanho;
        float med = 0;
        while(!isFilaVazia(*fila)) {
            Desenfileirar(fila, &item);
            if(i == (tam / 2) + 1) {
                med = (float)item.chave;
            }
            Enfileirar(item, &aux);
            i++;
        }
        while(!isFilaVazia(aux)) {
            Desenfileirar(&aux, &item);
            Enfileirar(item, fila);
        }
        return med;
    }
}

void diferenca(TipoFila* fila1, TipoFila* fila2, TipoFila* fila3) {
    if(fila1->tamanho == 0 || fila2->tamanho == 0)
        return;
    TipoFila aux1, aux2;
    TipoItem item1, item2;
    FFVazia(&aux1);
    FFVazia(&aux2);
    while(!isFilaVazia(*fila1)) {
        int contains = 0;
        Desenfileirar(fila1, &item1);
        Enfileirar(item1, &aux1);
        while(!isFilaVazia(*fila2)) {
            Desenfileirar(fila2, &item2);
            Enfileirar(item2, &aux2);
            if(item2.chave == item1.chave)
                contains = 1;
        }
        if(!contains)
            Enfileirar(item1, fila3);
        while(!isFilaVazia(aux2)) {
            Desenfileirar(&aux2, &item2);
            Enfileirar(item2, fila2);
        }
    }
    while(!isFilaVazia(aux1)) {
        Desenfileirar(&aux1, &item1);
        Enfileirar(item1, fila1);
    }
}

void inverterPilha2Aux(TPilha* pilha) {
    TPilha aux1, aux2;
    TipoItem item;
    FPVazia(&aux1);
    FPVazia(&aux2);
    while(!isPilhaVazia(*pilha)) {
        Desempilha(pilha, &item);
        Empilha(item, &aux1);
    }
    while(!isPilhaVazia(aux1)) {
        Desempilha(&aux1, &item);
        Empilha(item, &aux2);
    }
    while(!isPilhaVazia(aux2)) {
        Desempilha(&aux2, &item);
        Empilha(item, pilha);
    }
}

void inverterPilhaFila(TPilha* pilha) {
    TipoFila aux;
    TipoItem item;
    FFVazia(&aux);
    while(!isPilhaVazia(*pilha)) {
        Desempilha(pilha, &item);
        Enfileirar(item, &aux);
    }
    while(!isFilaVazia(aux)) {
        Desenfileirar(&aux, &item);
        Empilha(item, pilha);
    }
}

void inverterPilha1Aux(TPilha* pilha) {
    TPilha aux;
    FPVazia(&aux);
    TipoItem item;
    while(!isPilhaVazia(*pilha)) {
        Desempilha(pilha, &item);
        Empilha(item, &aux);
    }
    free(pilha->topo);
    *pilha = aux;
}

void ordemDecrescentePilha(TPilha* pilha) {
    TPilha aux;
    FPVazia(&aux);
    TipoItem item1, item2 = pilha->topo->prox->item;
    for(int i = pilha->tamanho; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            Desempilha(pilha, &item1);
            if(j == 0) {
                item2 = item1;
            }
            else {
                if (item1.chave > item2.chave) {
                    Empilha(item2, &aux);
                    item2 = item1;
                } else {
                    Empilha(item1, &aux);
                }
            }
        }
        Empilha(item2, pilha);
        while(!isPilhaVazia(aux)) {
            Desempilha(&aux, &item1);
            Empilha(item1, pilha);
        }
    }
}

void transfere(TPilha* pilha1, TPilha* pilha2) {
    TipoItem item1, item2;
    int quantos = 0;
    if(!isPilhaVazia(*pilha2)) {
        printf("tem como nao parceiro");
        return;
    }
    for(int k = 0; k < 2; k++) {
        quantos = 0;
        for (int i = pilha1->tamanho - 1; i > 0; i--) {
            Desempilha(pilha1, &item2);
            for (int j = 0; j < i; j++) {
                Desempilha(pilha1, &item1);
                Empilha(item1, pilha2);
            }
            Empilha(item2, pilha1);
            int tamanho = pilha2->tamanho - quantos;
            for (int j = 0; j < tamanho; j++) {
                Desempilha(pilha2, &item1);
                Empilha(item1, pilha1);
            }
            Empilha(item2, pilha2);
            quantos++;
        }
        Desempilha(pilha1, &item1);
        Empilha(item1, pilha2);
        Empilha(item1, pilha1);
        if(k == 0)
            while(!isPilhaVazia(*pilha2)) {
                Desempilha(pilha2, &item1);
            }
    }
}

void organizaMaiorMenor(TPilha* pilha) {
    TPilha aux;
    FPVazia(&aux);
    TipoItem item1, maior, menor;
    for(int i = pilha->tamanho; i > 0; i -= 2) {
        int foi1 = 0, foi2 = 0;
        for(int j = 0; j < i; j++) {
            Desempilha(pilha, &item1);
            if(j == 0) {
                maior = item1;
                menor = item1;
            }
            else {
                int empilhado = 0;
                if(item1.chave > maior.chave) {
                    if(!foi1 && !foi2)
                        foi1 = 1;
                    else
                        Empilha(maior, &aux);
                    maior = item1;
                    empilhado = 1;
                }
                if(item1.chave < menor.chave) {
                    if(!foi1 && !foi2)
                        foi1 = 1;
                    else
                        Empilha(menor, &aux);
                    menor = item1;
                    empilhado = 1;
                }
                if(!empilhado)
                    Empilha(item1, &aux);
            }
            imprimirPilha(&aux);
        }
        Empilha(menor, pilha);
        Empilha(maior, pilha);
        while(!isPilhaVazia(aux)) {
            Desempilha(&aux, &item1);
            Empilha(item1, pilha);
        }
    }
    // no final ver se ainda tem algum elemento
}

void FazFilaAlteradaVazia(FilaPilhada* fila) {
    FPVazia(&fila->pilha);
}

void EnfileirarAlterada(TipoItem item, FilaPilhada* fila) {
    TPilha aux;
    FPVazia(&aux);
    TipoItem itemaux;
    while(!isPilhaVazia(fila->pilha)) {
        Desempilha(&fila->pilha, &itemaux);
        Empilha(itemaux, &aux);
    }
    Empilha(item, &fila->pilha);
    while(!isPilhaVazia(aux)) {
        Desempilha(&aux, &itemaux);
        Empilha(itemaux, &fila->pilha);
    }
}

void DesenfileirarAlterada(FilaPilhada* fila, TipoItem* item) {
    TPilha aux;
    FPVazia(&aux);
    TipoItem itemaux;
    Desempilha(&fila->pilha, item);
    while(!isPilhaVazia(fila->pilha)) {
        Desempilha(&fila->pilha, &itemaux);
        Empilha(itemaux, &aux);
    }
    while(!isPilhaVazia(aux)) {
        Desempilha(&aux, &itemaux);
        Empilha(itemaux, &fila->pilha);
    }
}

int tamanhoFilaAlterada(FilaPilhada fila) {
    return fila.pilha.tamanho;
}

int vaziaFilaAlterada(FilaPilhada fila) {
    return isPilhaVazia(fila.pilha);
}

void imprimeFilaAlterada(FilaPilhada* fila) {
    TipoItem item;
    FilaPilhada aux;
    FazFilaAlteradaVazia(&aux);
    while(!vaziaFilaAlterada(*fila)) {
        DesenfileirarAlterada(fila, &item);
        EnfileirarAlterada(item, &aux);
        printf("%d\n", item.chave);
    }
    while(!vaziaFilaAlterada(aux)) {
        DesenfileirarAlterada(&aux, &item);
        EnfileirarAlterada(item, fila);
    }
}