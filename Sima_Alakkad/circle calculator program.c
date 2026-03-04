#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

int main()
{
    int option;
    double radius;

    printf("***** Welcome to the circle calculator program! *****\n");
    printf("Please choose what to calculate (1 for area, 2 for circumference): ");
    scanf("%d", &option);
    if(option == 1)
    {
        printf("You chose to calculate the area!\n");
    }
    else if(option == 2)
    {
        printf("You chose to calculate the circumference!\n");
    }
    else
    {
        printf("Please choose 1 or 2!\n");
        return 0;
    }

    switch(option)
    {
    case 1:
    
        double area;

        printf("Please enter a radius value: ");
        scanf("%lf", &radius);

        area = PI*radius*radius;

        printf("The area of the circle is: %.2lf\n", area);
        break;

    case 2:
        
        double circumference;

        printf("Please enter a radius value: ");
        scanf("%lf", &radius);

        circumference = 2*PI*radius;

        printf("The circumference of the circle is: %.2lf\n", circumference);
        break;
    }

    printf("Thanks for using this calculator!");

    return 0;
}
    