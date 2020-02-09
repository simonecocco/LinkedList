#include <stdlib.h>

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H

    /**
     * struttura della cella di memoria
     * che va a contenere:
     *
     * -----------------------------
     * prevpoint: puntatore di item
     * per l'item precedente
     *
     * nextpoint: puntatore di item
     * per l'item successivo
     *
     * data: puntatore generico
     * per il dato
     * ----------------------------
     */
    typedef struct items{
        struct items *prevpoint;
        struct items *nextpoint;
        void *data;
    } item;

    /**
     * struttura contenitore della lista
     * contiene:
     *
     * ----------------------------------------
     * size: unsigned int
     * numero di elementi presenti sulla lista
     *
     * firstpointer: puntatore di item
     * puntatore al primo elemento
     *
     * lastpointer: puntatore di item
     * puntatore al secondo elemento
     */
    typedef struct llists{
        unsigned int size;
        item *firstpointer;
        item *lastpointer;
    } llist;

    /**
     * inizializza una nuova lista
     * @param E puntatore generico del primo elemento da inserire
     * @return puntatore alla struttura llist (llists)
     */
    llist *newlist(void *E);

    /**
     * aggiunge un elemento alla lista
     * @param ll lista dove aggiungere un elemento
     * @param E puntatore gernerico dell'elemento da inserire
     */
    void additem(llist *ll,void *E);

    /**
     * ritorna un elemento della lista
     * @param ll lista dove andare a prendere l'elemento
     * @param index indice dell'elemento da prendere
     * @return puntatore a item
     */
    item *getitem(llist *ll,unsigned int index);
    //ritorna il dato
    void *getdata(llist *ll,unsigned int index);

    /**
     * elimina un elemento dalla lista
     * @param ll lista dove andare a rimuovere l'elemento
     * @param index indice dell'elemento da rimuovere
     * @return il dato dell'elemento
     */
    void *removeitem(llist *ll,unsigned int index);

    /** todo da aggiungere
     * replace(llist list,unsigned int index)
     */

    /**
     * distrugge la lista
     * @param ll
     */
    void *deletelist(llist *ll);
#endif
