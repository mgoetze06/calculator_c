#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isOperator(char c){
	//Überprüfen, ob Eingabe des Nutzers ein Operator ist oder nicht
	
    if((c == '+')||(c == '*')||(c == '-')||(c == '/')||(c == '@')||(c == '#')){ 
		//Eingabe ist Operator
        //42 *
        //43 +
        return true;
    }else{
		//Eingabe ist kein Operator
        return false;
    }
}

int berechne(int a, int b, char op){
    int ergebnis;
	//Operator zwischen +-*/unterscheiden
    switch(op) {
    	case '+': ergebnis = a+b; break;
        case '-': ergebnis = b-a; break;
        case '*': ergebnis = a*b; break;
        case '/': ergebnis = a/b; break;
    }
	//Ergebnis zurückliefern
    return ergebnis;
}

int convertToInt(char c[2]){
	int mystrlen;
	int x;
	mystrlen = strlen(c);
	//printf("size of c: %d\n",mystrlen);
	//x = c[0] - '0';
	if (mystrlen == 1){
		//printf("single digit\n");
		x = c[0] - '0';
	}
	else{
		x = (c[0]-'0')*10 + (c[1]-'0');
	}
	
	return x;
	
}



void rechner_list(){
    printf("rechner_list\n");
    printf("\n\n---   Taschenrechner   ---\n");
	
	//initialisierung
    Anchor* myanchor;
    List* list;
    list = NULL;
    myanchor->first = list;
    int x;
    char c[2];
    while (lengthList(myanchor->first) < 50){
		printf("##############################################################\n");
		printf("possible values: integers 0 - 99, operators +-*/@#\n");
        printf("Enter a value:");
        scanf("%s", c);
        
        int ergebnis;								//variable für ergebnis der rechenoperation
        int len = lengthList(myanchor->first);		//länge der verketteten Liste
		
        if (isOperator(c[0])){
			if (len>1){								//nur bei einer Listenlänge größer als 1 kann ein Operator angwandt werden
				
				if (c[0] == '@'){
					//operator ist @ --> Funktion stock aufrufen (oberstes Element nach ganz unten verschieben)
					myanchor->first = stock(myanchor->first->item,myanchor->first);
					
				}else{
					if (c[0] == '#'){
						//operator ist # --> Zusatzfunktion invertList aufrufen
						//gesamte Liste invertieren
						
						//temporär neuen Anker erstellen
						Anchor* new_anchor4;
						new_anchor4 = invertList(myanchor);
						
						//ursprünglichen Anker mit temporärem Anker überschreiben
						myanchor->first = new_anchor4->first;
						
					}else{
						//normale Berechnung mit +-*/
						//a == oberstes Element der Liste
						int a = myanchor->first->item;
						//b == Nachfolger von a == zweitoberstes Element der Liste
						int b = myanchor->first->next->item;
						//Ergebnis mit Funktion berechne() berechnen; operator ist in c[0]
						ergebnis = berechne(a,b,c[0]);
						printf("ergebnis: %d\n", ergebnis);
						
						//a and b von der Liste entfernen
						myanchor->first=popList(myanchor->first);
						myanchor->first=popList(myanchor->first);
						
						//Ergebnis der Berechnung zur Liste hinzufügen
						//temporär neuen Anker erstellen
						Anchor* new_anchor3;
						new_anchor3 = pushL(ergebnis,myanchor);
						//ursprünglichen Anker mit temporärem Anker überschreiben
						myanchor->first = new_anchor3->first;
					}
				}
            }else{
				//Länge der Liste ist <= 1; kein Operator ist erlaubt
				printf("an operator is not allowed with only one item in list!\n");
			}
        }else{
			//Eingabe ist kein Operator, Eingabe wird als Zahl interpretiert
			x = convertToInt(c); //aus Zeichenkette wird integer
			
			//neue Zahl zur Liste hinzufügen
			//temporär neuen Anker erstellen
			Anchor* new_anchor;
			new_anchor = pushL(x,myanchor);
			//ursprünglichen Anker mit temporärem Anker überschreiben
			myanchor->first = new_anchor->first;
        }
        printL(myanchor->first); //Liste plotten
    }
}





void list_test(){
    printf("list_test\n");
    Anchor* anchor;
    List* list;
    printf("temp1\n");
    list = NULL;
    anchor->first = list;
    printf("length: %d\n",lengthList(anchor->first));
    printf("push 1\n");
    anchor = pushL(1,anchor);
    //printf("print list with new 1\n");
    printf("length: %d\n",lengthList(anchor->first));
    printL(anchor->first);   
    //printf("push 2\n");
    anchor = pushL(2,anchor);
    //printf("print list with new 2\n");
    printL(anchor->first);   
    anchor = pushL(3,anchor);
    printf("length: %d\n",lengthList(anchor->first));
    //printf("print list with new 3\n");
    printL(anchor->first);  
    //printf("pop list:\n");
    anchor->first = popList(anchor->first);
    printf("length: %d\n",lengthList(anchor->first));
    printL(anchor->first);   
    
    /*list = pushList(3,list);
    printL(list);   
    //anchor = popL(anchor,list);
    printf("temp3\n");
    list = popList(list);
    printL(list);   
    printf("temp3\n");
    list = pushList(2,list);
    printL(list);
    printf("temp4\n");
    list = pushList(4,list);
    printL(list); 
    printf("temp51\n");
    list = pushList(6,list);
    printL(list);
    printf("temp5\n");
    list = popList(list);
    printL(list);   
    printf("temp61\n");
    list = popList(list);
    printL(list);   
    printf("temp62\n");
    list = pushList(21,list);
    printL(list);   
    printf("temp63\n");*/
}
