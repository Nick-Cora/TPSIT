/*
Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
}Nodo;

int is_empty(Nodo* head){
    
    if (head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Nodo **head, Nodo *element){

    if (is_empty(*head)){           //if (is_empty(*head) == NULL)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Nodo* pop(Nodo **head){

    Nodo* ret = *head;
    if (is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    return ret;
}

void main(){
    struct nodo *val, *next;
    String valore;

    printf("Inserire dei numeri");
    scanf("&d", valore);
    while(valore != NULL){
        push(valore % 10, valore->next);
    }
    
}