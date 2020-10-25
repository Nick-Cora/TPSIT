#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define LUNG 50

void encoding(char s[]){
    int k = 1;

    printf("Inserire la stringa: ");
    scanf("%s", s);
    for(int cnt=0; cnt<strlen(s);cnt++){
        if(s[cnt]==s[cnt+1]){
            k++;
        }else{
            if(k!=1){
                printf("%d%c", k, s[cnt]);
                k=1;
            }else{
                printf("%c", s[cnt]);
                k = 1;
            }
        }
    }
}


void decoding(char s[]){
    int car=0;
    printf("Inserire la stringa: ");
    scanf("%s", s);
    for(int k=0;k<strlen(s);k++){
        if(s[k] > 49 && s[k] < 58){
            car = s[k]-48;
            for(int x=1; x<car; x++){
                printf("%c",s[k+1]);
            }
        }else{
            printf("%c",s[k]);
        }
    }
}


int main(){
    int scelta;
    char string[LUNG];

    printf("\nInserire 1 se si vuole fare decoding e 2 se si vuole fare encoding");
    scanf("%d", &scelta);
    switch(scelta){
    case 1:
        decoding(string);
        break;
    case 2:
        encoding(string);
        break;
    }
}
