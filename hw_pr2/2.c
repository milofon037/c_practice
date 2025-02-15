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
        scanf("%s %d %f", &items[i].name, &items[i].count, &items[i].price);
    }

    for (i = 0; i < n; i++){
        printf("Item: %s\nQuantity: %d\nPrice: %.2f\n\n", items[i].name, items[i].count, items[i].price);
    }
    free(items);
}
