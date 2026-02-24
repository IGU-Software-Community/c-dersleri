#include <stdio.h>
const float PI= 3.14;
int main (){
    float lenght, width, area_house, r ,area_garden, final_area,final_time;
    printf("Enter your house's lenght:");
    scanf("%f", &lenght);
    
    printf("Enter your house's width:");
    scanf("%f", &width);
    
    printf("Enter your garden's radius:");
    scanf("%f", &r);
    
    area_house= lenght*width;
    area_garden= r*r*PI;
    final_area= area_garden-area_house;
    final_time= final_area*2.0;
    
    printf("The time of trimming is: %.2f", final_time);
    return 0;
}
    
    
    

    
    
    
    
    
    
    