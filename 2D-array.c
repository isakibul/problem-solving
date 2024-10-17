#include<stdio.h>

int city = 2;
int week = 7;

int main(){
    int temperature[city][week];

    for(int i=0; i<city; i++){
        for(int j=0; j<week; j++){
            printf("City %d & and Day %d: ",i+1, j+1);
            scanf("%d", &temperature[i][j]);
        }
    }

    printf("\n\n");

    for(int i=0; i<city; i++){
        for(int j=0; j<week; j++){
            printf("City %d & and Day %d: %d\n",i+1, j+1, temperature[i][j]);
        }
    }    
}