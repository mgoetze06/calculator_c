#include <stdbool.h>
#ifndef FP_H_   /* Include guard */
#define FP_H_

typedef struct{
    int pegel;
    int feld[];
}FP;
//FP* f;

//f->pegel;
//f->feld;
FP* empty();
bool isEmpty(FP* s);
int length(FP* s);
void print(FP* s);
void push(int x, FP* s);
void pop(FP* s);
int top(FP* s);
#endif
