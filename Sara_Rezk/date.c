#include <stdio.h>

int main() {
    int day, month, year, age;
    
    printf("Enter a date (day.month.year): ");
    scanf("%d.%d.%d", &day, &month, &year);
    
    printf("%d ", day);
    
    if (month == 1) {
        printf("January");
    }
    else if (month == 2) {
        printf("February");
    }
    else if (month == 3) {
        printf("March");
    }
    else if (month == 4) {
        printf("April");
    }
    else if (month == 5) {
        printf("May");
    }
    else if (month == 6) {
        printf("June");
    }
    else if (month == 7) {
        printf("July");
    }
    else if (month == 8) {
        printf("August");
    }
    else if (month == 9) {
        printf("September");
    }
    else if (month == 10) {
        printf("October");
    }
    else if (month == 11) {
        printf("November");
    }
    else {
        printf("December");
    }
    
    printf(" %d,", year);
    age=2026-year;
    printf(" %d years old.", age);
    
    return 0;
}