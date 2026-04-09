#include "nodo.h"

Nodo *crear_nodo(void *info, size_t size) {
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    if(!n)return;

    n->info = malloc(size);
    if(!n->info) { free(n); return }

    memcpy(n->info, info, size);
    n->ant = n->sig = NULL;
    return n;
}

void liberar_nodo(Nodo *n) {
    if(!n) {
        printf("No hay nodos a liberar\n");
    } else {
        free(n->info);
        free(n);
        n = NULL;
    }
}

bool actualizar_nodo(void *info, size_t size) {
    nodo->info = realloc(nodo->info, size);
    if(!nodo->info) return false;
    memcpy(nodo->info, info, size);
    return true;
}