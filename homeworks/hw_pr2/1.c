#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float GPA;
};

void main(){
    int n, i;
    scanf("%d", &n);
    struct Student* arr = malloc(sizeof(struct Student) * n);

    for (i = 0; i < n; i++){
        scanf("%s %d %f", &arr[i].name, &arr[i].age, &arr[i].GPA);
    }

    for (i = 0; i < n; i++){
        printf("Name: %s\nAge: %d\nGPA: %.1f\n\n", arr[i].name, arr[i].age, arr[i].GPA);
    }
}
