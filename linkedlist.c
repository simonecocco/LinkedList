#include "linkedlist.h"
llist *newlist(void *E){
    if(E==NULL)return NULL;
    llist *tmplist=malloc(sizeof(llist));
    tmplist->size=1;

    item *tmpitem=malloc(sizeof(item));
    tmpitem->data=E;
    tmpitem->prevpoint=NULL;
    tmpitem->nextpoint=NULL;

    tmplist->firstpointer=tmpitem;
    tmplist->lastpointer=tmpitem;

    return tmplist;
}

void additem(llist *ll,void *E){
    if(E==NULL||ll==NULL)return;
    ++ll->size;
    item *tmpitem=malloc(sizeof(item));
    tmpitem->data=E;
    tmpitem->nextpoint=NULL;
    tmpitem->prevpoint=ll->lastpointer;
    ll->lastpointer->nextpoint=tmpitem;
    ll->lastpointer=tmpitem;
}

item *getitem(llist *ll,unsigned int index){
    if(ll==NULL)return NULL;
    if(ll->size<=index)return NULL;

    item *tmpitem=ll->firstpointer;
    for(unsigned int i=0;i<ll->size;i++){
        if(i==index)return tmpitem;

        tmpitem=tmpitem->nextpoint;
    }
    return NULL;
}

void *getdata(llist *ll,unsigned int index){
    return getitem(ll,index)->data;
}

void *removeitem(llist *ll,unsigned int index){
    if(ll==NULL||ll->size<=index)return NULL;

    item *itemtodelete=getitem(ll,index);

    item *nextitem=itemtodelete->nextpoint,
            *previtem=itemtodelete->prevpoint;

    itemtodelete->nextpoint=NULL;
    itemtodelete->prevpoint=NULL;

    void *data=itemtodelete->data;

    itemtodelete->data=NULL;

    if(nextitem==NULL&&previtem==NULL){
        free(itemtodelete);
        ll->size=0;
        free(ll);
        //todo to deletell=NULL;
        return NULL;
    }else if(nextitem==NULL){
        ll->lastpointer=previtem;
        previtem->nextpoint=NULL;
    }else if(previtem==NULL){
        ll->firstpointer=nextitem;
        nextitem->prevpoint=NULL;
    }else{
        nextitem->prevpoint=previtem;
        previtem->nextpoint=nextitem;
    }
    ll->size--;
    free(itemtodelete);
    return data;
}

void *deletelist(llist *ll){
    if(ll==NULL)return NULL;
    unsigned int size=ll->size;
    while(size<=0){
        removeitem(ll,0);
        size--;
    }
    return NULL;
}