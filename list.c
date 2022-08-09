#include "list.h"
#include <stdio.h>
#include <stddef.h>

//anchor ist wie pegel zu betrachten

//push: ein Listenelement "oben" anfügen: Anchor zeigt auf neues Element; "alter" Anchor zeigt auf nächstes Listenelement
//pop: ein Listenelement "oben" entfernen: neuer Anchor zeigt auf das Element, was vom obersten Listenelement verwiesen wird (oberstes Element wird übersprungen) 

//unterstes Listenelement hat keinen weiteren Zeiger (next = NULL)

List* popList(List* s) {
    printf("inside pop list\n");
    List* f = malloc(sizeof(List));
    //f->item = x;
    f->item = s->next->item;
    f->next = s->next->next;
    //printf("%d\n", f->item);
    return f;
}


List* pushList(int x, List* s) {
    List* f = malloc(sizeof(List));
    printf("pushing into list\n");
    f->item = x;
    f->next = s;
    printf("finished pushing into list\n");
    return f;
}

Anchor* pushL(int x, Anchor* s) {
    printf("length of anchor: %d\n",lengthList(s->first));
    /*if (s->first == NULL){
        printf("anchor is null\n");
        List* list;
        s->first = pushList(x, list);
    }else{*/
        printf("anchor is not null\n");
        s->first = pushList(x, s->first);
    //}
    
    return s;
}
//Anchor* popL(Anchor* a, List* s) {
//    a->first = s->next;
//    return a;
//}

int lengthList(List* e){
    int len;
    len = 0;
    if (e == NULL){
        printf("Liste ist leer");
        len = 0;
    }
    else{
        List* l = e;
        while(l != NULL){
            printf("%d ", l->item);
            l = l->next;
            len = len + 1;
        }
    }
    
    return len;
}

void printL(List* e){
    if (e == NULL){
        printf("Liste ist leer");
    }
    else{
        List* l = e;
        while(l != NULL){
            printf("%d ", l->item);
            l = l->next;
        }
    }
    printf("\n");
}