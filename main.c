#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define FORMAT "YYMMDD-XXXX"
#define NUMBER_LENGTH 10
#define charToInt(c) (c-'0') //ändrar char siffror till int siffror genom att substrahera -48, då siffror börjar med värde 48 i ASCII tabell

int controlDigit (int digits[]);

int main()
{
    char format[] = FORMAT;
    char userInput[sizeof(FORMAT)+1] = {0};
    int personNumber[NUMBER_LENGTH] = {0};

    printf("Enter your personnumber in format %s:\n", FORMAT);
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strlen(userInput) - 1] = '\0';

    int i,k = 0;
    bool is_formatCorrect = true;

    while (i < sizeof(FORMAT) - 1)
    {
        if (isalpha(format[i]))
        {
            if(!isdigit(userInput[i]))
            {
                is_formatCorrect = false;
                break;
            }
            else
            {                                      
                personNumber[k]=charToInt(userInput[i]);
                k++; 
            }
        }
        else
        {
            if (format[i] != userInput[i])
            {
                is_formatCorrect = false;
                break;
            }
        }
        i++;
    }
    
    printf("The format of input personnumber is%s correct \n", is_formatCorrect ? "" : " not");
    if(is_formatCorrect) //om formatet är korrekt kolla kontrollsiffra
    printf(controlDigit(personNumber) == personNumber[NUMBER_LENGTH-1] ? "Yes it's valid personnumber!" : "Sorry, but personnumber is invalid" );

    return 0;
}

int controlDigit(int digits[]){
    int sum = 0;
    int temp = 0;
    for (int i = 0; i<NUMBER_LENGTH-1; i++) //hela personnummer är 10 siffror, men vi ska inte ta sista siffra i beräkningen
    {                                       //kanske bättre ideen att använda size_t n = sizeof(digits) / sizeof(digits[0]); och ange personNumber-1 som parameter istället
        temp = digits[i];               
        
        if(i%2==0) 
        {   
            temp*=2;
            if(temp>9)
            {
                temp-=9; // 10: 1+0=1 är samma som 10-9=1 ..... 14: 1+4=5;14-9=5 ..... 18:  1+8=9;18-9=9
            }
        } 
        sum+=temp;
    }
    return (10-sum%10)%10;
}




