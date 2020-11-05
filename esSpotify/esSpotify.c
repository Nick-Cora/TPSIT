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
    int val;
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
        /*
        for(int k = 0; k < NUM_CANZ; k++){          //stampo il vettore
            printf("%d %s %s\n", elenco[k].num, elenco[k].titolo, elenco[k].autore);
        }*/

        fclose(fp);
    }
}


void random(Canzone playlist[],int cnt){
    srand(time(NULL));
    for(int i=0;i< cnt;i++)
        playlist[i].val=rand()%10000000;
    int max=0;
    for(int i=0;i<cnt;i++){
        max=i;
        for(int j=0;j<cnt;j++){
            if(playlist[max].val<playlist[j].val){
                max=j;
            }
        }
        printf("%d %s %s\n", i+1, playlist[max].titolo, playlist[max].autore);
        playlist[max].val=-NUM_CANZ+i;
    }
    return;
}



void main(){
    Canzone playlist[NUM_CANZ];
    int k = 0;
    leggiFile(playlist, &k);
    random(playlist,k);
}

