#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float GPA;
};

void main(){
    struct Student arr[50];
    int n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        struct Student st;
        scanf("%s", &st.name);
        scanf("%d", &st.age);
        scanf("%f", &st.GPA);
        arr[i] = st;
    }

    for (i = 0; i < n; i++){
        printf("Name: %s\nAge: %d\nGPA: %.1f\n\n", arr[i].name, arr[i].age, arr[i].GPA);
    }
}
