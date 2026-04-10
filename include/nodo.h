#ifndef __NODO_H
#define __NODO_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


typedef struct Nodo Nodo;

struct Nodo {
    void *info;
    Nodo *sig;
    Nodo *ant;
};

Nodo *crear_nodo(void *info, size_t size);
void liberar_nodo(Nodo *n);
bool actualizar_nodo(Nodo *n, void *info, size_t size);

#endif