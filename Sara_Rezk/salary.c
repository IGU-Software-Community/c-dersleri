#include <stdio.h>
int main (){
    float egy_salery;
    float working_hours;
    int final;
    
    printf("Enter your salary: ");
    scanf("%f", &egy_salery);
    
     printf("Enter your working hours per day: ");
    scanf("%f", &working_hours);
    
    final=egy_salery/working_hours;
    
    printf("your salary per hour is: %d", final);
    return 0;

}