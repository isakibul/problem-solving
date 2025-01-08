#include<stdio.h>
#include<string.h>

int romanToInt(char* s) {
    int romanToValue(int roman){
        switch(roman){
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
            default:
                return 0;
        };
    };

    int result = 0;
    int len = strlen(s);

    for(int i=0; i<len; i++){
        int currentValue = romanToValue(s[i]);
        int nextValue = romanToValue(s[i+1]);

        if(currentValue<nextValue){
            result -= currentValue;
        }else{
            result +=currentValue;
        }
    }
    return result;
}

int main(){
    char* s = "MCMXCIV";
    int result = romanToInt(s);
    printf("%d", result);

    return 0;
}