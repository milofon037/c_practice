#include <stdio.h>


struct Employee {
    char name[50];
    char job[50];
    float salary;
};

void main(){
    int n, i;
    scanf("%d", &n);
    struct Employee emps[n];

    for (i = 0; i < n; i++){
        struct Employee emp;
        scanf("%s %s %f", &emp.name, &emp.job, &emp.salary);
        emps[i] = emp;
    }

    for (i = 0; i < n; i++){
        printf("Name: %s\nPosition: %s\nSalary: %.2f\n\n", emps[i].name, emps[i].job, emps[i].salary);
    }
}
