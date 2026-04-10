#include "lista_ligada.h"

int lista_num_nodos(DLista *l) {
    int i = 0;
    if(!l) return i;
    for(Nodo *tmp = l->head; tmp != NULL; tmp = tmp->sig, i++);
    return i;
}

DLista* crear_lista() {
    DLista *l = (DLista*)malloc(sizeof(DLista));
    if(!l) return NULL;
    l->head = l->tail = NULL;
    return l;
}

bool lista_es_vacia(DLista *l) {
    if(!l) return true;
    return l->head == NULL;
}

bool insertar_lista_vacia(DLista *l, void *info, size_t size) {
    if(!l) return false;
    Nodo *n = crear_nodo(info, size);
    if(!n) return false;
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
    if(!n) return false;
    n->ant = l->tail;
    l->tail->sig = n;
    l->tail = n;
    return true;

}

bool insertar_lista_posicion(DLista *l, int p, void *info, size_t size) {
    if(!l) return false;
    if(lista_es_vacia(l)) return insertar_lista_vacia(l, info, size);
    if(p == 0) return insertar_lista_inicio(l, info, size);
    if(p == lista_num_nodos(l)) return insertar_lista_final(l, info, size);
    if(p >= 1) {
        Nodo *tmp = l->head;
        for(int i = 0; i < p-1; tmp = tmp->sig, i++);
        Nodo *n = crear_nodo(info, size);
        if(!n) return false;
        n->ant = tmp;
        n->sig = tmp->sig;
        tmp->sig->ant = n;    
        tmp->sig = n;


        //Nodo *tmp2 = n->sig;
        //tmp->sig = n;
        //tmp2->ant = n;
        return true;
    }
    return false;
}