#include <stdio.h>

int main() {
    int *p = NULL;  // hiçbir adresi göstermiyor

    printf("p: %p\n", p);  // genelde (nil) veya 0x0 yazar

    // *p = 10;  
    // BU SATIR AÇILIRSA:
    // NULL adresine erişmeye çalışır → program çöker (segmentation fault)

    return 0;
}
