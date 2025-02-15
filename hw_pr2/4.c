#include <stdio.h>


struct Employee {
    char name[50];
    char job[50];
    float salary;
};

void main(){
    int n, i;
    scanf("%d", &n);
    struct Employee* emps = malloc(sizeof(struct Employee) * n);

    for (i = 0; i < n; i++){
        scanf("%s %s %f", &emps[i].name, &emps[i].job, &emps[i].salary);
    }

    for (i = 0; i < n; i++){
        printf("Name: %s\nPosition: %s\nSalary: %.2f\n\n", emps[i].name, emps[i].job, emps[i].salary);
    }
}
