#include <stdio.h>
#include <stdlib.h>

//Months in English and German

int main()
{
    int language;
    printf("Choose a language (1 for english, 2 for german): \n");
    scanf("%d", &language);
    if(language == 1)
    {
        printf("You chose English!\n");
    }
    else if(language == 2)
    {
        printf("You chose German!\n");
    }
    else
    {
        printf("Please choose 1 or 2!");
    }

    if(language == 1)
    {
        int months;
    printf("Enter a number from 1 to 12: ");
    scanf("%d", &months);

    switch(months)
    {

    case 1:
        printf("It is January");
        break;

    case 2:
        printf("It is February");
        break;

    case 3:
        printf("It is March");
        break;

    case 4:
        printf("It is April");
        break;

    case 5:
        printf("It is May");
        break;

    case 6:
        printf("It is June");
        break;

    case 7:
        printf("It is July");
        break;

    case 8:
        printf("It is August");
        break;

    case 9:
        printf("It is September");
        break;

    case 10:
        printf("It is October");
        break;

    case 11:
        printf("It is November");
        break;

    case 12:
        printf("It is December");
        break;

        default: 
        printf("Please enter a number from 1 to 12!");
     }
    
    }
    else if(language == 2)
    {
        int monaten;
    printf("Geben Sie eine Zahl ein 1 bis 12: ");
    scanf("%d", &monaten);

        switch(monaten)
     {
        
    case 1:
        printf("Es ist Januar");
        break;

    case 2:
        printf("Es ist Februar");
        break;

    case 3:
        printf("Es ist März");
        break;

    case 4:
        printf("Es ist April");
        break;

    case 5:
        printf("Es ist Mai");
        break;

    case 6:
        printf("Es ist Juni");
        break;

    case 7:
        printf("Es ist Juli");
        break;

    case 8:
        printf("Es ist August");
        break;

    case 9:
        printf("Es ist September");
        break;

    case 10:
        printf("Es ist Oktober");
        break;

    case 11:
        printf("Es ist November");
        break;

    case 12:
        printf("Es ist Dezember");
        break;

        default: 
        printf("Bitte geben Sie eine Zahl von 1 bis 12 ein!");
    }
    }
    
    return 0;
    
}