#include "FP.h"
#include <stdbool.h>
#include <stdio.h>

FP* empty(){
    FP* f;
    f->pegel = 0;
    return f;
}


bool isEmpty(FP* s){
    if(s->pegel == 0){ //s.pegel
        return true;  
    }else{
        return false;
    }
}

void print(FP* s){
    printf("Länge des Stapels: %d\n",s->pegel);
    for(int i=0;i<s->pegel;i++){
        printf("Stapelelement (%d): %d\n",i,s->feld[i]);
    }
}

void push(int x, FP* s){
    s->feld[s->pegel] = x;
    s->pegel = s->pegel + 1;
}
void pop(FP* s){
    //s->feld[s->pegel] = x;
    s->pegel = s->pegel - 1;
}
int top(FP* s){
    //s->feld[s->pegel] = x;
    return s->feld[s->pegel-1];
}

int length(FP* s){
    return s->pegel;
    //return 5;
}
