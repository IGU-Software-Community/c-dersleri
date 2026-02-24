#include <stdio.h>
int main (){
    int amount1, amountof_apple, amount2,amountof_orange,final;
    printf("Enter how much apple do you want:");
    scanf("%d",&amount1);
    
     printf("Enter how much orange do you want:");
    scanf("%d",&amount2);
    
    amountof_apple=3*amount1;
    amountof_orange=5*amount2;
    
    final= amountof_apple+amountof_orange;
    
    printf("your total amount is:%d + %d = %d", amountof_apple,amountof_orange, final);
return 0;
}