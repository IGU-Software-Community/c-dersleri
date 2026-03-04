#include <stdio.h>

int main (){
    int x,y,z;
     printf("Enter 3 diffrent numbers: ");
     scanf("%d%d%d",&x,&y,&z);
     
     if(x>y){
         if(x>z){
             printf("%d is the biggest number.", x);
         }
         else{
            printf("%d is the biggest number.", z);
         }
     }
     else{
         if(y>z){
             printf("%d is the biggest number.", y);
         }
         else{
            printf("%d is the biggest number.", z);
         }
     }

    return 0;
}
    
    
    

    
    
    
    
    
    
    