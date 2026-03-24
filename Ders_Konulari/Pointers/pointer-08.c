#include <stdio.h>

int main() {
    // 1. ARRAY TANIMI
    int arr[3] = {10, 20, 30};

    // 2. ARRAY = İLK ELEMANIN ADRESİ
    printf("arr (adres): %p\n", arr);        // arr == &arr[0]
    printf("&arr[0]: %p\n\n", &arr[0]);

    // 3. NORMAL ERİŞİM
    printf("arr[0]: %d\n", arr[0]);
    printf("arr[1]: %d\n\n", arr[1]);

    // 4. POINTER GİBİ ERİŞİM
    printf("*(arr): %d\n", *arr);           // arr[0]
    printf("*(arr + 1): %d\n\n", *(arr + 1)); // arr[1]

    // 5. POINTER TANIMLAYIP ARRAY'E BAĞLAMA
    int *p = arr;  // arr zaten adres olduğu için direkt atanır

    printf("*p: %d\n", *p);        // arr[0]
    printf("*(p + 1): %d\n", *(p + 1)); // arr[1]

    return 0;
}
