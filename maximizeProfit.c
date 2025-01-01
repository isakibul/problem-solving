#include<stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int minIndex = prices[0];
    int maxPrice = 0;

    for(int i=0; i<pricesSize; i++){
        if(minIndex<prices[i]){
            minIndex = i;
        }
    }

    printf("%d", minIndex);

    for(int i=minIndex; i<pricesSize; i++){
        if(prices[i]>maxPrice){
            maxPrice = i;
        }
    }

    return maxPrice;
}

int main(){
    int price[] = {7,1,5,3,6,4};
    int size = sizeof(price)/sizeof(price[0]);
    int result = maxProfit(price, size);
    printf("%d", result);
}