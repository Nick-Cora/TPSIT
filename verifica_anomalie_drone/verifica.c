#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define LUNG_RIGA 200       //lunghezza righe di un file
#define N_RIGHE         //numero di righe del file
#define LUNG 30     //lunghezza parola

typedef struct anomalia{
    int tempo;
    int tempoAnom;
    char tipo[LUNG];
    float lat;
    float lon;
}Anomalia;



int contaRighe(FILE *fp){           //conto le righe del file
    int cnt = 0;
    char car;

    while(fscanf(fp, "%c", &car) != EOF){       //quanco il carattere è \n ovvero quando finisce la riga incremento il contatore della riga
            if(car == "/n"){
                cnt++;
            }
    return cnt;
    }
}


void leggiFileVolo(Anomalia* anomalie, FILE* fp){           //carico nella struttura i dati presenti nel file del volo
    char* riga = (char*) malloc(LUNG_RIGA*sizeof(char));
    int cnt = 0;
    while(fgets(riga, LUNG_RIGA, fp)){
            (anomalie + cnt)->tempo = atoi(strtok(NULL,","));
            (anomalie + cnt)->lat = atof(strtok(NULL, ","));
            (anomalie + cnt)->lon = atof(strtok(NULL, ","));
            cnt++;
    }
    return;
}

void leggiFileAnomalie(Anomalia* anomalie, FILE* fp){           //carico nella struttura i dati presenti el file delle anomalie
    char* riga = (char*) malloc(LUNG_RIGA*sizeof(char));
    int cnt = 0;
    while(fgets(riga, LUNG_RIGA, fp)){
            (anomalie + cnt)->tempoAnom = atoi(strtok(NULL,","));
            strcpy((anomalie + cnt)->tipo, strtok(NULL, ","));
            cnt++;
    }
    return;
}


void controllaAnomalie(Anomalia* anomalie, int cntVolo, int cntAnom){

    for(int i = 1; i < cntVolo; i++){       //uso 2 for per confrontare un tempo delle anomalie con tutti i tempi dei tempi dei voli
        for(int k = 1; k < cntAnom; k++){
            if((anomalie+i)->tempo == (anomalie+k)->tempoAnom){
                printf("\n%d %f %f %s", (anomalie+i)->tempo, (anomalie+i)->lat, (anomalie+i)->lon, (anomalie+i)->tipo);
            }
        }
    }
}


void main(){
    FILE *fpAn;
    FILE *fpVo;
    Anomalia *anomalie;
    if(fpAn = fopen("Anomalie_drone.csv", "r") ==NULL){
        printf("Il file non esiste");
    }else{
        if(fpVo = fopen("Volo_drone.csv", "r") ==NULL){
                printf("Il file non esiste");
        }else{
            int righeVolo = contaRighe(fpVo);
            int righeAnom = contaRighe(fpAn);
            printf("%d %d", fpVo, fpAn);
            anomalie = (Anomalia*) malloc(sizeof(Anomalia)*righeVolo);
            leggiFileVolo(anomalie, fpVo);
            leggiFileAnomalie(anomalie, fpAn);
            fclose(fpAn);
            fclose(fpVo);
            controllaAnomalie(anomalie, righeVolo, righeAnom);
        }
    }
}
