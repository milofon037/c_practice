#include <stdio.h>

struct Course {
    char name[50];
    int credits;
    char teacher[50];
};

void main(){
    int n, i;
    scanf("%d", &n);
    struct Course* courses = malloc(sizeof(struct Course) * n);

    for (i = 0; i < n; i++){
        scanf("%s %d %s", &courses[i].name, &courses[i].credits, &courses[i].teacher);
    }

    for (i = 0; i < n; i++){
        printf("Course: %s\nCredits: %d\nProfessor: %s\n\n", courses[i].name, courses[i].credits, courses[i].teacher);
    }
}
