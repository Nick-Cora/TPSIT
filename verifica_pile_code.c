#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct carta{       //struct della carta
    int valore;
    char seme;
    struct carta *next;
};

void push(struct carta **head, struct carta *element){        //la push inserisce gli elementi dalla pila
    if(isEmpty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct carta * pop(struct carta **head){        //la pop rimuove gli elementi dalla pila(l'ultimo inserito perchè le pile sono LIFO Last In First Out)
    struct carta *sup = *head;
    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = sup->next;
    }
    return sup;
}

int isEmpty(struct carta* pun){         //la pila è vuota?
    return pun == NULL;
}

void main(){
    struct carta *mazzo = NULL;
    struct carta *support = NULL;
    struct carta *element = NULL;
    struct carta *alice = NULL;
    struct carta *bob = NULL;
    int num = 1;
    

    while (num <= 13){      //4 while per caricare nella pila 13 carte per seme
        support = (struct carta*) malloc(sizeof(struct carta));
        support->valore = num;
        support->seme = 'C';
        push(&mazzo, support);
        num++;
    }

    num = 1;
    while (num <= 13){
        support = (struct carta*) malloc(sizeof(struct carta));
        support->valore = num;
        support->seme = 'P';
        push(&mazzo, support);
        num++;
    }

    num = 1;
    while (num <= 13){
        support = (struct carta*) malloc(sizeof(struct carta));
        support->valore = num;
        support->seme = 'D';
        push(&mazzo, support);
        num++;
    }

    num = 1;
    while (num <= 13){
        support = (struct carta*) malloc(sizeof(struct carta));
        support->valore = num;
        support->seme = 'F';
        push(&mazzo, support);
        num++;
    }

    
    while(!isEmpty(mazzo)){     //se il mazzo non è vuoto cicla e da prima una carta ad Alice e la stampo e una a bob ma non la stampo
        element = pop(&mazzo);
        push(&alice, element);
        printf("%d ", element->valore);
        free(element);
        element = pop(&mazzo);
        push(&bob, element);
        free(element);
    }


}
