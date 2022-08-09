#include "FP.h"
#include <stdio.h>


void stacktest()
{
    printf("\nStapeltest\n");
    FP* f;
    f = empty();
    //ool temp = isEmpty(f);
    if (isEmpty(f)){
        printf("leerer Stapel\n");
    }else{
        printf("Stapel nicht leer\n");
    }
    //Aufgabenteil5: n Elemente hinzuzfügen
    for(int i=0;i<7;i++){
        push(i*3,f);
    }
    //Aufgabenteil6: den Stapel ausgeben
    print(f);
    pop(f);
    print(f);
    if (isEmpty(f)){
        printf("leerer Stapel\n");
    }else{
        printf("Stapel nicht leer\n");
    }
    printf("Länge des Stapels: %d\n",f->pegel);
    printf("Oberstes Element des Stapels: %d\n",top(f));
}
