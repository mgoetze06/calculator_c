#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isOperator(char c){
    if((c == '+')||(c == '*')||(c == '-')||(c == '/')){ 
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

int convertToInt(char c[3]){
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
    //printf("temp1\n");
    list = NULL;
    myanchor->first = list;
    //printf("length: %d\n",lengthList(myanchor->first));
    //printf("push 1\n");
    //anchor = pushL(1,anchor);
    //printf("print list with new 1\n");
    //printf("length: %d\n",lengthList(anchor->first));
    //printL(anchor->first);   
    //printf("push 2\n");
    //anchor = pushL(2,anchor);
    //printf("print list with new 2\n");
    //printL(anchor->first);   

    int x;
    char c[3];
    //printf("Enter a value :");
    //scanf("%s", c);
    //x = c[0] - '0';
    //myanchor = pushL(x,myanchor);
    //printf("length: %d\n",lengthList(anchor->first));
    //printL(myanchor->first);  
	//Anchor* new_anchor2;
    //new_anchor2->first = popList(myanchor->first);
	//myanchor->first = new_anchor2->first;
	//printL(myanchor->first);  
	
    while (lengthList(myanchor->first) < 5){
        printf("Enter a value :");
        scanf("%s", c);
        
        int ergebnis;
        bool temp;
		//Anchor* new_anchor;
        //new_anchor = pushL(x,anchor);
		
		//printL(anchor->first);
        temp = isOperator(c[0]);
        
        int len = lengthList(myanchor->first);
		
        //printf("Length: %d\n", len);
        if (isOperator(c[0])){
			if (len>1){
				printf("%s is an operator\n", c);
				//#############a
				int a = myanchor->first->item;
				//Anchor* new_anchor1;
				//new_anchor1->first = popList(myanchor->first);
				//myanchor->first = new_anchor1->first;
				//printf("removed first operator-number\n", c);
				//printL(myanchor->first);
				//#############b
				int b = myanchor->first->next->item;
				//Anchor* new_anchor2;
				//new_anchor2->first = popList(myanchor->first);
				//myanchor->first = new_anchor2->first;
				//printf("removed second operator-number\n", c);
				//printL(myanchor->first);
				//#############ergebnis
				ergebnis = berechne(a,b,c[0]);
				printf("ergebnis: %d\n", ergebnis);
				myanchor->first=popList(myanchor->first);
				myanchor->first=popList(myanchor->first);
				Anchor* new_anchor3;
				new_anchor3 = pushL(ergebnis,myanchor);
				myanchor->first = new_anchor3->first;
				//push(ergebnis,f);
				
				//printf("%d",temp);
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