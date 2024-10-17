#include<stdio.h>

int main(){
    int a[2][2], b[2][2], result[2][2];

    int i, j;
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("Enter the value of a%d%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("Enter the value of b%d%d: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            result[i][j] = a[i][j]+b[i][j];
        }
    }

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%d ", result[i][j]);
        }
            printf("\n");
    }

    return 0;
}