#ifndef EXERCICIOSPROVA_COMPLEMENTARES_H
#define EXERCICIOSPROVA_COMPLEMENTARES_H

typedef struct {
    int chave;
    /* outros componentes */
} TipoItem;

typedef struct celula {
    TipoItem item;
    struct celula* prox;
} TCelula;

typedef struct celula2 {
    TipoItem item;
    struct celula2* prox;
    struct celula2* ant;
} TCelula2;

#endif //EXERCICIOSPROVA_COMPLEMENTARES_H
