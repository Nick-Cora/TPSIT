/*
Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int valore;
    struct node *next;
};

bool isEmpty(struct node *pun){
    return pun == NULL;
}

void enqueue(struct node **head, struct node **tail, struct node *element){
    if(isEmpty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}


struct node * dequeue(struct node **head, struct node **tail){
    struct node *sup = *head;
    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = sup->next;
    }

    if(*head == NULL){
        *tail == NULL;
    }
    return sup;
}


void push(struct node **head, struct node *element){
    if(isEmpty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct node * pop(struct node **head){
    struct node *sup = *head;
    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = sup->next;
    }
    return sup;
}

void caricaCoda(struct node **head, struct node **tail, struct node *element){

    char scelta;

    do{
        element = (struct node*) malloc (sizeof(struct node));
        printf("Inserire un numero: ");
        fflush(stdin);
        scanf("%d", &element->valore);
        enqueue(head, tail, element);

        printf("Vuoi inserire ancora dei numeri? S/s (si) N,n (no)");
        fflush(stdin);
        scanf("%c", &scelta);
    }while(scelta == 'S' || scelta == 's'); 

}


void main(){
    
    struct node* head = NULL;
    struct node* tail = NULL;
    struct node* element = NULL;
    struct node* pila = NULL;

    caricaCoda(&head, &tail, element);
    while(!isEmpty(head)){
        element = dequeue(&head, &tail);
        push(&pila, element);
    }
    
    while(!isEmpty(pila)){
        element = pop(&pila);
        printf("%d ", element->valore);
        free(element);
    }
    
}