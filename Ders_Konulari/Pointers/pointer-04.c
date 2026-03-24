#include <stdio.h>

int main() {
    int x = 10;

    int *p = &x;  // p -> x'i gösteriyor

    *p = 20;  // x'in bulunduğu RAM adresindeki değeri değiştir

    printf("x yeni deger: %d\n", x);  // x artık 20

    return 0;
}
