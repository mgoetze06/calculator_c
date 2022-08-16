#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isOperator(char c){
    if((c == '+')||(c == '*')||(c == '-')||(c == '/')||(c == '@')||(c == '#')){ 
        //42 *
        //43 +
        return true;
    }else{
        return false;
    }
}

int berechne(int a, int b, char op){
    int ergebnis;
    switch(op) {
    	case '+': ergebnis = a+b; break;
        case '-': ergebnis = b-a; break;
        case '*': ergebnis = a*b; break;
        case '/': ergebnis = a/b; break;
    }
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
					//operator ist # --> Funktion stock aufrufen (oberstes Element nach ganz unten verschieben)
						Anchor* new_anchor4;
						new_anchor4 = invertList(myanchor);
						myanchor->first = new_anchor4->first;
						
						//printf("invertion done\n");
					}else{
						//printf("normal calculation\n");
						//a
						int a = myanchor->first->item;
						//b
						int b = myanchor->first->next->item;
						//solution
						ergebnis = berechne(a,b,c[0]);
						printf("ergebnis: %d\n", ergebnis);
						//remove a and b from list
						myanchor->first=popList(myanchor->first);
						myanchor->first=popList(myanchor->first);
						//add solution to list
						Anchor* new_anchor3;
						new_anchor3 = pushL(ergebnis,myanchor);
						myanchor->first = new_anchor3->first;
					}
				}
            }else{
				printf("an operator is not allowed with only one item in list!\n");
			}
        }else{
			x = convertToInt(c);
			Anchor* new_anchor;
			new_anchor = pushL(x,myanchor);
			myanchor->first = new_anchor->first;
        }
        printL(myanchor->first);
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
