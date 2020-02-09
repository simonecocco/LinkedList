# LinkedList
###### Liste doppiamente collegate

## Uso:

### Importazione
* Su arduino
```c
extern "C"{
    #include "linkedlist.h"
};
```
* Programmi normali
```c
#include "linkedlist.h
```
***

### Tipi
###### Elemento della lista che mantiene il dato
```c
typedef struct items{
    struct items *prevpoint;
    struct items *nextpoint;
    void *data;
} item;
```
###### Lista che mantiene la dimensione e i puntatori al primo e all'ultimo elemento
```c
typedef struct llists{
    unsigned int size;
    item *firstpointer;
    item *lastpointer;
} llist;
```
***

### Creazione di una nuova lista
* Sintassi
```c
llist *newlist(void *E);
```
* Codice
```c
llist *list=newlist((void *)x);
```
***

### Aggiungi un elemento alla lista
* Sintassi
```c
void additem(llist *ll,void *E);
```
* Codice
```c
additem(list,(void *)x);
```
***

### Ottieni un elemento della lista
* Sintassi
```c
void *getdata(llist *ll,unsigned int index);
```
* Codice
```c
char *x=(char *)getdata(list,0); 
```
***

### Rimuovere un elemento
* Sintassi
```c
void *removeitem(llist *ll,unsigned int index);
```
* Codice
```c
char *bkpchar=(char *)removeitem(list,0);
```
***

### Eliminare la lista
* Sintassi
```c
void *deletelist(llist *ll);
```
* Codice
```c
deletelist(list);
```