#include <stdio.h>
#include <stdbool.h>

int main() {
    int a = 10;
    char b[50];

    scanf("%d\n", &a); //принимаем целое число
    printf("%d\n", a); //выводим целое число

    fgets(b, sizeof(b), stdin); //принимаем на ввод строку
    scanf("%s", &b); //то же самое
    printf("%s", b); // выводим строку
}
