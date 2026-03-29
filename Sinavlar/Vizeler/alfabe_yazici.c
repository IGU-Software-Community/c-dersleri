/* * Kaynak: Pointers2.pdf - Sayfa 15
 * Konu: ASCII Değerleri ve ptr++ ile Bellekte İlerleme
 */
#include <stdio.h>

int main() {
    char alfabe[27];
    char *ptr = alfabe;
    int i;

    // Döngü ile her harfi sırayla belleğe yazma
    for (i = 0; i < 26; i++) {
        *ptr = 'A' + i; // ASCII 65 ('A') üzerine ekleyerek harf oluşturur
        ptr++;          // Bir sonraki harf hücresine (kutucuğa) geç
    }
    *ptr = '\0'; // Dizinin bittiğini belirten "dur" tabelası

    // Yazdırma için ptr'yi tekrar en başa alıyoruz
    ptr = alfabe;
    printf("Alfabe: ");
    while (*ptr != '\0') {
        printf("%c ", *ptr);
        ptr++;
    }

    return 0;
}
