#include <stdbool.h>
#ifndef list_H_   /* Include guard */
#define list_H_

typedef struct anchor {
    struct list_node* first;
} Anchor;


typedef struct list_node {
    int item;
    struct list_node* next;
} List;

List* pushList(int x, List* s);
Anchor* pushL(int x, Anchor* s);
void printL(List* e);
List* popList(List* s);
int lengthList(List* e);

//Anchor* popL(Anchor* a,List* s);


#endif