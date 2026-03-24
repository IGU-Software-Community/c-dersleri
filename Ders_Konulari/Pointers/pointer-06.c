#include <stdio.h>

int main() {
    int x = 10;
    int y = 50;

    int *p = &x;  // p önce x'i gösteriyor

    printf("ilk: %d\n", *p);  // 10

    p = &y;  // artık p x'i değil y'yi gösteriyor

    printf("sonra: %d\n", *p);  // 50

    return 0;
}
