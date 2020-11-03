#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 100
#define NUM_CANZ 10

typedef struct canzone{
    int num;
    char titolo[LUNG];
    char autore[LUNG];
}Canzone;


void leggiFile(Canzone elenco[], int* c){
    FILE *fp;
    char riga[LUNG];
    if((fp=fopen("musica.csv", "r"))==NULL){        //apro il file in read
            printf("\n\nIl file non esiste\n\n");
    }else{
        while(fgets(riga, LUNG, fp)!=NULL){     //carico nel vettore di strutture le varie parti del file
            elenco[*c].num=atoi(strtok(riga, ",\n"));
            strcpy(elenco[*c].titolo, strtok(NULL,",\n"));
            strcpy(elenco[*c].autore, strtok(NULL,",\n"));
            *c=*c+1;

        }

        for(int k = 0; k < NUM_CANZ; k++){          //stampo il vettore
            printf("%d %s %s\n", elenco[k].num, elenco[k].titolo, elenco[k].autore);
        }

        fclose(fp);
    }
}

        //non stampa le canzoni randomicamente
void random(Canzone elenco[], int dim){    //genera canzoni in modo random
    int vet[dim];
    int n;
    srand(time(NULL));

    for(int k = 0; k < dim; k++){
        vet[k] = k; //assegna a vet[0] = 0, vet[1] = 1 ecc...
    }
    for(int j = 0; j < dim; j++){
        do{
            n = rand() % dim + 1;
        }while(n = vet[j]);        //controllo che il numero uscito non sia nel vettore
        vet[j] = n;
        if(n == elenco[j].num){
            printf("%d %s, %s", j, elenco[j].titolo, elenco[j].autore);   //stampo numero, nome e autore della canzone
        }
    }
    return;
}




void main(){
    Canzone playlist[NUM_CANZ];
    int k = 0;
    leggiFile(playlist, &k);
    //random(playlist,k);
}

