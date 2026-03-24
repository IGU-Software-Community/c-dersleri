
#include <stdio.h>

int main() {
    int x = 10;

    int *p;   // p: int türünde bir değişkenin adresini tutacak pointer
    p = &x;   // p artık x'in adresini tutuyor

    printf("p: %p\n", p);  // p'nin değeri aslında bir adres

    return 0;
}
