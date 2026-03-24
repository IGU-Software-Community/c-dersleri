#include <stdio.h>

int main() {
    int x = 10;

    int *p = &x;  // p -> x'in adresini tutar

    printf("x: %d\n", x);     // normal değer
    printf("*p: %d\n", *p);   // *p -> p'nin gösterdiği adresteki değeri getirir

    return 0;
}
