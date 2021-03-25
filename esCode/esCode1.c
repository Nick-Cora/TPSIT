/*
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
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

void main(){
    char scelta;

    struct node* head = NULL;
    struct node* tail = NULL;
    struct node* element = NULL;

    do{
        element = (struct node*) malloc (sizeof(struct node));
        printf("Inserire un numero: ");
        fflush(stdin);
        scanf("%d", &element->valore);
        enqueue(&head, &tail, element);

        printf("Vuoi inserire ancora dei numeri? S/s (si) N,n (no)");
        fflush(stdin);
        scanf("%c", &scelta);
    }while(scelta == 'S' || scelta == 's');

    while(!isEmpty(head)){
        element = dequeue(&head, &tail);
        printf("%d ", element->valore);
        free(element);
    }

}