#include <stdio.h>

enum Type_en{Gasoline, Diesel, Electric};

struct Vehicle {
    char mark[50];
    char model[50];
    int year;
    enum Type_en type;
};

void main(){
    int n, i;
    scanf("%d", &n);
    struct Vehicle* cars = malloc(sizeof(struct Vehicle) * n);

    for (i = 0; i < n; i++){
        scanf("%s %s %d %d", &cars[i].mark, &cars[i].model, &cars[i].year, &cars[i].type);
    }

    for (i = 0; i < n; i++){
        char eng[8];
        if (cars[i].type == 0){
            char eng[8] = "Gasoline";
        }else if (cars[i].type == 1){
            char eng[8] = "Diesel";
        }else{
            char eng[8] = "Electric";
        }
        printf("Vehicle: %s %s\nYear: %d\nEngine Type: %s\n\n", cars[i].mark, cars[i].model, cars[i].year, eng);
    }
}
