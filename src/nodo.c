#include "nodo.h"
#include <string.h>

Nodo *crear_nodo(void *info, size_t size) {
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    if(!n)return NULL;
    n->info = malloc(size);
    if(!n->info) { free(n); return NULL; }
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
    }
}

bool actualizar_nodo(Nodo *n, void *info, size_t size) {
    if(!n) return false;
    void *tmp = realloc(n->info, size);
    if(!tmp) return false;
    n->info = tmp;
    memcpy(n->info, info, size);
    return true;
}