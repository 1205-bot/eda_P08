#ifndef __LISTA_LIGADA_H
#define __LISTA_LIGADA_H

#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct DLista {
    Nodo *head;
    Nodo *tail;
    
} DLista;

DLista* crear_lista();
int lista_num_nodos(DLista *l);
bool lista_es_vacia(DLista *l);
bool insertar_lista_vacia(DLista *l, void *info, size_t size);
bool insertar_lista_inicio(DLista *l, void *info, size_t size);
bool insertar_lista_final(DLista *l, void *info, size_t size);
bool insertar_lista_posicion(DLista *l, int p, void *info, size_t size);

#endif