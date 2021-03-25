#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

int main(){
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; //inizializzo la lista a NULL

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0){
            if (lista == NULL){ //controllo che la lista sia vuota

                //alloco la lista e copio il valore in l
                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;
            }else{
                // se la lista non è vuota alloco next per un nuovo valore e punto alla cella successiva
                l->next = (struct El *)malloc(sizeof(struct El));
                l = l->next;
            }

            l->valore = n;  //assegno a l il valore inserito in input
            l->next = NULL; //assegno il next di l a NULL
        }
    } while (n >= 0);

    l = lista; //copio la lista dentro l
    printf("numeri inseriti:\n");
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; //vado all'elemento successivo
    }
    printf("\n");
    return 0;
}
