#include "list.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

//anchor ist wie pegel zu betrachten
//push: ein Listenelement "oben" anfügen: Anchor zeigt auf neues Element; "alter" Anchor zeigt auf nächstes Listenelement
//pop: ein Listenelement "oben" entfernen: neuer Anchor zeigt auf das Element, was vom obersten Listenelement verwiesen wird (oberstes Element wird übersprungen) 
//unterstes Listenelement hat keinen weiteren Zeiger (next = NULL)

List* stock(int x, List* e) {	
	//aus der Liste 4,3,2,1 wird 3,2,1,4
	
	//Liste der Länge 1 mit Element x erzeugen
	List* f;
    f->item = x;
    f->next = NULL;
	
	
	//aktuelle Liste bis zum letzten Element durchlaufen
	List* l = e;
	while(l != NULL){
		l = l->next;
	}
	
	//neues Listenelement f an das Ende anhängen
	l->next = f;
	
	return l;
}



List* popList(List* s) {
	//aus der Liste 4,3,2,1 wird 3,2,1
	
	
    //printf("inside pop list\n");
    List* f = malloc(sizeof(List));
	//printf("before if\n");
	if (s->next == NULL){				//nächstes Element ist NULL --> Liste hat nur Länge 1
		//printf("next item is NULL! end of list\n");
		f = NULL;						//popList() erzeugt dadurch leere Liste
	}else{
		//printf("next item not NULL!\n");
		f->next = (s->next)->next;		//Liste wird an oberster Stelle abgeschnitten
		f->item = (s->next)->item;
		//printf("%d\n", f->item);
	}
    return f;
}


List* pushList(int x, List* s) {
	//aus der Liste 4,3,2,1 wird x,4,3,2,1
	
	
    List* f = malloc(sizeof(List)); 	//neues Listenelement erstellen
    //printf("pushing into list\n");
    f->item = x; 						//Liste->item zu x setzen
    f->next = s; 						//neues Listenelement oben an die bestehende Liste anfügen
    //printf("finished pushing into list\n");
    return f; 							//neue Liste zurückgeben
}

Anchor* pushL(int x, Anchor* s) {
    s->first = pushList(x, s->first);	//Aufruf der Funktion mit dem neuen Wert und dem obersten Listenelement
    return s;
}

int lengthList(List* e){
    int len;							//Variable für Listenlänge
    len = 0;
    if (e == NULL){						//Liste ist leer
        printf("list is empty\n");
        len = 0;
    }
    else{
        List* l = e;
        while(l != NULL){				//Sollte der Next-Zeiger nicht NULL sein, existiert ein weiteres Listenelement
            //printf("%d ", l->item);
            l = l->next;				
            len = len + 1;				//Die Gesamtlistenlänge wird um 1 erhöht
        }
    }
    return len;
}

void printL(List* e){
    if (e == NULL){						//Liste ist leer
        printf("list is empty\n");
    }
    else{
        List* l = e;
		printf("\n ### list length: %d\n",lengthList(e));	//Länge der Liste ausgeben
        printf(" ### list content: ");						//Inhalt der Liste ausgeben (oberstes Element zuerst (ganz links), unterstes Element zuletzt (ganz rechts)
		while(l != NULL){
            printf("%d ", l->item);
            l = l->next;
        }
    }
    printf("\n");
}

Anchor* invertList(Anchor* a) {
	
	//Zusatzfunktion zum Invertieren der gesamten Liste
	//es wird nicht nur das oberste Element nach ganz unten verschoben wie bei stock()
	//sondern die gesamte Reihenfolge der Elemente von oben nach unten vertauscht
	
	//aus der Liste 4,3,2,1 wird 1,2,3,4
	
	List* prev = NULL;
    List* current = a->first;
    List* next = NULL;
    while (current != NULL) {			//bis das aktuelle Element NULL ist == Ende der Liste erreicht
        next = current->next;        	//nächstes Element speichern
        current->next = prev; 		 	//aktuellen Zeiger auf das vorherige Element setzen
        prev = current;					//alle Zeiger eine Position in der Liste versetzen
        current = next;
    }
    a->first = prev;
	return a;
}