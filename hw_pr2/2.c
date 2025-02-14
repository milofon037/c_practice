#include <stdio.h>

struct Item {
    char name[50];
    int count;
    float price;
};

void main(){
    int n, i;
    scanf("%d", &n);
    struct Item* items = malloc(sizeof(struct Item) * n);

    for (i = 0; i < n; i++){
        struct Item it;
        scanf("%s %d %f", &it.name, &it.count, &it.price); // тут можно напрямую в элемент массива вводить, без посредников
        items[i] = it;
    }

    for (i = 0; i < n; i++){
        printf("Item: %s\nQuantity: %d\nPrice: %.2f\n\n", items[i].name, items[i].count, items[i].price);
    }
    free(items);
}
