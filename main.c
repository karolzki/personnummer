#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int controlDigit (int digits[]);

int main(){

int personNumber[9] = {8,1,1,2,1,8,9,8,7}; //6
printf("\nthis is checksum %d", controlDigit(personNumber));
return 0;
}



int controlDigit(int digits[]){
    int sum = 0;
    for (int i = 0; i<=sizeof(digits); i++){   
        int temp = digits[i];
        if(i%2==0) {   
            temp*=2;
            if(temp>9){
                temp-=9;
            }
        } 
        sum+=temp;
    }
    return 10-sum%10;
}




