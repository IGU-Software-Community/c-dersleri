#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function = A reusable section of code that can be invoked "called"
//            arguments can be sent to a function so that it can use them

/* void happyBirthday()
{
     printf("\nHappy birthday to you!");
    printf("\nHappy birthday to you!");
    printf("\nHappy birthday dear [name]!");
    printf("\nHappy birthday to you!");
    printf("\nYou are [age] years old!\n");
}

int main()
{
   happyBirthday();
   happyBirthday();
   happyBirthday();
    
    return 0;
} */

void happyBirthday(char name[], int age)
{
     printf("\nHappy birthday to you!");
    printf("\nHappy birthday to you!");
    printf("\nHappy birthday dear %s!", name);
    printf("\nHappy birthday to you!");
    printf("\nYou are %d years old!\n", age);
}

int main()
{
   char name[50] = "";
   int age = 0;

   printf("Enter your name: ");
   fgets(name, sizeof(name), stdin);
   name[strlen(name) - 1] = '\0';

   printf("Enter your age: ");
   scanf("%d", &age);

   happyBirthday(name, age);
    
    return 0;
}



