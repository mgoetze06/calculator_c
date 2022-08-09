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


void rechner_list(){

    printf("list_test\n");
    Anchor* anchor;
    List* list;
    //printf("temp1\n");
    list = NULL;
    anchor->first = list;
    printf("length: %d\n",lengthList(anchor->first));
    //printf("push 1\n");
    //anchor = pushL(1,anchor);
    //printf("print list with new 1\n");
    //printf("length: %d\n",lengthList(anchor->first));
    //printL(anchor->first);   
    //printf("push 2\n");
    //anchor = pushL(2,anchor);
    //printf("print list with new 2\n");
    //printL(anchor->first);   
    //printf("rechner_list\n");
    //printf("\n\n---   Taschenrechner   ---\n");
    int x;
    char c[3];
    printf("Enter a value :");
    scanf("%s", c);
    x = c[0] - '0';
    anchor = pushL(x,anchor);
    printf("length: %d\n",lengthList(anchor->first));
    printL(anchor->first);  
    while (lengthList(anchor->first) < 3){
        printf("Enter a value :");
        scanf("%s", c);
        x = c[0] - '0';
        printL(anchor->first);
        int ergebnis;
        bool temp;
        //anchor = pushL(x,anchor);
        temp = isOperator(c[0]);
        
        int len = lengthList(anchor->first);
        
        if (isOperator(c[0])&&len>1){
            
            printf("%s is an operator\n", c);
            int a = anchor->first->item;
            anchor->first = popList(anchor->first);
            int b = anchor->first->item;
            anchor->first = popList(anchor->first);
            ergebnis = berechne(a,b,c[0]);
            printf("ergebnis: %d\n", ergebnis);
            //anchor = pushL(ergebnis,anchor);
            //push(ergebnis,f);
            
            //printf("%d",temp);
            
        }else{
            Anchor* new_anchor;
            x = c[0] - '0';  //create a int from single char if it is not an operator
            new_anchor = pushL(x,anchor);
            //anchor = new_anchor;
        }
        printL(anchor->first);
    }
}





void list_test(){
    printf("list_test\n");
    Anchor* anchor;
    List* list;
    //printf("temp1\n");
    list = NULL;
    anchor->first = list;
    printf("length: %d\n",lengthList(anchor->first));
    //printf("push 1\n");
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
