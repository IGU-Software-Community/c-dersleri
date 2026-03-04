#include <stdio.h>

int main (){
    int x;
    float price_per_one=12.0;
    float total_price;
    float final_price;
    float discount=0.0;
    
    printf("Enter the quantity you want to buy:");
    scanf("%d", &x);
     total_price= x*price_per_one;
     
     if(x>122){
         discount= 0.22;
     }
     else{
         if (x>52){
            discount= 0.12; 
         }
         else{
             discount= 0.0;
         }
     }
     final_price = total_price - (total_price*discount);
     printf("Quantity: %d units\n", x);
    printf("Total before discount: %.2f \n", total_price);
    printf("Discount applied: %.0f%%\n", discount * 100);
    printf("Final total after discount: %.2f \n", final_price);
    

    return 0;
}
    
    
    

    
    
    
    
    
    
    