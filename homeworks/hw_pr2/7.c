#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float GPA;
};

void main(){
    int n, i;
    struct Student* arr = malloc(sizeof(struct Student) * n);

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%s %d %f", &arr[i].name, &arr[i].age, &arr[i].GPA);
    }

    for (i = 0; i < n; i++){
        struct Student* st = &arr[i];
        printf("Name: %s\nAge: %d\nGPA: %.1f\n\n", st->name, st->age, st->GPA);
    }
}
