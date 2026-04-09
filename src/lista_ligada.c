#include "lista_ligada.h"

int lista_num_nodos(DLista *l) {
    int i = 0;
    for(Nodo *tmp = l->head; tmp != NULL; tmp = tmp->sig, i++);
    return i;
}

DLista* crear_lista() {
    DLista *l = (DLista*)malloc(sizeof(DLista));
    l->head = l->tail = NULL;
    return l;
}

bool DLista_es_vacia(DLista *l) {
    if(!l) return true;
}

bool insertar_lista_vacia(DLista *l, void *info, size_t size) {
    if(!l) return false;
    Nodo *n = crear_nodo(info, size);
    l->head = l->tail = n;
    return true;
}

bool insertar_lista_inicio(DLista *l, void *info, size_t size) {
    if(!l) return false;
    Nodo *n = crear_nodo(info, size);
    n->sig = l->head;
    l->head->ant = n;
    l->head = n;
    return true;
}

bool insertar_lista_final(DLista *l, void *info, size_t size) {
    if(!l) return false;
    Nodo *n = crear_nodo(info, size);
    n->ant = l->tail;
    l->tail->sig = n;
    l->tail = n;
    return true;

}

bool insertar_lista_posicion(DLista *l, int p, void *info, size_t size) {
    if(!l) return false;
    if(DLista_es_vacia(l)) return insertar_lista_vacia(l, info, size);
    if(p == 0) return insertar_lista_inicio(l, info, size);
    if(p >= 1) {
        DLista *tmp = l->head;
        for(int i = 0; i < p-1; i++) tmp = tmp->sig;
        Nodo *n = crear_nodo(info, size);
        n->ant = tmp;
        n->sig = tmp->sig;
        Nodo *tmp2 = n->sig;
        tmp->sig = n;
        tmp2->ant = n;
    }
}