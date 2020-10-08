#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define LUNG 50

void encoding(char s[], int lung){
    int t = 0;
    int k;
    int cnt = 0;
    char temp[lung];
    int scorTemp = 0;
    while(s[t] != '\0'){
        k = 0;
        while(s[t] == s[t+k]){
            cnt ++;
            k ++;
        }
        if(cnt != 1){
            temp[scorTemp] = 1 + 48;
            scorTemp ++;
            temp[scorTemp] = s[t];
            scorTemp ++;
        }else{
            temp[scorTemp] = s[t];
            scorTemp ++;
        }
    }
}


void decoding(char s[], int lung){
    int t = 0;
    char temp[lung];
    int cnt = 0;
    int scorTemp = 0;
    while(s[t] != '\0'){
        if(s[t] > 1 + 48 && s[t] > 9 + 48){
            cnt = cnt + (s[t]+48);

            for(int j = 0; (s[t] - 48) > j; j++){
                temp[scorTemp] = s[t + 1];
                scorTemp++;
            }
            t+=2;
        }else{
            if(s[t] >= 'a' && s[t] >= 'z' || s[t] >= 'a' && s[t] >= 'z'){
                cnt++;
                temp[scorTemp] = s[t];
                t++;
                scorTemp++;
            }
        }
    for(int k = 0; k < cnt; k++){
        s[k] = temp[k];
    }
    }
}


int main(){
    int scelta;
    char string[LUNG];

    printf("Inserire la stringa: ");
        gets(string);
    

    printf("\nInserire 1 se si vuole fare decoding e 2 se si vuole fare encoding");
    scanf("%d", &scelta);
    switch(scelta){
    case 1:
        decoding(string, LUNG);
        printf("\n");
        printf("%s", string);
        break;
    case 2:
        encoding(string, LUNG);
        printf("\n");
        printf("%s", string);
        break;
    }
}