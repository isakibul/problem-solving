#include<stdio.h>

int main(){
    int test[2][3][2];

    int i, j, k;
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            for(k=0; k<2; k++){
                printf("test[%d][%d][%d]: ", i+1, j+1, k+1);
                scanf("%d", &test[i][j][k]);
            }
        }
    }

    printf("\n\n");

    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            for(k=0; k<2; k++){
                printf("test[%d][%d][%d]: %d\n", i, j, k, test[i][j][k]);
            }
        }
    }

    return 0;
}